#ifdef REGEN_ENABLE_PARALLEL
#include "sfa.h"
#include <boost/thread.hpp>
#include <boost/bind.hpp>

namespace regen {

SFA::SFA(Expr *expr_root, const std::vector<StateExpr*> &state_exprs, std::size_t thread_num):
    nfa_size_(state_exprs.size()),
    dfa_size_(0),
    thread_num_(thread_num)
{
  typedef std::set<StateExpr*> NFA;
  fa_accepts_.resize(nfa_size_);
  for (NFA::iterator i = expr_root->transition().first.begin(); i != expr_root->transition().first.end(); ++i) {
    start_states_.insert((*i)->state_id());
  }

  SSTransition sst;
  std::map<SSTransition, state_t> sfa_map;
  std::queue<SSTransition> queue;
  SSTransition::iterator iter;
  state_t sfa_id = 0;

  sfa_map[sst] = DFA::REJECT;

  for (std::size_t i = 0; i < nfa_size_; i++) {
    sst[i].insert(i);
  }

  sfa_map[sst] = sfa_id++;
  queue.push(sst);

  while (!queue.empty()) {
    sst = queue.front();
    sst_.push_back(sst);
    queue.pop();
    std::vector<SSTransition> transition(256);

    iter = sst.begin();
    while (iter != sst.end()) {
      state_t start = (*iter).first;
      std::set<state_t> &currents = (*iter).second;
      for (std::set<state_t>::iterator i = currents.begin(); i != currents.end(); ++i) {
        StateExpr *s = state_exprs[*i];
        NFA &next = s->transition().follow;
        switch (s->type()) {
          case Expr::kLiteral: {
            Literal* literal = static_cast<Literal*>(s);
            unsigned char index = (unsigned char)literal->literal();
            for (NFA::iterator ni = next.begin(); ni != next.end(); ++ni) {
              transition[index][start].insert((*ni)->state_id());
            }
            break;
          }
          case Expr::kCharClass: {
            CharClass* charclass = static_cast<CharClass*>(s);
            for (int c = 0; c < 256; c++) {
              if (charclass->Involve(static_cast<unsigned char>(c))) {
                for (NFA::iterator ni = next.begin(); ni != next.end(); ++ni) {
                  transition[c][start].insert((*ni)->state_id());
                }
              }
            }
            break;
          }
          case Expr::kDot: {
            for (int c = 0; c < 256; c++) {
              for (NFA::iterator ni = next.begin(); ni != next.end(); ++ni) {
                transition[c][start].insert((*ni)->state_id());
              }
            }
            break;
          }
          case Expr::kEOP: {
            fa_accepts_[(s)->state_id()] = true;
            break;
          }
          case Expr::kNone: break;
          default: exitmsg("notype");
        }
      }
      ++iter;
    }

    State &state = get_new_state();
    
    for (std::size_t c = 0; c < 256; c++) {
      SSTransition &next = transition[c];
      if (next.empty()) {
        state[c] = REJECT;
        state.dst_states.insert(REJECT);
        continue;
      }
      if (sfa_map.find(next) == sfa_map.end()) {
        sfa_map[next] = sfa_id++;
        queue.push(next);
      }
      state[c] = sfa_map[next];
      state.dst_states.insert(sfa_map[next]);
    }
  }

  complete_ = true;
}

SFA::SFA(const NFA &nfa, std::size_t thread_num):
    nfa_size_(nfa.size()),
    dfa_size_(0),
    thread_num_(thread_num)
{
  fa_accepts_.resize(nfa_size_);
  for (NFA::const_iterator state_iter = nfa.begin(); state_iter != nfa.end(); ++state_iter)
    fa_accepts_[(*state_iter).id] = (*state_iter).accept;

  SSTransition sst;
  std::map<SSTransition, state_t> sfa_map;
  std::queue<SSTransition> queue;
  SSTransition::iterator iter;
  state_t sfa_id = 0;

  sfa_map[sst] = DFA::REJECT;

  for (std::size_t i = 0; i < nfa_size_; i++) {
    sst[i].insert(i);
  }

  sfa_map[sst] = sfa_id++;
  queue.push(sst);

  while (!queue.empty()) {
    sst = queue.front();
    sst_.push_back(sst);
    queue.pop();
    std::vector<SSTransition> transition(256);

    for (iter = sst.begin(); iter != sst.end(); ++iter) {
      state_t start = (*iter).first;
      std::set<state_t> &currents = (*iter).second;
      for (std::set<state_t>::iterator i = currents.begin(); i != currents.end(); ++i) {
        for (std::size_t c = 0; c < 256; c++) {
          if (!nfa[*i][c].empty()) {
            transition[c][start].insert(nfa[*i][c].begin(), nfa[*i][c].end());
          }
        }
      }
    }

    State &state = get_new_state();
    
    for (std::size_t c = 0; c < 256; c++) {
      SSTransition &next = transition[c];
      if (next.empty()) {
        state[c] = REJECT;
        state.dst_states.insert(REJECT);
      }
      if (sfa_map.find(next) == sfa_map.end()) {
        sfa_map[next] = sfa_id++;
        queue.push(next);
      }
      state[c] = sfa_map[next];
      state.dst_states.insert(sfa_map[next]);
    }
  }

  complete_ = true;
}

SFA::SFA(const DFA &dfa, std::size_t thread_num):
    nfa_size_(0),
    dfa_size_(dfa.size()),
    thread_num_(thread_num)
{
  if (!dfa.Complete()) return;
  
  fa_accepts_.resize(dfa.size());
  for (DFA::const_iterator s = dfa.begin(); s != dfa.end(); ++s) {
    fa_accepts_[s->id] = s->accept;
  }

  start_states_.insert(0);
  
  SSDTransition ssdt;
  std::map<SSDTransition, state_t> sfa_map;
  std::queue<SSDTransition> queue;
  SSDTransition::iterator iter;
  state_t sfa_id = 0;

  sfa_map[ssdt] = DFA::REJECT;

  for (std::size_t i = 0; i < dfa_size_; i++) {
    ssdt[i] = i;
  }

  sfa_map[ssdt] = sfa_id++;
  queue.push(ssdt);

  while (!queue.empty()) {
    ssdt = queue.front();
    SSTransition sst;
    for (iter = ssdt.begin(); iter != ssdt.end(); ++iter) {
      sst[(*iter).first].insert((*iter).second);
    }
    sst_.push_back(sst);
    queue.pop();
    std::vector<SSDTransition> transition(256);
    
    iter = ssdt.begin();
    while (iter != ssdt.end()) {
      state_t start = (*iter).first;
      state_t current = (*iter).second;
      const DFA::Transition &trans = dfa.GetTransition(current);
      for (std::size_t c = 0; c < 256; c++) {
        state_t next = trans[c];
        if (next != DFA::REJECT) {
          transition[c][start] = next;
        }
      }
      ++iter;
    }

    State &state = get_new_state();
    
    for (std::size_t c = 0; c < 256; c++) {
      SSDTransition &next = transition[c];
      if (next.empty()) {
        state[c] = REJECT;
        state.dst_states.insert(REJECT);
        continue;
      }

      if (sfa_map.find(next) == sfa_map.end()) {
        sfa_map[next] = sfa_id++;
        queue.push(next);
      }
      state[c] = sfa_map[next];
      state.dst_states.insert(sfa_map[next]);
    }
  }

  complete_ = true;
}

void SFA::MatchTask(TaskArg targ) const
{

  if (olevel_ >= Regen::Options::O1) {
    partial_results_[targ.task_id] = CompiledMatch(targ.string._udata(), NULL, 0);
    return;
  }
  
  state_t state = 0;
  const unsigned char* str = targ.string.ubegin(), * end = targ.string.ubegin();
  
  while (str != end && (state = transition_[state][*str++]) != DFA::REJECT);

  partial_results_[targ.task_id] = state;
  return;
}

bool SFA::Match(const Regen::StringPiece &string, Regen::StringPiece *result) const
{
  if (!complete_) return false;

  std::size_t thread_num = thread_num_;
  if (string.size() <= 2)  {
    thread_num = 1;
  } else if (string.size() < thread_num) {
    thread_num = string.size();
  }
  partial_results_.resize(thread_num);
  boost::thread *threads[thread_num];
  std::size_t task_string_length = string.size() / thread_num;
  std::size_t remainder_length = string.size() % thread_num;
  TaskArg targ;
  const char *str = string.begin();

  for (std::size_t i = 0; i < thread_num; i++) {
    if (i == thread_num - 1) task_string_length += remainder_length;
    targ.string.set(str, task_string_length);
    if (flag_.reverse_match()) {
      targ.task_id = thread_num - i - 1;
    } else {
      targ.task_id = i;
    }
    threads[targ.task_id] = new boost::thread(
        boost::bind(
            boost::bind(&regen::SFA::MatchTask, this, _1),
            targ));
    str += task_string_length;
  }

  std::set<state_t> states, next_states;
  states = start_states_;
  state_t pstate;

  for (std::size_t i = 0; i < thread_num; i++) {
    threads[i]->join();
    if ((pstate = partial_results_[i]) == DFA::REJECT) {
      states.clear();
      break;
    }
    for (std::set<state_t>::iterator i = states.begin(); i != states.end(); ++i) {
      SSTransition::const_iterator iter = sst_[pstate].find(*i);
      if (iter == sst_[pstate].end()) continue;
      next_states.insert((*iter).second.begin(), (*iter).second.end());
    }
    states.swap(next_states);
    if (states.empty()) break;
    next_states.clear();
  }

  bool match = false;
  for (std::set<state_t>::iterator i = states.begin(); i != states.end(); ++i) {
    if (fa_accepts_[*i]) {
      match = true;
      break;
    }
  }

  for (std::size_t i = 0; i < thread_num; i++) {
    threads[i]->join();
    delete threads[i];
  }
  
  return match;
}

} // namespace regen

#endif //REGEN_ENABLE_PARALLEL

#ifndef REGEN_REGEX_H_
#define REGEN_REGEX_H_

#include "regen.h"
#include "util.h"
#include "lexer.h"
#include "expr.h"
#include "exprutil.h"
#include "generator.h"
#include "nfa.h"
#include "dfa.h"
#ifdef REGEN_ENABLE_PARALLEL
#include "sfa.h"
#endif

namespace regen {

class Regex {
public:
  Regex(const Regen::StringPiece& regex, const Regen::Options = Regen::Options::NoParseFlags);
  ~Regex() {}
  void PrintRegex() const;
  static void PrintRegex(const DFA &);
  void PrintParseTree() const;
  void PrintText(Expr::GenOpt, std::size_t n = 1) const;
  static void CreateRegexFromDFA(const DFA &dfa, ExprInfo *info, ExprPool *p);
  void DumpExprTree() const;
  bool Compile(Regen::Options::CompileFlag olevel = Regen::Options::O3);
  bool MinimizeDFA() { if (dfa_.Complete()) { dfa_.Minimize(); return true; } else return false; }
  bool Match(const Regen::StringPiece& string, Regen::StringPiece *result = NULL) const;
  bool NFAMatch(const Regen::StringPiece& string, Regen::StringPiece *result = NULL) const;
  const std::string& regex() const { return regex_; }
  std::size_t max_length() const { return expr_info_.max_length; }
  std::size_t min_length() const { return expr_info_.min_length; }
  std::size_t must_max_length() const { return must_max_length_; }
  const std::string& must_max_word() const { return must_max_word_; }
  const DFA& dfa() const { return dfa_; }
  DFA& dfa() { return dfa_; }
  Regen::Options::CompileFlag olevel() const { return olevel_; }
  Expr* expr_root() const { return expr_info_.expr_root; }
  const ExprInfo& expr_info() const { return expr_info_; }
  const std::vector<StateExpr*> &state_exprs() const { return state_exprs_; }
  static CharClass* BuildCharClass(Lexer *, CharClass *);

private:
  void Parse();
  Expr* e0(Lexer *, ExprPool *);
  Expr* e1(Lexer *, ExprPool *);
  Expr* e2(Lexer *, ExprPool *);
  Expr* e3(Lexer *, ExprPool *);
  Expr* e4(Lexer *, ExprPool *);
  Expr* e5(Lexer *, ExprPool *);
  Expr* e6(Lexer *, ExprPool *);
  static StateExpr* CombineStateExpr(StateExpr*, StateExpr*, ExprPool *);
  Expr* PatchBackRef(Lexer *, Expr *, ExprPool *);

  const std::string regex_;
  Regen::Options flag_;
  ExprInfo expr_info_;
  ExprPool pool_;
  std::size_t recursion_depth_;
  std::vector<StateExpr*> state_exprs_;

  std::size_t must_max_length_;
  const std::string must_max_word_;
  std::bitset<256> involved_char_;
  std::size_t count_involved_char_;

  Regen::Options::CompileFlag olevel_;
  bool dfa_failure_;
  DFA dfa_;
};

} // namespace regen

#endif // REGEN_REGEX_H_

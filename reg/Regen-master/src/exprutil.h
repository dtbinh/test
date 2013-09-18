#ifndef REGEN_EXPRUTIL_H_
#define REGEN_EXPRUTIL_H_

#include "expr.h"

namespace regen {

class PrintExprVisitor: public ExprVisitor {
public:
  void Visit(Expr*) {}
  void Visit(Literal* e);
  void Visit(CharClass* e);
  void Visit(Dot* e) { printf("."); }
  void Visit(Anchor* e) { if (e->atype() == Anchor::kBegLine) { printf("^"); } else { printf("$"); } }
  void Visit(None * e) { printf("[:None:]"); }
  void Visit(Union* e) { printf("|"); }
  void Visit(Intersection* e) { printf("&"); }
  void Visit(XOR* e) { printf("&&"); }
  void Visit(Qmark* e) { printf("?"); }
  void Visit(Plus* e) { printf("+"); }
  void Visit(Star* e) { printf("*"); }
  static void Print(Expr *e);
protected:
  PrintExprVisitor() {}
};
  
class PrintRegexVisitor: public ExprVisitor {
public:
  void Visit(StateExpr *e) { PrintExprVisitor::Print(e); }
  void Visit(BinaryExpr *e);
  void Visit(UnaryExpr *e);
  static void Print(Expr *e);
private:
  PrintRegexVisitor() {}
};

class PrintParseTreeVisitor: public ExprVisitor {
public:
  void Visit(StateExpr* e) { print_state(e); }
  void Visit(UnaryExpr* e);
  void Visit(BinaryExpr* e);
  static void Print(Expr *e);
private:
  std::string thema;
  void print_state(Expr *e);
  void print_arrow(Expr *src, Expr *dst);
  PrintParseTreeVisitor(): thema(" shape=circle, fillcolor=lightsteelblue1, style=filled, color = navyblue ") {}
};

class DumpExprVisitor: public ExprVisitor {
public:
  void Visit(Expr *e) {}
  void Visit(StateExpr *e);
  void Visit(UnaryExpr* e);
  void Visit(BinaryExpr* e);
  static void Dump(Expr *e);
private:
  DumpExprVisitor() {}
};

} // namespace regen

#endif /* REGEN_EXPRUTIL_H_ */

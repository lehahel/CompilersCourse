#pragma once

class CBaseNonterminal;


namespace Expr {
    class CBase;
    
    class CBinaryOperation;
    class CUnaryOperation;   

    class CIntExpr;
    class CDoubleExpr;
    class CStringExpr;
    class CBoolExpr;
};

namespace Statement {
    class CBase;
    class CExpr;
    class CList;
};

struct CInt;
struct CDouble;
struct CBool;
struct CString;
struct CCustom;

class Program;
class CMain;

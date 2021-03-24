#pragma once

class CBaseNonterminal;


namespace Expr {
    class CBase;
    
    class CBinaryOperation;
    class CUnaryOperation;   

    class CIdent;
    class CIntExpr;
    class CDoubleExpr;
    class CStringExpr;
    class CBoolExpr;
};

namespace Statement {
    class CBase;
    class CExpr;
    class CLocVarDecl;
    class CList;
    class CAssignment;
};

namespace Declaration {
    class CBase;
    class CVarDecl;
};

namespace Lvalue {
    class CBase;
    class CIdentifier;
};

class CType;
class CInt;
class CDouble;
class CBool;
class CString;
class CCustom;

class Program;
class CMain;

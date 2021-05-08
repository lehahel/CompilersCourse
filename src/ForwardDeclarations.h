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

namespace Type {
    class CBase;
    class CInt;
    class CDouble;
    class CBool;
    class CString;
    class CCustom;
}

class CObject;

CObject *Add(CObject *left, CObject *right);
CObject *Sub(CObject *left, CObject *right);
CObject *Mul(CObject *left, CObject *right);
CObject *Div(CObject *left, CObject *right);
CObject *Mod(CObject *left, CObject *right);

CObject *And(CObject *left, CObject *right);

CObject *Less   (CObject *left, CObject *right);
CObject *Bigger (CObject *left, CObject *right);
CObject *Lequal (CObject *left, CObject *right);
CObject *Bequal (CObject *left, CObject *right);
CObject *Equal  (CObject *left, CObject *right);
CObject *Nequal (CObject *left, CObject *right);

CObject *UnaryMinus(CObject *object);
CObject *Not       (CObject *object);

class Program;
class CMain;

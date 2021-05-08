#pragma once

#include "Object.hpp"
#include "BoolObject.hpp"
#include "IntObject.hpp"
#include "DoubleObject.hpp"
#include "StringObject.hpp"

#include <iostream>

CObject *Add(CObject *left, CObject *right) {
    if (left->type->get_type()  == Type::INT &&
        right->type->get_type() == Type::INT) {
        CIntObject *left_casted  = dynamic_cast<CIntObject *>(left);
        CIntObject *right_casted = dynamic_cast<CIntObject *>(right);
        CIntObject* res =  new CIntObject(left_casted->value + right_casted->value);
        return res;
    }
    if (left->type->get_type()  == Type::STRING &&
        right->type->get_type() == Type::STRING) {
        CStringObject *left_casted  = dynamic_cast<CStringObject *>(left);
        CStringObject *right_casted = dynamic_cast<CStringObject *>(right);
        CStringObject* res =  new CStringObject(left_casted->value + right_casted->value);
        return res;
    }
    if (left->type->get_type()  == Type::DOUBLE &&
        right->type->get_type() == Type::DOUBLE) {
        CDoubleObject *left_casted  = dynamic_cast<CDoubleObject *>(left);
        CDoubleObject *right_casted = dynamic_cast<CDoubleObject *>(right);
        CDoubleObject* res =  new CDoubleObject(left_casted->value + right_casted->value);
        return res;
    }
    std::cerr << "Wrong object types for operation Add!" << std::endl;
    std::abort();
}

CObject *Sub(CObject *left, CObject *right) {
    if (left->type->get_type()  == Type::INT &&
        right->type->get_type() == Type::INT) {
        CIntObject *left_casted  = dynamic_cast<CIntObject *>(left);
        CIntObject *right_casted = dynamic_cast<CIntObject *>(right);
        CIntObject* res =  new CIntObject(left_casted->value - right_casted->value);
        return res;
    }
    if (left->type->get_type()  == Type::DOUBLE &&
        right->type->get_type() == Type::DOUBLE) {
        CDoubleObject *left_casted  = dynamic_cast<CDoubleObject *>(left);
        CDoubleObject *right_casted = dynamic_cast<CDoubleObject *>(right);
        CDoubleObject* res =  new CDoubleObject(left_casted->value - right_casted->value);
        return res;
    }
    std::cerr << "Wrong object types for operation Sub!" << std::endl;
    std::abort();
}

CObject *Mul(CObject *left, CObject *right) {
    if (left->type->get_type()  == Type::INT &&
        right->type->get_type() == Type::INT) {
        CIntObject *left_casted  = dynamic_cast<CIntObject *>(left);
        CIntObject *right_casted = dynamic_cast<CIntObject *>(right);
        CIntObject* res =  new CIntObject(left_casted->value * right_casted->value);
        return res;
    }
    if (left->type->get_type()  == Type::DOUBLE &&
        right->type->get_type() == Type::DOUBLE) {
        CDoubleObject *left_casted  = dynamic_cast<CDoubleObject *>(left);
        CDoubleObject *right_casted = dynamic_cast<CDoubleObject *>(right);
        CDoubleObject* res =  new CDoubleObject(left_casted->value + right_casted->value);
        return res;
    }
    std::cerr << "Wrong object types for operation Mul!" << std::endl;
    std::abort();
}

CObject *Div(CObject *left, CObject *right) {
    if (left->type->get_type()  == Type::INT &&
        right->type->get_type() == Type::INT) {
        CIntObject *left_casted  = dynamic_cast<CIntObject *>(left);
        CIntObject *right_casted = dynamic_cast<CIntObject *>(right);
        CIntObject* res =  new CIntObject(left_casted->value / right_casted->value);
        return res;
    }
    if (left->type->get_type()  == Type::DOUBLE &&
        right->type->get_type() == Type::DOUBLE) {
        CDoubleObject *left_casted  = dynamic_cast<CDoubleObject *>(left);
        CDoubleObject *right_casted = dynamic_cast<CDoubleObject *>(right);
        CDoubleObject* res =  new CDoubleObject(left_casted->value / right_casted->value);
        return res;
    }
    std::cerr << "Wrong object types for operation Div!" << std::endl;
    std::abort();
}

CObject *And(CObject *left, CObject *right) {
    if (left->type->get_type()  == Type::BOOL &&
        right->type->get_type() == Type::BOOL) {
        CBoolObject *left_casted  = dynamic_cast<CBoolObject *>(left);
        CBoolObject *right_casted = dynamic_cast<CBoolObject *>(right);
        CBoolObject* res =  new CBoolObject(left_casted->value && right_casted->value);
        return res;
    }
    std::cerr << "Wrong object types for operation Div!" << std::endl;
    std::abort();
}

CObject *Less(CObject *left, CObject *right) {
    if (left->type->get_type()  == Type::INT &&
        right->type->get_type() == Type::INT) {
        CIntObject *left_casted  = dynamic_cast<CIntObject *>(left);
        CIntObject *right_casted = dynamic_cast<CIntObject *>(right);
        CBoolObject* res =  new CBoolObject(left_casted->value < right_casted->value);
        return res;
    }
    if (left->type->get_type()  == Type::DOUBLE &&
        right->type->get_type() == Type::DOUBLE) {
        CDoubleObject *left_casted  = dynamic_cast<CDoubleObject *>(left);
        CDoubleObject *right_casted = dynamic_cast<CDoubleObject *>(right);
        CBoolObject* res =  new CBoolObject(left_casted->value < right_casted->value);
        return res;
    }
    std::cerr << "Wrong object types for operation Less!" << std::endl;
    std::abort();
}

CObject *Bigger(CObject *left, CObject *right) {
    if (left->type->get_type()  == Type::INT &&
        right->type->get_type() == Type::INT) {
        CIntObject *left_casted  = dynamic_cast<CIntObject *>(left);
        CIntObject *right_casted = dynamic_cast<CIntObject *>(right);
        CBoolObject* res =  new CBoolObject(left_casted->value > right_casted->value);
        return res;
    }
    if (left->type->get_type()  == Type::DOUBLE &&
        right->type->get_type() == Type::DOUBLE) {
        CDoubleObject *left_casted  = dynamic_cast<CDoubleObject *>(left);
        CDoubleObject *right_casted = dynamic_cast<CDoubleObject *>(right);
        CBoolObject* res =  new CBoolObject(left_casted->value > right_casted->value);
        return res;
    }
    std::cerr << "Wrong object types for operation Bigger!" << std::endl;
    std::abort();
}

CObject *Lequal(CObject *left, CObject *right) {
    if (left->type->get_type()  == Type::INT &&
        right->type->get_type() == Type::INT) {
        CIntObject *left_casted  = dynamic_cast<CIntObject *>(left);
        CIntObject *right_casted = dynamic_cast<CIntObject *>(right);
        CBoolObject* res =  new CBoolObject(left_casted->value <= right_casted->value);
        return res;
    }
    if (left->type->get_type()  == Type::DOUBLE &&
        right->type->get_type() == Type::DOUBLE) {
        CDoubleObject *left_casted  = dynamic_cast<CDoubleObject *>(left);
        CDoubleObject *right_casted = dynamic_cast<CDoubleObject *>(right);
        CBoolObject* res =  new CBoolObject(left_casted->value <= right_casted->value);
        return res;
    }
    std::cerr << "Wrong object types for operation Lequal!" << std::endl;
    std::abort();
}

CObject *Bequal(CObject *left, CObject *right) {
    if (left->type->get_type()  == Type::INT &&
        right->type->get_type() == Type::INT) {
        CIntObject *left_casted  = dynamic_cast<CIntObject *>(left);
        CIntObject *right_casted = dynamic_cast<CIntObject *>(right);
        CBoolObject* res =  new CBoolObject(left_casted->value >= right_casted->value);
        return res;
    }
    if (left->type->get_type()  == Type::DOUBLE &&
        right->type->get_type() == Type::DOUBLE) {
        CDoubleObject *left_casted  = dynamic_cast<CDoubleObject *>(left);
        CDoubleObject *right_casted = dynamic_cast<CDoubleObject *>(right);
        CBoolObject* res =  new CBoolObject(left_casted->value >= right_casted->value);
        return res;
    }
    std::cerr << "Wrong object types for operation Bequal!" << std::endl;
    std::abort();
}

CObject *Equal(CObject *left, CObject *right) {
    if (left->type->get_type()  == Type::INT &&
        right->type->get_type() == Type::INT) {
        CIntObject *left_casted  = dynamic_cast<CIntObject *>(left);
        CIntObject *right_casted = dynamic_cast<CIntObject *>(right);
        CBoolObject* res =  new CBoolObject(left_casted->value == right_casted->value);
        return res;
    }
    if (left->type->get_type()  == Type::DOUBLE &&
        right->type->get_type() == Type::DOUBLE) {
        CDoubleObject *left_casted  = dynamic_cast<CDoubleObject *>(left);
        CDoubleObject *right_casted = dynamic_cast<CDoubleObject *>(right);
        CBoolObject* res =  new CBoolObject(left_casted->value == right_casted->value);
        return res;
    }
    std::cerr << "Wrong object types for operation Equal!" << std::endl;
    std::abort();
}

CObject *Nequal(CObject *left, CObject *right) {
    if (left->type->get_type()  == Type::INT &&
        right->type->get_type() == Type::INT) {
        CIntObject *left_casted  = dynamic_cast<CIntObject *>(left);
        CIntObject *right_casted = dynamic_cast<CIntObject *>(right);
        CBoolObject* res =  new CBoolObject(left_casted->value != right_casted->value);
        return res;
    }
    if (left->type->get_type()  == Type::DOUBLE &&
        right->type->get_type() == Type::DOUBLE) {
        CDoubleObject *left_casted  = dynamic_cast<CDoubleObject *>(left);
        CDoubleObject *right_casted = dynamic_cast<CDoubleObject *>(right);
        CBoolObject* res =  new CBoolObject(left_casted->value != right_casted->value);
        return res;
    }
    std::cerr << "Wrong object types for operation Nequal!" << std::endl;
    std::abort();
}

CObject *UnaryMinus(CObject *object) {
    if (object->type->get_type() == Type::INT) {
        CIntObject *object_casted = dynamic_cast<CIntObject *>(object);
        CIntObject *res = new CIntObject(-object_casted->value);
        return res;
    }
    if (object->type->get_type() == Type::DOUBLE) {
        CDoubleObject *object_casted = dynamic_cast<CDoubleObject *>(object);
        CDoubleObject *res = new CDoubleObject(-object_casted->value);
        return res;
    }
    std::cerr << "Wrong object type for operation UnaryMinus!" << std::endl;
    std::abort();
}

CObject *Not(CObject *object) {
    if (object->type->get_type() == Type::BOOL) {
        CBoolObject *object_casted = dynamic_cast<CBoolObject *>(object);
        CBoolObject *res = new CBoolObject(!object_casted->value);
        return res;
    }
    std::cerr << "Wrong object type for operation Not!" << std::endl;
    std::abort();
}

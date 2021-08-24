//
// Created by daraw on 11/06/2020.
//
#include "ConstantFunction.h"

double OOP_Hw3::ConstantFunction::Evaluate(const map<string, double> &variables) const {
    return constant;
}
SharedPtr<OOP_Hw3::Function> OOP_Hw3::ConstantFunction::DeriveBy(const string &variable) const {
    SharedPtr<Function> func=new ConstantFunction(0.0);
    return func;
}
map<string,map<string,SharedPtr<OOP_Hw3::Function> > > OOP_Hw3::ConstantFunction::Hessian() const {
    return map<string,map<string,SharedPtr<OOP_Hw3::Function> > > ();
}
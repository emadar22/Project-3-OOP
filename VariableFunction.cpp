//
// Created by daraw on 11/06/2020.
//
#include "VariableFunction.h"
#include "ConstantFunction.h"

OOP_Hw3::VariableFunction::VariableFunction(const string &variable) {
    vars.push_back(variable);
}
double OOP_Hw3::VariableFunction::Evaluate(const map<string, double> &variables) const {
    return variables.at(*(vars.begin()));
}
SharedPtr<OOP_Hw3::Function> OOP_Hw3::VariableFunction::DeriveBy(const string &variable) const {
    if(variable==*(vars.begin())){
        SharedPtr<Function> func=new ConstantFunction(1.0);
        return func;
    }
    SharedPtr<Function> func=new ConstantFunction(0.0);
    return func;

}
map<string,map<string,SharedPtr<OOP_Hw3::Function> > > OOP_Hw3::VariableFunction::Hessian() const {
    map<string,map<string,SharedPtr<Function> > > hes;
    map<string,SharedPtr<Function> > arr;
    SharedPtr<Function> func=new ConstantFunction(0.0);
    arr.insert(std::pair<string,SharedPtr<Function> >(*(vars.begin()),func));
    hes.insert(std::pair<string,map<string,SharedPtr<Function> > >(*(vars.begin()),arr));
    return hes;
}
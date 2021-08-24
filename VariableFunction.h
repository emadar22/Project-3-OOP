//
// Created by daraw on 11/06/2020.
//

#ifndef HW3_OOP_VARIABLEFUNCTION_H
#define HW3_OOP_VARIABLEFUNCTION_H

#include "Function.h"
namespace OOP_Hw3{
    class VariableFunction: public Function{
    public:
        VariableFunction(const string& variable);
        virtual double Evaluate(const map<string, double>& variables)const ;
        virtual SharedPtr<Function> DeriveBy(const string& variable)const;
        virtual map<string,map<string,SharedPtr<Function> > > Hessian()const;

    };
}
#endif //HW3_OOP_VARIABLEFUNCTION_H

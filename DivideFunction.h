//
// Created by daraw on 11/06/2020.
//

#ifndef HW3_OOP_DIVIDEFUNCTION_H
#define HW3_OOP_DIVIDEFUNCTION_H
#include "Function.h"
#include "MultiplyFunction.h"
#include "SubtractFunction.h"
namespace OOP_Hw3{
    class DivideFunction:public Function{
        SharedPtr<Function> func1,func2;
    public:
        DivideFunction(const SharedPtr<Function> f1,const SharedPtr<Function> f2);
        virtual double Evaluate(const map<string, double>& variables)const ;
        virtual SharedPtr<Function> DeriveBy(const string& variable)const;
        virtual map<string,map<string,SharedPtr<Function> > > Hessian()const;

    };
}
#endif //HW3_OOP_DIVIDEFUNCTION_H

//
// Created by daraw on 11/06/2020.
//

#ifndef HW3_OOP_MULTIPLYFUNCTION_H
#define HW3_OOP_MULTIPLYFUNCTION_H

#include "Function.h"
#include "AddFunction.h"
namespace OOP_Hw3{
    class MultiplyFunction:public Function{
        SharedPtr<Function> func1,func2;
    public:
        /* the constructor of MultiplyFunction */
        MultiplyFunction(const SharedPtr<Function> f1,const SharedPtr<Function> f2);
        /*  getting a map and a variables, and return the evaluate
            of the variables in the first function multiply the evaluate
            of the variables in the second function  */
        virtual double Evaluate(const map<string, double>& variables)const ;
        /* Derive the the two functions by derive the first function and multiply
            it to second then add it to derive the second function and multiply
            it to first */
        virtual SharedPtr<Function> DeriveBy(const string& variable)const;
        /* this function gets a function and return the hessian of the func */
        virtual map<string,map<string,SharedPtr<Function> > > Hessian()const;

    };
}
#endif //HW3_OOP_MULTIPLYFUNCTION_H

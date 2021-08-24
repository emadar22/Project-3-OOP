//
// Created by daraw on 11/06/2020.
//

#ifndef HW3_OOP_SUBTRACTFUNCTION_H
#define HW3_OOP_SUBTRACTFUNCTION_H

#include "Function.h"
namespace OOP_Hw3{
    class SubtractFunction: public Function{
        SharedPtr<Function> func1,func2;
    public:
        /* the constructor of SubtractFunction */
        SubtractFunction(const SharedPtr<Function> f1,const SharedPtr<Function> f2);
        /*  getting a map and a variables, and return the evaluate
        of the variables in the first function Subtract the evaluate
        of the variables in the second function  */
        virtual double Evaluate(const map<string, double>& variables)const ;
        /* Derive the the two functions by the given variable
        then Subtract them */
        virtual SharedPtr<Function> DeriveBy(const string& variable)const;
        /* this function gets a function and return the hessian of the func */
        virtual map<string,map<string,SharedPtr<Function> > > Hessian()const;



    };
}
#endif //HW3_OOP_SUBTRACTFUNCTION_H

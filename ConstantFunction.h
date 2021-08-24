//
// Created by daraw on 11/06/2020.
//
#include "Function.h"
#ifndef HW3_OOP_CONSTANTFUNCTION_H
#define HW3_OOP_CONSTANTFUNCTION_H
namespace OOP_Hw3{

    class ConstantFunction: public Function{
        double constant;
    public:
        /* the constructor of constant function */
        ConstantFunction(double cnst):constant(cnst){}
        /* return the evaluate of the func in the given variables */
        virtual double Evaluate(const map<string, double>& variables)const ;
        /* Derive the func by the given variable*/
        virtual SharedPtr<Function> DeriveBy(const string& variable)const;
        /* this function gets a function and return the hessian of the func */
        virtual map<string,map<string,SharedPtr<Function> > > Hessian()const;


    };
}
#endif //HW3_OOP_CONSTANTFUNCTION_H

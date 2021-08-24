///
// Created by daraw on 09/06/2020.
//

#ifndef HW3_OOP_FUNCTION_H
#define HW3_OOP_FUNCTION_H

#include "SharedPtr.h"
#include <map>
#include <list>
#include <iostream>
#include <string>
using std::string;
using std::list;
using std::map;
namespace OOP_Hw3 {
    class Function{
    protected:
        list<string> vars;
    public:
        /* return the evaluate of the func in the given variables */
        virtual double Evaluate(const map<string, double>& variables)const = 0;
        list<string> Variables()const{
            return vars;
        }
        /* Derive the func by the given variable*/
        virtual SharedPtr<Function> DeriveBy(const string& variable)const=0;
        /* return the hessian of the func */
        virtual map<string,map<string,SharedPtr<Function> > > Hessian()const=0;

    };


}
#endif //HW3_OOP_FUNCTION_H

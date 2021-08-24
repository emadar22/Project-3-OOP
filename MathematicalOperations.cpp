//
// Created by daraw on 09/06/2020.
//
#include "MathematicalOperations.h"

namespace OOP_Hw3{

    SharedPtr<Function> operator+(SharedPtr<Function> f1, SharedPtr<Function> f2){
        SharedPtr<Function> addptr=new AddFunction(f1,f2);
        return addptr;
    }
    SharedPtr<Function> operator-(SharedPtr<Function> f1, SharedPtr<Function> f2){
        SharedPtr<Function> subptr=new SubtractFunction(f1,f2);
        return subptr;
    }
    SharedPtr<Function> operator*(SharedPtr<Function> f1, SharedPtr<Function> f2){
        SharedPtr<Function> mulptr=new MultiplyFunction(f1,f2);
        return mulptr;
    }
    SharedPtr<Function> operator/(SharedPtr<Function> f1, SharedPtr<Function> f2){
        SharedPtr<Function> devPtr=new DivideFunction(f1,f2);
        return devPtr;
    }

    SharedPtr<Function> var(const std::string& variableName){
        SharedPtr<Function> var=new VariableFunction(variableName);
        return var;
    }
    SharedPtr<Function> cnst(double num){
        SharedPtr<Function> ptr=new ConstantFunction(num);
        return ptr;
    }
}


#pragma once

#include "Function.h"
#include "AddFunction.h"
#include "SubtractFunction.h"
#include "MultiplyFunction.h"
#include "DivideFunction.h"
#include "VariableFunction.h"
#include "ConstantFunction.h"
namespace OOP_Hw3
{
    SharedPtr<Function> operator+(SharedPtr<Function> f1, SharedPtr<Function> f2);
    SharedPtr<Function> operator-(SharedPtr<Function> f1, SharedPtr<Function> f2);
    SharedPtr<Function> operator*(SharedPtr<Function> f1, SharedPtr<Function> f2);
    SharedPtr<Function> operator/(SharedPtr<Function> f1, SharedPtr<Function> f2);

    SharedPtr<Function> var(const std::string& variableName);
    SharedPtr<Function> cnst(double num);
}
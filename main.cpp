#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <string>
#include <iomanip> // Set floating point precision

#include "Function.h"
#include "MathematicalOperations.h"

using namespace OOP_Hw3;
using std::string;
using std::map;
typedef map<string, map<string, SharedPtr<Function> > > Hessian;

map<string, double> CreatePoint(double x, double y, double z)
{
    map<string, double> point = map<string, double>();
    point["x"] = x;
    point["y"] = y;
    point["z"] = z;
    return point;
}


void PrintHessianAtPoint(const Hessian& hessian, const map<string, double>& point, const string& funcName)
{
    for (Hessian::const_iterator it1 = hessian.begin(); it1 != hessian.end(); ++it1)
    {
        string var1 = it1->first;
        for (map<string, SharedPtr<Function> >::const_iterator it2 = it1->second.begin(); it2 != it1->second.end(); ++it2)
        {
            string var2 = it2->first;
            double derivativeValue = it2->second->Evaluate(point);
            std::cout << "dd" << funcName << " / d" << var1 << "d" << var2 << " = ";
            std::cout << derivativeValue << std::endl;
        }
    }
}

int main()
{
    // Set floating point printing precision to two decimal points
    std::cout << std::fixed << std::setprecision(2);

    SharedPtr<Function> x = var("x");
    SharedPtr<Function> y = var("y");
    SharedPtr<Function> z = var("z");
    map<string, double> point1 = CreatePoint(1, 0.1, 3);
    map<string, double> point2 = CreatePoint(-2.2, 4, -1.3);


    SharedPtr<Function> f1 = x * x + x - cnst(20);
    SharedPtr<Function> f2 = x * y * z + y * z / x;
    SharedPtr<Function> f3 = cnst(0.5*9) * x * x + cnst(8) * x * y  + cnst(0.5 * 7) * y * y;

    std::cout << "point1 = (1, 0.1, 3)" << std::endl;
    std::cout << "point2 = (-2.2, 4, -1.3)" << std::endl;
    list<string> va2=f2->Variables();

    std::cout << "*************" << std::endl;
    std::cout << "f1(point1) = " << f1->Evaluate(point1) << std::endl;
    std::cout << "f1(point2) = " << f1->Evaluate(point2) << std::endl;
    std::cout << "f2(point1) = " << f2->Evaluate(point1) << std::endl;
    std::cout << "f2(point2) = " << f2->Evaluate(point2) << std::endl;

    std::cout << "f1'x(point1)   = " << f1->DeriveBy("x")->Evaluate(point1) << std::endl;
    std::cout << "f2'x(point1)   = " << f2->DeriveBy("x")->Evaluate(point1) << std::endl;
    std::cout << "f2''xy(point1) = " << f2->DeriveBy("x")->DeriveBy("y")->Evaluate(point2) << std::endl;

    std::cout << "*************" << std::endl;
    std::cout << "Hessian of f2 at point2" << std::endl;

    PrintHessianAtPoint(f2->Hessian(), point2, "f2");


    std::cout << "*************" << std::endl;
    std::cout << "Hessian of f3 at point2" << std::endl;

    PrintHessianAtPoint(f3->Hessian(), point2, "f3");

    return 0;
}

//
// Created by daraw on 11/06/2020.
//

#include "AddFunction.h"
typedef map<string, map<string, SharedPtr<OOP_Hw3::Function> > > Hessian;

OOP_Hw3::AddFunction::AddFunction(const SharedPtr<OOP_Hw3::Function> f1, const SharedPtr<OOP_Hw3::Function> f2)
:func1(f1), func2(f2)
{
    vars=func1->Variables();
    list<string> ls=func2->Variables();
    vars.splice(vars.end(),ls);
    vars.sort();
    vars.unique();


}
double OOP_Hw3::AddFunction::Evaluate(const map<string, double> &variables) const {
    return func1->Evaluate(variables)+func2->Evaluate(variables);
}
SharedPtr<OOP_Hw3::Function> OOP_Hw3::AddFunction::DeriveBy(const string &variable) const {
    SharedPtr<Function> dptr=new AddFunction(func1->DeriveBy(variable),func2->DeriveBy(variable));
    return dptr;
}
map<string,map<string,SharedPtr<OOP_Hw3::Function> > > OOP_Hw3::AddFunction::Hessian() const {
    map<string,map<string,SharedPtr<OOP_Hw3::Function> > > hes;
    list<string> list1=Variables();
    for(list<string>::iterator itr=list1.begin();itr!=list1.end();itr++)
    {
        hes.insert(std::pair<string,map<string,SharedPtr<Function> > >(*itr,map<string,SharedPtr<Function> >()));
    }
    for(Hessian::iterator itrhes=hes.begin();itrhes!=hes.end();itrhes++)
    {
        SharedPtr<Function> fun=DeriveBy(itrhes->first);
        for(list<string>::iterator itr=list1.begin();itr!=list1.end();itr++){
            itrhes->second.insert(std::pair<string,SharedPtr<Function> >(*itr,fun->DeriveBy(*itr)));

        }

    }
    return hes;


}
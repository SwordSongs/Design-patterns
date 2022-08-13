#include<iostream>
using namespace std;

class Implementor
{
public:
    virtual void OperationImp() = 0;
};

class ImplementorA : public Implementor
{
public:
    void OperationImp() override
    {
        cout << "具体实现A执行方法." << endl;
    }
};

class ImplementorB : public Implementor
{
public:
    void OperationImp() override
    {
        cout << "具体实现B执行方法." << endl;
    }
};

class Abstraction
{
public:
    Abstraction(Implementor* imp) {
        this->imp = imp;
    }

    ~Abstraction() {
        if (imp)
        {
            delete imp;
            imp = NULL;
        }
    }

    void operation() {
        imp->OperationImp();
    }

protected:
    Implementor* imp;

};

class RefinedAbstractionA : public Abstraction
{
public:
    RefinedAbstractionA(Implementor* imp) : Abstraction(imp) {}
    ~RefinedAbstractionA() {}

    void  operation() {
        cout << "RefinedAbstractionA." << endl;
        imp->OperationImp();
    }

};

class RefinedAbstractionB : public Abstraction
{
public:
    RefinedAbstractionB(Implementor* imp) : Abstraction(imp) {}
    ~RefinedAbstractionB() {}

    void  operation() {
        cout << "RefinedAbstractionB." << endl;
        imp->OperationImp();
    }

};


int main()
{
    RefinedAbstractionA ra(new ImplementorA());
    RefinedAbstractionB rb(new ImplementorB());

    ra.operation();

    rb.operation();


    return 0;
}
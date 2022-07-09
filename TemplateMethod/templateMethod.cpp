#include<iostream>
using namespace std;

class AbstractClass{
    public:
        virtual void primitiveOperation1() = 0;
        virtual void primitiveOperation2() = 0;

        void templateMethod(){
            primitiveOperation1();
            primitiveOperation2();
        }
};

class ConcreteClassA : public AbstractClass{
    public:
        void primitiveOperation1(){
            cout<<"������A,����1."<<endl;
        }

          void primitiveOperation2(){
            cout<<"������A,����2."<<endl;
        }
};


class ConcreteClassB : public AbstractClass{
    public:
        void primitiveOperation1(){
            cout<<"������B,����1."<<endl;
        }

          void primitiveOperation2(){
            cout<<"������B,����2."<<endl;
        }
};

int main(){

    ConcreteClassA ca;
    ConcreteClassB cb;

    ca.templateMethod();
    cb.templateMethod();

    return 0;
}
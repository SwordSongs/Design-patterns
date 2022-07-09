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
            cout<<"具体类A,方法1."<<endl;
        }

          void primitiveOperation2(){
            cout<<"具体类A,方法2."<<endl;
        }
};


class ConcreteClassB : public AbstractClass{
    public:
        void primitiveOperation1(){
            cout<<"具体类B,方法1."<<endl;
        }

          void primitiveOperation2(){
            cout<<"具体类B,方法2."<<endl;
        }
};

int main(){

    ConcreteClassA ca;
    ConcreteClassB cb;

    ca.templateMethod();
    cb.templateMethod();

    return 0;
}
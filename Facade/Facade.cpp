#include<iostream>
using namespace std;

class SubsystemOne{
    public:
        void methodOne(){
            cout<<"子系统方法1."<<endl;
        }
};

class SubsystemTwo{
    public:
        void methodTwo(){
            cout<<"子系统方法2."<<endl;
        }
};

class SubsystemThree{
    public:
        void methodThree(){
            cout<<"子系统方法3."<<endl;
        }
};

class SubsystemFour{
    public:
        void methodFour(){
            cout<<"子系统方法4."<<endl;
        }
};

class Facade{
    public:
        void methodA(){
            sysOne.methodOne();
            sysThree.methodThree();
        }

        void methodB(){
            sysTwo.methodTwo();
            sysFour.methodFour();
        }
        
    private:
        SubsystemOne     sysOne;
        SubsystemTwo     sysTwo;
        SubsystemThree   sysThree;
        SubsystemFour    sysFour;
};

int main(){
    Facade facade;

    facade.methodA();   //依赖倒置原则 & 迪米特法则
    facade.methodB();

    return 0;
}
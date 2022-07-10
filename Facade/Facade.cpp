#include<iostream>
using namespace std;

class SubsystemOne{
    public:
        void methodOne(){
            cout<<"��ϵͳ����1."<<endl;
        }
};

class SubsystemTwo{
    public:
        void methodTwo(){
            cout<<"��ϵͳ����2."<<endl;
        }
};

class SubsystemThree{
    public:
        void methodThree(){
            cout<<"��ϵͳ����3."<<endl;
        }
};

class SubsystemFour{
    public:
        void methodFour(){
            cout<<"��ϵͳ����4."<<endl;
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

    facade.methodA();   //��������ԭ�� & �����ط���
    facade.methodB();

    return 0;
}
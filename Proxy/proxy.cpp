#include<iostream>
using namespace std;


//接口
class Subject{
    public:
        virtual void request() = 0;
};

//真实实体类
class RealSubject : public Subject
{
   public:
       void request(){
            cout<<"RealSubject  request."<<endl;
       }

};

//代理类
class Proxy : public Subject
{
   public:
       Proxy(){
           realSubject = new RealSubject();
       }

       ~Proxy(){
            if(realSubject){
                delete realSubject;
                realSubject = NULL;
            }
       }

       void request(){
            realSubject->request();
       }

    private:
        RealSubject *realSubject;

};

int main(){
    Proxy proxy;
    proxy.request();

    return 0;
}
#include<iostream>
using namespace std;

class IUser{
    public:
        virtual void insert() = 0;
        virtual void select() = 0; 
};

class SqlserverUser : public IUser{
    public:
        void insert(){
            cout<<"SqlServer USER insert."<<endl;
        }

        void select(){
            cout<<"SqlServer USER select."<<endl;
        }
};

class AccessUser : public IUser{
    public:
        void insert(){
            cout<<"Access USER insert."<<endl;
        }

        void select(){
            cout<<"Access USER select."<<endl;
        }
};

class Factory{
    public:
        virtual IUser* createUser() = 0;
};

class SqlServerFactory : public Factory{
    public:
        IUser* createUser(){
            return new SqlserverUser();
        }
};

class AccessFactory : public Factory{
    public:
        IUser* createUser(){
            return new AccessUser();
        }
};

int main(){
    //Factory  *factory = new SqlServerFactory();
    Factory *factory = new AccessFactory();   //指定生成工厂

    IUser    *user = factory->createUser();   //具体产品类解耦合，但新增Oracle产品需增加多个类
    
    user->insert();
    user->select();


    return 0;
}
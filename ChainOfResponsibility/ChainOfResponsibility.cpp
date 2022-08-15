#include<iostream>
using namespace std;


class Handler
{
    public:
        void setSuccessor(Handler *successor)
        {
            this->successor = successor;
        }

        virtual void handleRequest(int request) = 0;

    protected: 
        Handler *successor;
};

class ConcreteHandler1 : public Handler
{
    public:
       void handleRequest(const int request)
       {
            if(request >= 0 && request < 10)
            {
                cout<<"ConcreteHandler1 处理请求."<<endl;
            }
            else if(successor != NULL)
            {
                successor->handleRequest(request);
            }
       }

};

class ConcreteHandler2 : public Handler
{
    public:
       void handleRequest(const int request)
       {
            if(request >= 10 && request < 20)
            {
                cout<<"ConcreteHandler2 处理请求."<<endl;
            }
            else if(successor != NULL)
            {
                successor->handleRequest(request);
            }
       }

};

class ConcreteHandler3 : public Handler
{
    public:
       void handleRequest(const int request)
       {
            if(request >= 20 && request < 30)
            {
                cout<<"ConcreteHandler3 处理请求."<<endl;
            }
            else if(successor != NULL)
            {
                successor->handleRequest(request);
            }
       }

};


int main()
{
    Handler *h1 = new ConcreteHandler1();
    Handler *h2 = new ConcreteHandler2();
    Handler *h3 = new ConcreteHandler3();

    h1->setSuccessor(h2);    //建立职责链
    h2->setSuccessor(h3);

    int request[] = {2, 5, 14, 22, 18, 3, 27, 20};  

    for(int i: request)
    {
        h1->handleRequest(i);
    }

    delete h1;
    delete h2;
    delete h3;

    h1 = NULL;
    h2 = NULL;
    h3 = NULL;

    return 0;
}
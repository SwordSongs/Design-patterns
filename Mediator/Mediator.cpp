#include<iostream>
#include<string>
using namespace std;

class Mediator
{
    public:
        virtual void send(const string message, const string ColleagueName) = 0;
    };

    class Colleague
    {
    public:
        Colleague(Mediator* m, string s) : mediator(m), name(s) {}
        virtual ~Colleague() {}

        string getName() { return name; }

    protected:
        Mediator* mediator;
        string name;
};

class ConcreteColleague1 : public Colleague
{
    public:
        ConcreteColleague1(Mediator* m, string s) : Colleague(m, s) {}
        ~ConcreteColleague1() {}

        void send(const string message)
        {
            mediator->send(message, name);
        }

        void notify(const string message)
        {
            cout << "同事1得到消息: " << message << endl;
        }
    };

    class ConcreteColleague2 : public Colleague
    {
    public:
        ConcreteColleague2(Mediator* m, string s) : Colleague(m, s) {}
        ~ConcreteColleague2() {}

        void send(const string message)
        {
            mediator->send(message, name);
        }

        void notify(const string message)
        {
            cout << "同事2得到消息: " << message << endl;
        }
};



class ConcreteMediator : public Mediator
{
    public:
        ConcreteMediator()
        {
            colleague1 = NULL;
            colleague2 = NULL;
        }
        ~ConcreteMediator() {}

        void registerIn(ConcreteColleague1 *c1, ConcreteColleague2 *c2)
        {
            colleague1 = c1;
            colleague2 = c2;
        }

        void send(const string message, const string ColleagueName) 
        {
            if (ColleagueName == "Colleague1")
            {
                colleague2->notify(message);
            }
            else {
                colleague1->notify(message);
            }
        }

    private:
        ConcreteColleague1 *colleague1;
        ConcreteColleague2 *colleague2;
};

int main()
{
    ConcreteMediator* m = new ConcreteMediator();

    ConcreteColleague1 *c1 = new ConcreteColleague1(m, "Colleague1");
    ConcreteColleague2 *c2 = new ConcreteColleague2(m, "Colleague2");

    m->registerIn(c1, c2);

    c1->send("吃饭了吗？");
    c2->send("还没,你呢？");


    if (m != NULL)
    {
        delete m;
        m = NULL;
    }
 
    if (c1 != NULL)
    {
        delete c1;
        c1 = NULL;
    }
    
    if (c2 != NULL)
    { 
        delete c2;
        c2 = NULL;
    }
    

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

class Observer 
{
public:
    virtual void update() = 0;
    virtual int getID() const = 0;
};

class Subject 
{
public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        for (vector<Observer*>::iterator it = observers.begin(); it != observers.end(); ++it) {
            if ((*it)->getID() == observer->getID()) {
                observers.erase(it);
            }
        }
    }

    void notify() {
        for (vector<Observer*>::iterator it = observers.begin(); it != observers.end(); ++it) {
            (*it)->update();
        }
    }

private:
    vector<Observer*> observers;
};

class ConcreteSubject : public Subject 
{
    public:
        ConcreteSubject(string s="") : subjectState(s) {}

        string subjectState;
};

class ConcreteObserver : public Observer 
{
    public:
        ConcreteObserver(int id, string name, ConcreteSubject subject, string observerState) {
            this->id = id;
            this->name = name;
            this->subject = subject;
            this->observerState = observerState;
        }

        void update() {
            observerState = subject.subjectState;
            //cout << "id: " << id << ", name: " << name << ", observerState: " << observerState << endl;
        }

        int getID() const{
            return id;
        }

        void doNow() {
            cout << "id: " << id << ", name: " << name << ", observerState: " << observerState << endl;
        }

    private:
        int id;
        string name;
        ConcreteSubject subject;
        string observerState;
};


int main() {


    ConcreteSubject s("都给我停止，开始工作.");

    ConcreteObserver* os1 = new ConcreteObserver(1, "郭靖", s, "开始修炼降龙十八掌.");
    ConcreteObserver* os2 = new ConcreteObserver(2, "黄蓉", s, "开始修炼打狗棒法.");
    ConcreteObserver* os3 = new ConcreteObserver(3, "小龙女", s, "开始修炼古墓神功.");
    ConcreteObserver* os4 = new ConcreteObserver(4, "杨过", s, "开始修炼黯然销魂掌.");

    os1->doNow();
    os2->doNow();
    os3->doNow();
    os4->doNow();

    s.attach(os1);
    s.attach(os2);
    s.attach(os3);
    s.attach(os4);


    cout << "收到通知***********" << endl;
    s.notify();

    os1->doNow();
    os2->doNow();
    os3->doNow();
    os4->doNow();

    system("pause");
    return 0;
}
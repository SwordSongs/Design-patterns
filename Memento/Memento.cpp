#include<iostream>
#include<string>
using namespace std;

class Memento
{
    friend class Originator;
public:
    Memento() { state = ""; }
    Memento(string s) : state(s) { }

    string getState()
    {
        return state;
    }

private:
    string state;

};

class Originator
{
public:
    Originator(string s) : state(s) { }

    Memento createMemento()
    {
        return  Memento(state);
    }

    void setMemento(const Memento& m)
    {
        state = m.state;
    }

    void showState()
    {
        cout << state << endl;
    }

    void setState(string s)
    {
        state = s;
    }

private:
    string state;
};


class CareTaker
{
public:
    Memento getMemento()
    {
        return memento;
    }

    void setMemento(const Memento& m)
    {
        memento = m;
    }

private:
    Memento memento;
};

int main() {
    Originator o("ON");

    cout << "o.state: ";
    o.showState();

    CareTaker ct;
    ct.setMemento(o.createMemento());

    o.setState("OFF");
    cout << "o.state: ";
    o.showState();

    o.setMemento(ct.getMemento());
    cout << "o.state: ";
    o.showState();

    return 0;
}


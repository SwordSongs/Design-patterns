#include<iostream>
using namespace std;

class Worker;  //ǰ������

class State {
public:
    virtual void writeProgram(Worker* w) = 0;
};

class Worker {
public:
    Worker();

    ~Worker() {
        delete current;
    }

    double getHour() {
        return hour;
    }

    void setHour(double val) {
        hour = val;
    }

    void setState(State* s) {
        if (current)  delete current;
        current = s;
    }

    State* getState() {
        return current;
    }

    void writeProgram() {
        current->writeProgram(this);
    }

private:
    State* current;
    double hour;
    bool finish;
};


//ע������˳�������˳��
class ResetState : public State {    //add
public:
    void writeProgram(Worker* w) {
        cout << "ʱ��̫�� ǿ���°ࡣ" << endl;
    }
};

class SleepState : public State {
public:
    void writeProgram(Worker* w) override {
        if (w->getHour() < 22) {   //modified 
            cout << "��ǰʱ�䣺" << w->getHour() << ", Ҫ˯���ˡ�" << endl;
        }
        else {                     //add
            w->setState(new ResetState());
            w->writeProgram();
        }

    }
};

class EveningState : public State {
public:
    void writeProgram(Worker* w) override {
        if (w->getHour() < 21) {
            cout << "��ǰʱ�䣺" << w->getHour() << ", ״̬���� Ŭ��������" << endl;
        }
        else {
            w->setState(new SleepState());
            w->writeProgram();
        }
    }
};

class AfternoonState : public State {
public:
    void writeProgram(Worker* w) override {
        if (w->getHour() < 17) {
            cout << "��ǰʱ�䣺" << w->getHour() << ", ״̬���� Ŭ��������" << endl;
        }
        else {
            w->setState(new EveningState());
            w->writeProgram();
        }
    }
};

class NoonState : public State {
public:
    void writeProgram(Worker* w) override {
        if (w->getHour() < 13) {
            cout << "��ǰʱ�䣺" << w->getHour() << ", ���ˣ� �緹���ݡ�" << endl;
        }
        else {
            w->setState(new AfternoonState());
            w->writeProgram();
        }
    }
};

class ForenoonState : public State {
public:
    void writeProgram(Worker* w) override {
        if (w->getHour() < 12) {
            cout << "��ǰʱ�䣺" << w->getHour() << ", ���繤���� ����ٱ���" << endl;
        }
        else {
            w->setState(new NoonState());
            w->writeProgram();
        }
    }
};

Worker::Worker()
{
    current = new ForenoonState();   //����������ForenoonState
    hour = 8;
    finish = false;
}

int main() {

    Worker WD;
    WD.writeProgram();

    WD.setHour(12);
    WD.writeProgram();

    WD.setHour(15);
    WD.writeProgram();

    WD.setHour(20);
    WD.writeProgram();


    WD.setHour(21);
    WD.writeProgram();

    WD.setHour(23);
    WD.writeProgram();

    system("pause");
    return 0;
}
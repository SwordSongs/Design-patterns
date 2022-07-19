#include<iostream>
using namespace std;

class Worker;  //前置声明

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


//注意声明顺序与调用顺序
class ResetState : public State {    //add
public:
    void writeProgram(Worker* w) {
        cout << "时间太晚， 强制下班。" << endl;
    }
};

class SleepState : public State {
public:
    void writeProgram(Worker* w) override {
        if (w->getHour() < 22) {   //modified 
            cout << "当前时间：" << w->getHour() << ", 要睡着了。" << endl;
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
            cout << "当前时间：" << w->getHour() << ", 状态不错， 努力继续。" << endl;
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
            cout << "当前时间：" << w->getHour() << ", 状态不错， 努力继续。" << endl;
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
            cout << "当前时间：" << w->getHour() << ", 饿了， 午饭午休。" << endl;
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
            cout << "当前时间：" << w->getHour() << ", 上午工作， 精神百倍。" << endl;
        }
        else {
            w->setState(new NoonState());
            w->writeProgram();
        }
    }
};

Worker::Worker()
{
    current = new ForenoonState();   //需完整定义ForenoonState
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
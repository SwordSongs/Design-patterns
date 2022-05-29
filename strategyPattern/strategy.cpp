#include<iostream>
using namespace std;


//抽象算法类
class CashSuper {
public:
    virtual double acceptCash(double money) { return 0; };
};

//具体算法类
class CashNormal : public CashSuper {
    //override
public:
    double acceptCash(double money) {
        return money;
    }
};

class CashRebate : public CashSuper {
public:
    CashRebate() :moneyRebate(1) {}
    CashRebate(double moneyRebate) {
        this->moneyRebate = moneyRebate;
    }
    ~CashRebate() {}

    //override
    double acceptCash(double money) {
        return money * moneyRebate;
    }

private:
    double moneyRebate;
};

class CashReturn : public CashSuper {
public:
    CashReturn() :moneyCondition(0), moneyReturn(0) {}
    CashReturn(double moneyCondition, double moneyReturn) {
        this->moneyCondition = moneyCondition;
        this->moneyReturn = moneyReturn;
    }
    ~CashReturn() {}

    //override
    double acceptCash(double money) {
        return  money - (money / moneyCondition) * moneyReturn;
    }

private:
    double moneyCondition;
    double moneyReturn;
};

class CashContext {
public:
    CashContext(int mode) {    //工厂方法
        switch (mode) {
        default:
        {
            cs = new CashNormal();
        }
        break;
        case 0:
        {
            cs = new CashRebate(0.7);
        }
        break;
        case 1:
        {
            cs = new CashReturn(300, 100);
        }
        break;
        }
    }


    double getResult(double money) {    //策略模式
        return cs->acceptCash(money);
    }

    ~CashContext() {
        delete cs;
    }

private:    CashSuper* cs;
};



int main() {
    //CashContext cc(1);    //满三百减去一百
    CashContext cc(0); 
    double money = 3000;

    money = cc.getResult(money);
    cout << "money: " << money << endl;

    //system("pause");
    return 0;
}
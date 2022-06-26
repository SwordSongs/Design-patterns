#include<iostream>
#include<vector>
#include<string>
using namespace std;

//运算基类
class Operation {
public:
    Operation() {}
    virtual ~Operation(){}

        virtual double getResult() {
        return 0;
    }
};

//加减乘派生类
class OperationAdd : public Operation {
public:
    OperationAdd(double A = 0, double B = 0) :Operation(), numberA(A), numberB(B) {}
    ~OperationAdd() {}

    double getResult() {
        return numberA + numberB;
    }

protected:
    double numberA;
    double numberB;
};

class OperationSub : public Operation {
public:
    OperationSub(double A = 0, double B = 0) :Operation(), numberA(A), numberB(B) {}
    ~OperationSub() {}

    double getResult() {
        return numberA - numberB;
    }

protected:
    double numberA;
    double numberB;
};

class OperationMul : public Operation {
public:
    OperationMul(double A = 0, double B = 0) :Operation(), numberA(A), numberB(B) {}
    ~OperationMul() {}

    double getResult() {
        return numberA * numberB;
    }

protected:
    double numberA;
    double numberB;
};

class OperationDiv : public Operation {
public:
    OperationDiv(double A = 0, double B = 0) :Operation(), numberA(A), numberB(B) {}
    ~OperationDiv() {}

    double getResult() {
        if (numberB == 0) {
            cout << "除数不可为0." << endl;
            return  0;
        }

        return numberA / numberB;
    }

protected:
    double numberA;
    double numberB;
};

//工厂运算类

enum Aoperator {ADD, SUB, MUL, DIV};
string getOp(Aoperator oper) {
    switch (oper) {
        case ADD:
            return "+";
        case SUB:
            return "-";
        case MUL:
            return "*";
        case DIV:
            return "/";
        default:
            return "NULL";
    
    }
}

class OperationFactory {
public:
    static void createOperate(Aoperator oper, double numberA, double numberB) {
        Operation* op = NULL;

        switch (oper) {
        case ADD:
            op = new OperationAdd(numberA, numberB);
            break;
        case SUB:
            op = new OperationSub(numberA, numberB);
            break;
        case MUL:
            op = new OperationMul(numberA, numberB);
            break;
        case DIV:
            op = new OperationDiv(numberA, numberB);
            break;
        default:
            break;

        }

        if (op != NULL) {
            cout << "operator: " << getOp(oper)<<", getResult: " << op->getResult() << endl;
        }
        else {
            cout << "运算不支持" << endl;
        }
    }
};


int main() {
    OperationFactory of;
    of.createOperate(ADD, 100, 20);
    of.createOperate(SUB, 100, 20);
    of.createOperate(MUL, 100, 20);
    of.createOperate(DIV, 100, 20);

    //system("pause");   
    return 0;
}
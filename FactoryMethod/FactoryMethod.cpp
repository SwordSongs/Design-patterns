#include<iostream>
#include<vector>
#include<string>
using namespace std;

//运算基类
class Operation {
public:
    Operation() {}
    virtual ~Operation() {}

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

enum Aoperator { ADD, SUB, MUL, DIV };
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


//工厂方法接口基类
class FactoryMethod {     //wd注：简单工厂的选择判断逻辑在工厂那个类内部，添加分支修改破坏了【开放-封闭】原则，故而有了进一步抽象出来了工厂方法模式
public:
    virtual Operation* createOperation(double A, double B) = 0;

};

class AddFactory :public FactoryMethod {
public:
    Operation* createOperation(double A, double B) {
        return new OperationAdd(A, B);
    }

};

class SubFactory :public FactoryMethod {
public:
    Operation* createOperation(double A, double B) {
        return new OperationSub(A, B);
    }

};

class MulFactory :public FactoryMethod {
public:
    Operation* createOperation(double A, double B) {
        return new OperationMul(A, B);
    }

};

class DivFactory :public FactoryMethod {
public:
    Operation* createOperation(double A, double B) {
        return new OperationDiv(A, B);
    }

};

int main() {
    //FactoryMethod* factoryMethod = new AddFactory();    修改算法工厂从而实现其他算法，扩展算法只需扩展算法工厂类
    //对简单工厂进一步抽象，符合【开放-封闭】原则，只是将简单工厂的分支逻辑剥离放到调用的请求端
    //FactoryMethod* factoryMethod = new DivFactory();   
    FactoryMethod* factoryMethod = new SubFactory();  
    Operation* operation = factoryMethod->createOperation(1, 2);
    double result = operation->getResult();
    cout << "result: " << result << endl;

    system("pause");   
    return 0;
}
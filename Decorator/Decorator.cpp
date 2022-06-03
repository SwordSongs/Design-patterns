#include<iostream>
using namespace std;

class Component {
public:
    virtual void operation() {
        cout << "�����۾���" << endl;
    }
};

class ConcreteComponent :public Component {
public:
    void operation() {
        cout << "����ѧ�⡣" << endl;
    }
};

class Decorator :public Component {
public:
    void operation() {
        if (c != NULL) {
            c->operation();
        }
    }

    void setComponent(Component* c) {
        this->c = c;
    }

protected:
    Component* c;
};

class ConcreteDecoratorA :public Decorator {
public:
    ConcreteDecoratorA(string s) :Decorator() {
        addState = s;
    }

    ~ConcreteDecoratorA() {}

    void operation() {
        cout <<  "����"<<addState<<"ñ�ӡ�" << endl;    //����˳��ɵ���
        c->operation();
    }

private:
    string addState;
};

class ConcreteDecoratorB :public Decorator {
public:
    void operation() {
        addBehavior();     //����˳����Ե���
        c->operation();
    }

    void addBehavior() {
        cout << "����һ�����ơ�"<< endl;
    }

};



int main() {
    ConcreteComponent* c = new ConcreteComponent();
    ConcreteDecoratorA* a = new ConcreteDecoratorA("�Ϳ�");
    ConcreteDecoratorB* b = new ConcreteDecoratorB();

    a->setComponent(c);  //װ������װ����������˳�������������ͬ��Ϊ
    b->setComponent(a);
    b->operation();

    delete b;
    delete a;
    delete c;

    return 0;
}
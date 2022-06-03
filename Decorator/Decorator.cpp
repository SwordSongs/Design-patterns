#include<iostream>
using namespace std;

class Component {
public:
    virtual void operation() {
        cout << "睁开眼睛。" << endl;
    }
};

class ConcreteComponent :public Component {
public:
    void operation() {
        cout << "做数学题。" << endl;
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
        cout <<  "戴上"<<addState<<"帽子。" << endl;    //操作顺序可调换
        c->operation();
    }

private:
    string addState;
};

class ConcreteDecoratorB :public Decorator {
public:
    void operation() {
        addBehavior();     //操作顺序可以调换
        c->operation();
    }

    void addBehavior() {
        cout << "穿上一身名牌。"<< endl;
    }

};



int main() {
    ConcreteComponent* c = new ConcreteComponent();
    ConcreteDecoratorA* a = new ConcreteDecoratorA("耐克");
    ConcreteDecoratorB* b = new ConcreteDecoratorB();

    a->setComponent(c);  //装饰链，装饰链调用中顺序调整，产生不同行为
    b->setComponent(a);
    b->operation();

    delete b;
    delete a;
    delete c;

    return 0;
}
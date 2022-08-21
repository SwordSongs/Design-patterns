#include<iostream>
#include<vector>
using namespace std;

class Visitor
{
    public:
        virtual void visitConcreteElementA() = 0;
        virtual void visitConcreteElementB() = 0;
};

class ConcreteVisitor1 : public Visitor
{
    public:
        void visitConcreteElementA()
        {
            cout << "ConcreteElementA 被 ConcreteVisitor1访问." << endl;
        }
        void visitConcreteElementB()
        {
            cout << "ConcreteElementB 被 ConcreteVisitor1访问." << endl;
        }
};

class ConcreteVisitor2 : public Visitor
{
    public:
        void visitConcreteElementA()
        {
            cout << "ConcreteElementA 被 ConcreteVisitor2访问." << endl;
        }
        void visitConcreteElementB()
        {
            cout << "ConcreteElementB 被 ConcreteVisitor2访问." << endl;
        }
};

class Element
{
    public:
        virtual void accept(Visitor& visitor) = 0;
};

class ConcreteElementA : public Element
{
    public:
        void accept(Visitor& visitor)
        {
            visitor.visitConcreteElementA();
        }

        void operationA()
        {
            cout << "其他的A相关方法." << endl;
        }
};

class ConcreteElementB : public Element
{
    public:
        void accept(Visitor& visitor)
        {
            visitor.visitConcreteElementB();
        }

        void operationB()
        {
            cout << "其他的B相关方法." << endl;
        }
};

class ObjectStructure
{
    public:
        void attach(Element *element)
        {
            vec.push_back(element);
        }

        vector<Element*>::iterator find(Element *element)
        {
            for (vector<Element *>::iterator it = vec.begin(); it != vec.end(); ++it) 
            {
                if (*it == element) return it;
            }

            return vec.end();
        }

        void detach(Element *element)
        {
            vec.erase(find(element));
        }

        void accept(Visitor &visitor)
        {
            for (Element *e : vec)
            {
                e->accept(visitor);
            }
        }

    private:
        vector<Element*> vec;
};

int main()
{
    ObjectStructure o;

    ConcreteElementA *a = new ConcreteElementA();
    ConcreteElementB *b = new ConcreteElementB();

    o.attach(a);
    o.attach(b);

    ConcreteVisitor1 v1;
    ConcreteVisitor2 v2;

    o.accept(v1);
    o.accept(v2);

    o.detach(a);

    o.accept(v1);
    o.accept(v2);

    delete a;
    delete b;

    system("pause");

    return 0;
}
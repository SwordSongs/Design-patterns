#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Component
{
public:
    Component(string s) :name(s) {}
    ~Component() {}

    virtual void add(Component* c) = 0;
    virtual void remove(Component* c) = 0;
    virtual void display(int depth) = 0;

protected:
    string name;
};

class Leaf : public Component
{
public:
    Leaf(string name) : Component(name) {}
    ~Leaf() {}

    void add(Component* c) override
    {
        cout << "can't add to a leaf." << endl;
    }

    void remove(Component* c) override
    {
        cout << "can't remove from a leaf." << endl;
    }

    void display(int depth) override
    {
        cout << string(depth, '-') << name << endl;
    }
};

class Composite : public Component
{
public:
    Composite(string name) : Component(name) {}
    ~Composite() {}

    void add(Component* c) override
    {
        children.push_back(c);
    }

    void remove(Component* c) override
    {
        children.pop_back();
    }

    void display(int depth) override
    {
        cout << string(depth, '-') << name << endl;

        for (size_t i = 0; i < children.size(); ++i)
        {
            children[i]->display(depth + 2);
        }
    }
private:
    vector<Component*> children;
};

int main() {
    Composite *root = new Composite("root");

    Leaf* A = new Leaf("Leaf A");
    Leaf* B = new Leaf("Leaf B");


    root->add(A);
    root->add(B);
    Composite* cx = new Composite("Composite X");
    cx->add(new Leaf("Leaf XA"));
    cx->add(new Leaf("Leaf XB"));

    root->add(cx);

    Composite* cxy = new Composite("Composite XY");
    cxy->add(new Leaf("Leaf XYA"));
    cxy->add(new Leaf("Leaf XYB"));

    cx->add(cxy);

    Leaf* C = new Leaf("Leaf C");
    Leaf* D = new Leaf("Leaf D");

    root->add(C);
    root->add(D);

    root->remove(D);

    root->display(1);

    system("pause");
    return 0;
}
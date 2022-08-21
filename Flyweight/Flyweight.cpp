#include<iostream>
#include<unordered_map>
using namespace std;

class Flyweight
{
public:
    virtual void operation(int extrinsicsatate) = 0;
};

class ConcreteFlyweight : public Flyweight
{
public:
    void operation(int extrinsicstate)
    {
        cout << "具体Flyweight: " << extrinsicstate << endl;
    }

};

class UnsharedConcreteFlyweight : public Flyweight
{
public:
    void operation(int extrinsicstate)
    {
        cout << "不共享的具体Flyweight: " << extrinsicstate << endl;
    }

};

class FlyweightFactory
{
public:
    FlyweightFactory()
    {
        flyweights.insert(make_pair("X", new ConcreteFlyweight()));
        flyweights.insert(make_pair("Y", new ConcreteFlyweight()));
        flyweights.insert(make_pair("Z", new ConcreteFlyweight()));
    }

    ~FlyweightFactory() {
        for (unordered_map<string, ConcreteFlyweight*>::iterator it = flyweights.begin(); it != flyweights.end(); ++it)
        {
            delete (*it).second;
            cout << "distruct " << (*it).first << endl;
        }
    }

    Flyweight* getFlyweight(string key)
    {
        return static_cast<Flyweight*>(flyweights[key]);
    }

private:
    unordered_map<string, ConcreteFlyweight*> flyweights;
};


int main()
{
    int extrinsicsatate = 22;

    FlyweightFactory f;

    Flyweight *fx = f.getFlyweight("X");
    fx->operation(++extrinsicsatate);

    fx = f.getFlyweight("Y");
    fx->operation(++extrinsicsatate);

    fx = f.getFlyweight("Z");
    fx->operation(++extrinsicsatate);

    Flyweight* fus = new UnsharedConcreteFlyweight();
    fus->operation(++extrinsicsatate);

    delete fus;

    return 0;
}
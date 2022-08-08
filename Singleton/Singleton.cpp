#include<iostream>
using namespace std;



class Singleton
{
public:
    ~Singleton()
    {
        cout << "Singleton distructor." << endl;
    }

    static Singleton* getInstance()
    {
        if (instance == NULL)
        {
            instance = new Singleton();
        }

        return instance;
    }

private:

    Singleton()
    {
        cout << "Singleton constructor." << endl;
    }

    static Singleton *instance;
};

Singleton* Singleton::instance = NULL;



int main()
{
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    if (s1 == s2)
    {
        cout << "s1 equals s2." << endl;
    }

    return 0;
}
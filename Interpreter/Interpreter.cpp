#include<iostream>
#include<vector>
using namespace std;

class Context
{
public:
    void setInput(const string s)
    {
        input = s;
    }

    string getInput()
    {
        return input;
    }

    void setOutput(const string s)
    {
        output = s;
    }

    string getOutput()
    {
        return output;
    }


private:
    string input;
    string output;
};

class AbstractExpression
{
public:
    virtual  void interpret(Context context) = 0;
};

class TerminalExpression : public AbstractExpression
{
public:
    void interpret(Context context)
    {
        cout << "终结符解释" << endl;
    }
};

class NonTerminalExpression : public AbstractExpression
{
public:
    void interpret(Context context)
    {
        cout << "非终结符解释" << endl;
    }
};


int main()
{
    Context context;
    vector<AbstractExpression *> vec;

    TerminalExpression terminal;
    NonTerminalExpression nonTerminal;

    vec.push_back(&terminal);
    vec.push_back(&nonTerminal);
    vec.push_back(&terminal);
    vec.push_back(&terminal);

    for (vector<AbstractExpression*>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        (*it)->interpret(context);
    }

    system("pause");

    return 0;
}
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Receiver
{
public:
    void action(const string& obj) {
        cout << obj << endl;
    }
};

class Command
{
public:
    Command(Receiver* receiver) {
        this->receiver = receiver;
    }

    virtual ~Command() {}
    virtual void execute() = 0;


protected:
    Receiver* receiver;
};

class ConcreteCommand : public Command
{
public:
    ConcreteCommand(Receiver* receiver, const string& obj) : Command(receiver), obj(obj) {}
    ~ConcreteCommand() {}


    void execute() {
        receiver->action(obj);
    }

private:
    string obj;
};

class Invoker
{
public:
    Invoker(vector<Command*> commandList) {
        this->commandList = commandList;
    }

    ~Invoker() {}

    void setCommand() {
        for (vector<Command*>::iterator it = commandList.begin(); it != commandList.end(); ++it)
        {
            (*it)->execute();
        }

    }



private:
    vector<Command*> commandList;
};

int main()
{
    Receiver* receiver = new Receiver();
    Command* command1 = new ConcreteCommand(receiver, "¿¾¼¦³á°ò.");
    Command* command2  = new ConcreteCommand(receiver, "¿¾Å£ÅÅ.");
    Command* command3  = new ConcreteCommand(receiver, "¿¾ÑòÅÅ.");

    vector<Command*> commandList;
    commandList.push_back(command1);
    commandList.push_back(command2);
    commandList.push_back(command3);

    Invoker invoker(commandList);
    invoker.setCommand();

    delete receiver;
    delete command1;
    delete command2;
    delete command3;

    receiver = NULL;
    command1 = NULL;
    command2 = NULL;
    command3 = NULL;

    system("pause");
    return 0;
}
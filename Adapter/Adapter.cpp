#include<iostream>
#include<string>
using namespace std;

//������Ա
class Player
{
public:
    Player(string s) :name(s) {}
    virtual ~Player() {}

    virtual void attack() = 0;
    virtual void defense() = 0;

protected:
    string name;
};

//ǰ��
class Forward : public Player
{
public:
    Forward(string s) : Player(s) {}
    ~Forward() {};

    void attack() {
        cout << "Forward: " << name << " attack." << endl;
    }

    void defense() {
        cout << "Forward: " << name << " defense." << endl;
    }
};

//�з�
class Center : public Player
{
public:
    Center(string s) : Player(s) {}
    ~Center() {};

    void attack() {
        cout << "Center: " << name << " attack." << endl;
    }

    void defense() {
        cout << "Center: " << name << " defense." << endl;
    }
};

//����
class Guard : public Player
{
public:
    Guard(string s) : Player(s) {}
    ~Guard() {};

    void attack() {
        cout << "Guard: " << name << " attack." << endl;
    }

    void defense() {
        cout << "Guard: " << name << " defense." << endl;
    }
};

class ChinesePlayer {
public:
    ChinesePlayer(string s) :name(s) {}
    virtual ~ChinesePlayer() {}

    virtual void jingong() = 0;
    virtual void fangshou() = 0;

protected:
    string name;
};

class ChineseCenter :public ChinesePlayer {
    public:
        ChineseCenter(string s) : ChinesePlayer(s) {}
        ~ChineseCenter(){}

        void jingong() override {
            cout << "�з棺" << name << "������" << endl;
        }

        void fangshou() override {
            cout << "�з棺" << name << "���ء�" << endl;
        }
};

//������ ����
class Translator : Player {
    public:
        Translator(string adapter, string adaptee) : Player(adapter){
            cc = new ChineseCenter(adaptee);
        }
        ~Translator(){
            if (cc) delete cc;
        }

        void attack() {
            cout << "��ã����Ƿ���: "<<name<<", ������������:"<<endl;
            cc->jingong();
        }

        void defense() {
            cout << "��ã����Ƿ���: " << name << ", ������������: " << endl;
            cc->fangshou();
        }
   private://�����⼮��Ա
       ChineseCenter* cc;  
};

int main() {
    Forward mike("Mike");
    Center peter("Peter");
    Guard bob("Bob");

    Translator jake("Jake", "Ҧ��");

    mike.attack();
    peter.attack();
    bob.defense();

    //��������
    jake.defense();

    return 0;
}
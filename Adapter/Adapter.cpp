#include<iostream>
#include<string>
using namespace std;

//抽象球员
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

//前锋
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

//中锋
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

//后卫
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
            cout << "中锋：" << name << "进攻。" << endl;
        }

        void fangshou() override {
            cout << "中锋：" << name << "防守。" << endl;
        }
};

//适配者 翻译
class Translator : Player {
    public:
        Translator(string adapter, string adaptee) : Player(adapter){
            cc = new ChineseCenter(adaptee);
        }
        ~Translator(){
            if (cc) delete cc;
        }

        void attack() {
            cout << "你好，我是翻译: "<<name<<", 教练的命令是:"<<endl;
            cc->jingong();
        }

        void defense() {
            cout << "你好，我是翻译: " << name << ", 教练的命令是: " << endl;
            cc->fangshou();
        }
   private://负责外籍球员
       ChineseCenter* cc;  
};

int main() {
    Forward mike("Mike");
    Center peter("Peter");
    Guard bob("Bob");

    Translator jake("Jake", "姚明");

    mike.attack();
    peter.attack();
    bob.defense();

    //翻译适配
    jake.defense();

    return 0;
}
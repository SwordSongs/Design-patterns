#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main(){
    vector<string> passagers;

    passagers.push_back("大鸟");
    passagers.push_back("小菜");
    passagers.push_back("行李");
    passagers.push_back("老外");
    passagers.push_back("公交内部员工");
    passagers.push_back("小偷");

    for(vector<string>::iterator it = passagers.begin(); it != passagers.end(); ++it)
    {
        cout<<*it<<"请买票"<<endl;
    }

    system("pause");
    return 0;

}
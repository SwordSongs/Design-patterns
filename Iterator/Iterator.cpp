#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main(){
    vector<string> passagers;

    passagers.push_back("����");
    passagers.push_back("С��");
    passagers.push_back("����");
    passagers.push_back("����");
    passagers.push_back("�����ڲ�Ա��");
    passagers.push_back("С͵");

    for(vector<string>::iterator it = passagers.begin(); it != passagers.end(); ++it)
    {
        cout<<*it<<"����Ʊ"<<endl;
    }

    system("pause");
    return 0;

}
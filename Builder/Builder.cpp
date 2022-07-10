#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Product{
    public:
        void add(string part){
            parts.push_back(part);
        }

        void show(){
            cout<<"产品构建完毕："<<endl;

            for(vector<string>::iterator it = parts.begin(); it!=parts.end(); ++it){
                cout<<"  --"<<*it<<endl;
            }
        }
    private:
        vector<string> parts;

};


class Builder{
    public:
        virtual void buildPartA() = 0;
        virtual void buildPartB() = 0;
        virtual Product getResult() = 0;
};


class ConcreteBuilder1 : public Builder{
    public:
        void buildPartA(){
            product.add("部件A.");
        }

        void buildPartB(){
            product.add("部件B.");
        }

        Product getResult(){
            return product;
        }

    private:
        Product product;
};

class ConcreteBuilder2 : public Builder{
    public:
        void buildPartA(){
            product.add("部件AII.");
        }

        void buildPartB(){
            product.add("部件BII.");
        }

        Product getResult(){
            return product;
        }

    private:
        Product product;
};

//指挥者类，隔离用户和具体构建
class Director{
    public:
        void construct(Builder* builder){
            builder->buildPartA();             //构建步骤确定，控制构建
            builder->buildPartB();
        }
};

int main(){ 
    Director director;

    ConcreteBuilder1* cd1 = new ConcreteBuilder1();
    ConcreteBuilder2* cd2 = new ConcreteBuilder2();

    //构造I类
    director.construct(cd1);
    Product product = cd1->getResult();
    product.show();

    //构造II类    
    director.construct(cd2);
    product = cd2->getResult();
    product.show();

    return 0;
}
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
            cout<<"��Ʒ������ϣ�"<<endl;

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
            product.add("����A.");
        }

        void buildPartB(){
            product.add("����B.");
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
            product.add("����AII.");
        }

        void buildPartB(){
            product.add("����BII.");
        }

        Product getResult(){
            return product;
        }

    private:
        Product product;
};

//ָ�����࣬�����û��;��幹��
class Director{
    public:
        void construct(Builder* builder){
            builder->buildPartA();             //��������ȷ�������ƹ���
            builder->buildPartB();
        }
};

int main(){ 
    Director director;

    ConcreteBuilder1* cd1 = new ConcreteBuilder1();
    ConcreteBuilder2* cd2 = new ConcreteBuilder2();

    //����I��
    director.construct(cd1);
    Product product = cd1->getResult();
    product.show();

    //����II��    
    director.construct(cd2);
    product = cd2->getResult();
    product.show();

    return 0;
}
#include<iostream>
#include<string>
using namespace std;

class Animal{
    protected:
        string nickname;
    public:
        Animal(string a):nickname(a){}
        void virtual Cry(){}

};
class Cat:public Animal{
    public:
        Cat(string a):Animal(a){}
        void Cry(){
            cout<<"喵喵喵"<<endl;
        }

};
class Dog:public Animal{
    public:
        Dog(string a):Animal(a){}
        void Cry(){
            cout<<"汪汪汪"<<endl;
        }


};
class Donkey:public Animal{
    public:
        Donkey(string a):Animal(a){}
        void Cry(){
            cout<<"嗯昂嗯昂"<<endl;
        }


};

class Person:public Animal{
    public:
        Person(string a):Animal(a){}
        void DoCry(Animal &p){
            p.Cry();
        }
};

int main()
{
   #define N 4
   Animal *p[N] = {new Dog("阿黄"), new Cat("咪咪"), new Donkey("黔之驴"), new Cat("雪团")};
   Person baobao("宝宝");

   for(int i = 0; i < N; i++)
      baobao.DoCry(*p[i]);
   return 0;
}
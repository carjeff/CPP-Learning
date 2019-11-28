#include<iostream>
#include<string>
using namespace std;

class Animal{
    protected:
        string nickname;
    public:
        Animal(string a):nickname(a){}
        void virtual Cry();
};
class Dog:public Animal{
    public:
        Dog(string a):Animal(a){}
        void Cry(){
            cout<<"������"<<endl;
        }
};
class Cat:public Animal{
    public:
        Cat(string a):Animal(a){}
        void Cry(){
            cout<<"������"<<endl;
        }
};
class Donkey:public Animal{
    public:
        Donkey(string a):Animal(a){}
        void Cry(){
            cout<<"�ź�"<<endl;
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
   Animal *p[N] = {new Dog("����"), new Cat("����"), new Donkey("ǭ֮¿"), new Cat("ѩ��")};
   Person baobao("����");

   for(int i = 0; i < N; i++)
      baobao.DoCry(*p[i]);
   return 0;
}
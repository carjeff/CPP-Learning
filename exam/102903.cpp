/*
现在要求温蒂和她的弟弟们从Circle公有派生出Sphere球类，在派生类中必须重新定义GetArea()常成员函数计算并返回球表面积，增加GetVolume()常成员函数计算并返回球体积。彼得潘知道温蒂和她的弟弟们记不住球表面积和体积计算公式，所以把计算公式也给了她们（很贴心哦！）。温蒂请你帮助她定义子类Sphere。
   球的表面积计算公式： 4 * 3.14 * radius * radius
   球的体积计算公式：(4.0 / 3) * 3.14 * radius * radius * radius
*/
#include<iostream>
#include<iomanip>
#define pi 3.14
using namespace std;

class Circle //基类Circle
{
   protected:
      double radius; //圆半径
   public:
      void SetRadius(double r) //设置半径函数
      {
         radius = r;
      }
      double GetArea() const //返回圆面积常成员函数
      {
         return 3.14 * radius * radius;
      }
};

class Sphere:public Circle{
    public:
        double GetArea() const{return 3.14*4*radius*radius;}
        double GetVolume() const{return (4.0 / 3) * 3.14 * radius * radius * radius;}
};
int main()
{
   double r;
   cin >> r;
   Sphere s; //创建派生类Sphere的对象球s
   s.SetRadius(r); //调用基类函数设置球s的半径
   cout << "球的表面积和体积为：" << setiosflags(ios::fixed) << setprecision(2) << s.GetArea() << ", " << s.GetVolume() << endl;
   cout << "把球从中间劈开，横切面的面积为：" << s.Circle::GetArea() << endl;
   return 0;
}
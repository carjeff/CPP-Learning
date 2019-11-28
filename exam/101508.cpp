/*
声明一个Circle类，所有成员函数都在类体内定义。
   1）有int类型的数据成员radius（半径）。
   2）有1个构造函数，且为有1个参数（参数默认值为1）的构造函数，将参数赋给半径数据成员。
   3）有成员函数double area()，用于计算并返回圆的面积。pi的值使用3.14。
*/
#include<iostream>
#include<iomanip>
using namespace std;
#define pi 3.14

class Circle{
    private:
        int radius;
    public:
        Circle(int a =1){
            radius = a;
        }
        double area(){
            return pi*radius*radius;
        }
};

int main()
{
   Circle c1;
   cout << setiosflags(ios::fixed) << setprecision(2) << c1.area() << endl;
   //输出要求小数点后必须保留2位有效数字（四舍五入），不足补零

   int a;
   cin >> a;
   Circle c2(a);
   cout << setiosflags(ios::fixed) << setprecision(2) << c2.area() << endl;
   return 0;
}
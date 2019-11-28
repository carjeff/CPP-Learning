#include<iostream>
using namespace std;

//必要的头文件等，可能为多条语句
class Complex//复数Complex类
{
    protected://保护数据成员：int类型的real、image，分别代表实部、虚部
        int real,image;
    public://带有两个参数的构造函数，参数默认值均为0；在初始化列表中将形参赋给对应的数据成员
        Complex(int a=0, int b=0):real(a),image(b){}
        void Show() const{
            cout<<real;
            if(image>0){
                cout<<"+"<<image<<"i";
            }
            else if(image<0){
                cout<<image<<"i";
            }
            cout<<endl;
        }//输出Show()常成员函数，注意保持合理的复数输出格式

        Complex operator+(const Complex& z2) const {
            return Complex(real+z2.real,image+z2.image);
        }//双目+运算符重载常成员函数，有一个参数（Complex类型对象z2的常引用）

        Complex operator-(const Complex& z2) const {
            return Complex(real-z2.real,image-z2.image);
        }//双目-运算符重载常成员函数，有一个参数（Complex类型对象z2的常引用）

        Complex operator*(const Complex& z2) const {
            return Complex(real*z2.real-image*z2.image,real*z2.image+image*z2.real);
        }//双目*运算符重载常成员函数，有一个参数（Complex类型对象z2的常引用）

        Complex operator-() const {return Complex(-real, -image);}//单目-运算符重载常成员函数，无参数
};
int main()
{
   int a, b, c, d;
   cin >> a >> b >> c >> d;
   Complex z1(a, b), z2(c, d), z3; //定义复数对象
   z1.Show(); //输出z1
   z2.Show(); //输出z2

   z3 = z1 + z2 - (-z1); //进行复数运算
   z3.Show(); //输出z3

   z3 = z3 * z1; //进行复数运算
   z3.Show(); //输出z3
   return 0;
}
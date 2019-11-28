#include<iostream>
using namespace std;
// 阅读下面main()函数体代码结构并仔细观察输入输出示例，请定义互换函数模板void Exchange(……)，定义日期Date类（保护的int类型的数据成员year、month、day）。
//    从main()函数体可知，为保证程序正确执行，必须为Date类定义恰当的构造函数、重载‘<<’输出运算符，但是不必为Date类重载赋值运算符函数，可以使用默认赋值运算符函数。
template <typename type> void Exchange(type &a, type &b){
    type temp;
    temp = a;
    a =b;
    b= temp;
}
class Date{
    protected:
        int year,month,day;
    public:
        Date(int a=0, int b=0, int c=0){year = a; month =b; day =c;}
        friend ostream& operator<<(ostream &os,Date &d ){
            os<<d.year<<"年"<<d.month<<"月"<<d.day<<"日"<<endl;
            return os;
        }
};
int main()
{
   int a, b; //定义整型变量
   double c, d; //定义浮点型变量
   int y1, m1, d1, y2, m2, d2;
   cin >> a >> b >> c >> d >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
   Date day1(y1, m1, d1), day2(y2, m2, d2); //定义Date型变量

   cout<<"互换前a与b为："<<a<<","<<b<<endl;//参照输出示例，输出互换前a与b的值
   Exchange(a, b); //调用模板函数void Exchange(int,int)
   cout<<"互换前a与b为："<<a<<","<<b<<endl;//参照输出示例，输出互换后a与b的值

   cout<<"互换前c与d为："<<c<<","<<d<<endl;//参照输出示例，输出互换前c与d的值，要求小数点后必须保留2位有效数字（四舍五入），不足补零
   Exchange(c, d); //调用模板函数void Exchange(double,double)
   cout<<"互换前c与d为："<<c<<","<<d<<endl;//参照输出示例，输出互换后c与d的值，要求小数点后必须保留2位有效数字（四舍五入），不足补零

   cout<<"互换前day1与day2为："<<day1<<","<<day2<<endl;//参照输出示例，输出互换前day1与day2的值
   Exchange(day1, day2); //调用模板函数void Exchange(Date,Date)
   cout<<"互换前day1与day2为："<<day1<<","<<day2<<endl;//参照输出示例，输出互换后day1与day2的值
   return 0;
}
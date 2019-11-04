/*一、创建矩形Rectangle类，有保护的int类型的成员变量r_long长和r_width宽；无参数的构造函数和有参数（参数没有默认值）的构造函数；
其他成员函数comp_area()计算并返回矩形的面积，成员函数comp_perimeter()计算并返回矩形的周长，成员函数get_long()返回矩形的长；
成员函数get_width()返回矩形的宽。 
主函数要求：
1.无参构造矩形对象A
2.输入整数a、b，通过a、b构造矩形对象B
3.输出A的长、宽
4.输出B的长、宽
5.输出A的面积
6.输出B的周长
*/

#include<iostream>
using namespace std;
class Rectangle
{
    public:
        Rectangle(); //创建无参数构造函数
        Rectangle(int length, int width); //创建有参数的构造函数
        int comp_area(); //计算矩形面积
        int comp_perimeter();//计算矩形周长
        int get_long(); //获取矩形长度
        int get_width();//获取矩形宽度
    private:
        int r_long, r_width;
};

Rectangle::Rectangle(){ //无参数构造函数中默认长度为10，宽度为5
    r_long = 10;
    r_width = 5;
}

Rectangle::Rectangle(int length, int width){
    r_long = length;
    r_width = width;
}

int Rectangle::comp_area(){
    return r_long * r_width;
}

int Rectangle::comp_perimeter(){
    return r_long * 2 + r_width * 2;
}

int Rectangle::get_long(){
    return r_long;
}

int Rectangle::get_width(){
    return r_width;
}

int main(){
    Rectangle A;
    int a, b ;
    cout<<"Please input the length and width: ";
    cin>>a>>b;
    Rectangle B (a,b);
    int Alen = A.get_long();
    int Awid = A.get_width();
    cout<<"\nRectangle A's length is : "<<Alen;
    cout<<"\nRectangle A's width is : "<<Awid;
    int Blen = B.get_long();
    int Bwid = B.get_width();
    cout<<"\nRectangle B's length is : "<<Blen;
    cout<<"\nRectangle B's width is : "<<Bwid;
    int Aarea = A.comp_area();
    cout<<"\nRectangle A's age is : "<<Aarea;
    int Bper = B.comp_perimeter();
    cout<<"\nRectangle B's perimeter is : "<<Bper;

    return 0;
    
}

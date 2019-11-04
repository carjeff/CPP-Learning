/*
创建球Ball类，有保护的double型成员radius，其他成员请根据主程序要求自行设计，主程序要求：
1.	输入半径、构造球类对象A；
2.	输出A球的表面积、体积
3.	拷贝构造新的球类对象B；
4.	B半径扩大一倍；
5.	输出B球的表面积、体积；
*/
#include<iostream>
using namespace std;

class Ball {
    public:
        Ball(double r);   //创建构造函数
        Ball(Ball &p);   //创建拷贝构造函数
        double ball_area(); //计算球的表面积
        double ball_volume();//计算球的体积
    private:
        double radius;
        const double PI = 3.1415926; //定义常量PI为3.1415926


};

Ball::Ball(double r){
    radius = r;
}

Ball::Ball(Ball &p){
    radius = p.radius * 2;  //由于需要半径扩大一倍，直接在拷贝构造函数当中扩大
}

double Ball:: ball_area(){
    return 4 * PI * radius * radius; 
}

double Ball:: ball_volume(){
    return 4 / 3.0 * PI * radius * radius * radius;
}

int main(){
    double r;
    cout<<"Please input the radius of the Ball : ";
    cin>>r;
    Ball A(r);
    double Aarea = A.ball_area();
    double Avol = A.ball_volume();
    cout<<"\nBall A's area is : "<<Aarea;
    cout<<"\nBall A's volume is : "<<Avol;
    Ball B(A);
    double Barea = B.ball_area();
    double Bvol = B.ball_volume();
    cout<<"\nBall B's area is : "<<Barea;
    cout<<"\nBall B's volume is : "<<Bvol;  
    return 0;

}
#include <iostream>
#include <graphics.h>
using namespace std;
//中点画线法
void line1(int x1,int y1,int x2,int y2){

     int x,y,d0,d1,d2,a,b;
     y=y1;             
     a=y1-y2;          //直线方程中的a的算法
     b=x2-x1;          //直线方程中的b的算法
     d0=2*a+b;         //增量初始值
     d1=2*a;           //当>=0时的增量
     d2=2*(a+b);       //当<0时的增量
     for(x=x1;x<=x2;x++){
            putpixel(x,y,GREEN);   //打亮
        if(d0<0){
            y++;            
            d0+=d2;
        }else{

        d0+=d1;
        }

     }
}

int main()
{
    initgraph(640,480);       //打开EGE初始化
    line1(200,160,400,400);   //画线
    getch();                  //等待用户操作
    closegraph();             //关闭图形
    return 0;
}
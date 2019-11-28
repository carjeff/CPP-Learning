#include<iostream>
#include<cmath>
using namespace std;
bool Neighbor(int a, int b){
    if(abs(a-b)==1)
    return true;
    else
    return false;
    
}

bool Neighbor(int a, int b, int c){
    int temp;
    if(a>b){temp = a; a = b; b=temp;}
    if(b>c){temp = b; b = c; c=temp;}
    if(a>b){temp = a; a = b; b=temp;}
    if(b>c){temp = b; b = c; c=temp;}
    if(b-a==1&&c-a==1)
    return true;
    else
    {
        return false;
    }
    
}

int main()
{
   int a, b, c, d, e;
   cin >> a >> b >> c >> d >> e;
   if (Neighbor(a, b)) //调用重载函数Neighbor()
      cout << "true" << endl;
   else
      cout << "false" << endl;
   if (Neighbor(c, d, e)) //调用重载函数Neighbor()
      cout << "true" << endl;
   else
      cout << "false" << endl;
   return 0;
}
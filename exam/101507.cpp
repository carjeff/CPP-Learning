/*函数重载之数组升序排序
试题描述
   两个重载函数原型如下：
   void fun(int arr[], int n);
   void fun(double arr[], int n);
   编写这两个函数，将int型或double类型的数组arr[]各个元素从小到大排序，排序之后的元素仍然存在arr[]中，形参n为数组元素个数。
   在主函数main()中首先输入字符'i'或'd'，输入不含引号，前者表示后续将输入int类型数组元素，后者表示后续将输入double类型数组元素；再输入数组元素个数N和N个整数或浮点数，并将N个数存入数组中；然后调用对应的重载函数，函数调用完毕后输出数组中各个元素的值，double类型的浮点数输出要求小数点后必须保留2位有效数字（四舍五入），不足补零。
    注意：请不要修改试题描述中的函数原型，注意大小写敏感。
输入
   输入包含三行：
   第一行是字符'i'或'd'，不含引号。
第二行是N（0 < N < 1000）。
第三行是N个整数或浮点数，代表数组各个元素的值，相邻两数之间用一个空格隔开。
输出
   输出排序后数组中各个元素的值，相邻两数之间用一个空格隔开，double类型的浮点数输出要求小数点后必须保留2位有效数字（四舍五入），不足补零。
输入示例1
   i
   10
   23 20 35 27 29 26 29 35 26 28
输出示例1
   20 23 26 26 27 28 29 29 35 35
输入示例2
   d
   5
   2.3 -7.829 3 27.617 29.94433
输出示例2
   -7.83 2.30 3.00 27.62 29.94
*/


#include<iostream>
#include<iomanip>
using namespace std;
void fun(int arr[], int n){
    int temp;
    for(int i=0; i<n-1;i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        }
    }
}

void fun(double arr[], int n){
    double temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    char a;
    cin>>a;
    int n;
    cin>>n;
    int ar[1000];
    double arr[1000];
    if(a=='i'){
        for(int i=0; i<n; i++){
            cin>>ar[i];
        }
        fun(ar, n);
        for(int i=0; i<n; i++){
            cout<<ar[i]<<" ";
        }
        cout<<endl;
    }
    else if(a=='d'){
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        fun(arr,n);
        for(int i=0; i<n; i++){
            cout<<setiosflags(ios::fixed)<<setprecision(2)<<arr[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
#include<iostream>
using namespace std;
class Gather//定义类Gather
{
   protected:
      int m_data[100]; //数据成员
      int m_count; //集合元素个数

    public:
        Gather(){
            Clear();
        }
        //定义默认构造函数，函数体中调用Clear()函数
        void Clear(){
            m_count = 0;
        }
        //清空集合函数Clear()，函数体中设置m_count为0
        int GetCount(){
            return m_count;
        }
//定义返回集合元素个数函数int GetCount()，函数体中返回m_count
        int Find(int a){
            int i;
            for(i = 0; i<m_count;i++){
                if(m_data[i] == a)
                return i;
            }
            return -1;
        }
//定义集合元素位置函数int Find()，函数只有一个参数，即要查找的元素值。元素位置从0开始，找不到则返回-1。
        bool Add(int a){
            int p = Find(a);
            if(p==-1){
                m_data[m_count] = a;
                m_count++;
                return true;
            }
            else
            return false;
        }
//定义加入集合元素函数Add()，函数只有一个参数，即要加入集合的元素值。如果该元素在集合中已经存在，则返回false；否则加入该元素，并返回true。
        bool Remove(int a){
            int p = Find(a);
            if(p==-1){
                return false;
            }
            else{
                for(int i=p;i<m_count;i++){
                    m_data[i]=m_data[i+1];
                }
                m_count--;
                return true;
            }
        }
//定义移出集合元素函数Remove()，函数只有一个参数，即要移出集合的元素值。如果该元素在集合中不存在，则返回false；否则移出该元素，并返回true。
        Gather operator+(const Gather& g2){
            Gather temp = *this;
            int n = g2.m_count;
            for(int i=0; i<n;i++){
                temp.Add(g2.m_data[i]);
            }
            return temp;
        }
//重载加号运算符，代表集合并运算，函数只有一个参数，即Gather类型集合g2对象的常引用。
        Gather operator-(const Gather& g2){
            Gather temp = *this;
            int n = g2.m_count;
            for(int i=0; i<n; i++){
                temp.Remove(g2.m_data[i]);
            }
            return temp;
        }
//重载减法运算符，代表集合差运算，函数只有一个参数，即Gather类型集合g2对象的常引用。
        friend ostream& operator<<(ostream& dout, const Gather & g){
            dout<<"(";
            for(int i=0; i<g.m_count-1;i++){
                dout<<g.m_data[i]<<",";
            }
            dout<<g.m_data[g.m_count-1]<<")"<<endl;
            return dout;
        }
//输出运算符<<重载友元函数，函数有两个参数，即ostream类型dout的引用、Gather类型集合g对象的常引用。
};
int main()
{
    Gather g1,g2;
//创建Gather对象g1和g2
   int x, y, a, b;
   cin>>x>>y;
   for(int i=x; i<=y;i++){
       g1.Add(i);
   }
//输入整数x和y，然后将[x, y]之间的所有整数放入集合g1中
    g2 = g1;
//调用默认赋值运算符重载函数，将g1赋给g2
   cout << "集合g2内容如下：" << g2 << endl; //调用输出运算符重载函数

    Gather g3 = g1;//调用默认拷贝构造函数，将g1赋给g3

   cin >> x >> y >> a >> b;
    g3.Remove(x);
    g3.Remove(y);//从g3中移走集合元素函数x，y
    g3.Add(a);
    g3.Add(b);//加入a和b到集合g3中

   cout << "集合g3内容如下：" << g3 << endl;
   cout << "集合g2与g3的差：" << g2 - g3 << endl;
   cout << "集合g2与g3的合：" << g2 + g3 << endl;
   return 0;
}
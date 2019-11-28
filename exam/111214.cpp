#include <iostream>
using namespace std;
template <typename type, int n>
class Stack
{
protected:
    int m_count;
    type *m_data;

public:
    Stack()
    {
        m_data = new type[n];
        Clear();
    }
    ~Stack()
    {
        delete[] m_data;
    }
    void Clear() { m_count = 0; }
    void Push(type e)
    {
        m_data[m_count] = e;
        m_count++;
    }
    bool Pop(type &a)
    {
        if (m_count == 0)
            return false;
        m_count--;
        a = m_data[m_count];
        return true;
    }
};

int main()
{
    Stack<int, 100> stk1;    //创建对象
    Stack<double, 100> stk2; //创建对象
    int n, m;
    int c;
    double b;
    cin >> n >> m;
    for (int i = 0; i < n; i++) //输入n个整数，并压入堆栈stk1中
    {
        cin >> c;
        stk1.Push(c);
    }
    for (int i = 0; i < m; i++) //输入m个浮点数，并压入堆栈stk2中
    {
        cin >> b;
        stk2.Push(b);
    }
    int a;
    if (stk1.Pop(a))
        cout << a << endl;
    if (stk1.Pop(a))
        cout << a << endl;
    double x;
    if (stk2.Pop(x))
        cout << x << endl;
    if (stk2.Pop(x))
        cout << x << endl;
    return 0;
}
#include<iostream>
using namespace std;
class A1//����A1��
{
   protected://������Ա
      int a1;
   public://���г�Ա
      A1(int a=0):a1(a)//����һ������a�Ĺ��캯�����Ҳ�����Ĭ��ֵ0�����ڳ�ʼ���б���ʹ��a��ֵ��ʼ�����ݳ�Աa1�����������£�
      {
         cout << "ִ�л���A1�Ĺ��캯��" << endl;
      }
      ~A1()//�������������������£�
      {
         cout << "ִ�л���A1����������" << endl;
      }
      void ShowA1() const //������ݳ�Ա����Ļ
      {
         cout << "A1::a1=" << a1 << endl;
      }
};
class A2//����A2��
{
   protected://������Ա
      int a2;
   public://���г�Ա
      A2(int a=0):a2(a)//����һ������a�Ĺ��캯�����Ҳ�����Ĭ��ֵ0�����ڳ�ʼ���б���ʹ��a��ֵ��ʼ�����ݳ�Աa2�����������£�
      {
         cout << "ִ�л���A2�Ĺ��캯��" << endl;
      }
      ~A2()//�������������������£�
      {
         cout << "ִ�л���A2����������" << endl;
      }
      void ShowA2() const //������ݳ�Ա����Ļ
      {
         cout << "A2::a2=" << a2 << endl;
      }
};
class B:public A1,private A2//������B��A1���м̳У���A2˽�м̳�
{
   public://���г�Ա
      B(int a1, int a2):A1(a1),A2(a2)//������������a1��a2�Ĺ��캯�����Ҳ�������Ĭ��ֵ0�����ڳ�ʼ���б��зֱ���û���A1��A2�Ĺ��캯������������Ӧ�Ĳ��������������£�
      {
         cout << "ִ��������B�Ĺ��캯��" << endl;
      }
      ~B()//�������������������£�
      {
         cout << "ִ��������B����������" << endl;
      }
      void Show()//�������Ա����
      {
         ShowA1();//���û��ຯ��ShowA1()
         ShowA2();//���û��ຯ��ShowA2()
      }
};
int main()
{
   int x, y;
   cin >> x >> y;
   B obj(x, y); //����������B����obj
   obj.Show();
   obj.ShowA1();
   return 0;
}
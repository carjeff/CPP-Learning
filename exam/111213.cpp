#include<iostream>
using namespace std;
// �Ķ�����main()���������ṹ����ϸ�۲��������ʾ�����붨�廥������ģ��void Exchange(����)����������Date�ࣨ������int���͵����ݳ�Աyear��month��day����
//    ��main()�������֪��Ϊ��֤������ȷִ�У�����ΪDate�ඨ��ǡ���Ĺ��캯�������ء�<<���������������ǲ���ΪDate�����ظ�ֵ���������������ʹ��Ĭ�ϸ�ֵ�����������
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
            os<<d.year<<"��"<<d.month<<"��"<<d.day<<"��"<<endl;
            return os;
        }
};
int main()
{
   int a, b; //�������ͱ���
   double c, d; //���帡���ͱ���
   int y1, m1, d1, y2, m2, d2;
   cin >> a >> b >> c >> d >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
   Date day1(y1, m1, d1), day2(y2, m2, d2); //����Date�ͱ���

   cout<<"����ǰa��bΪ��"<<a<<","<<b<<endl;//�������ʾ�����������ǰa��b��ֵ
   Exchange(a, b); //����ģ�庯��void Exchange(int,int)
   cout<<"����ǰa��bΪ��"<<a<<","<<b<<endl;//�������ʾ�������������a��b��ֵ

   cout<<"����ǰc��dΪ��"<<c<<","<<d<<endl;//�������ʾ�����������ǰc��d��ֵ��Ҫ��С�������뱣��2λ��Ч���֣��������룩�����㲹��
   Exchange(c, d); //����ģ�庯��void Exchange(double,double)
   cout<<"����ǰc��dΪ��"<<c<<","<<d<<endl;//�������ʾ�������������c��d��ֵ��Ҫ��С�������뱣��2λ��Ч���֣��������룩�����㲹��

   cout<<"����ǰday1��day2Ϊ��"<<day1<<","<<day2<<endl;//�������ʾ�����������ǰday1��day2��ֵ
   Exchange(day1, day2); //����ģ�庯��void Exchange(Date,Date)
   cout<<"����ǰday1��day2Ϊ��"<<day1<<","<<day2<<endl;//�������ʾ�������������day1��day2��ֵ
   return 0;
}
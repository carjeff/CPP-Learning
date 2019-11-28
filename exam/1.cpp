#include<iostream>
using namespace std;
class Gather//������Gather
{
   protected:
      int m_data[100]; //���ݳ�Ա
      int m_count; //����Ԫ�ظ���

    public:
        Gather(){
            Clear();
        }
        //����Ĭ�Ϲ��캯�����������е���Clear()����
        void Clear(){
            m_count = 0;
        }
        //��ռ��Ϻ���Clear()��������������m_countΪ0
        int GetCount(){
            return m_count;
        }
//���巵�ؼ���Ԫ�ظ�������int GetCount()���������з���m_count
        int Find(int a){
            int i;
            for(i = 0; i<m_count;i++){
                if(m_data[i] == a)
                return i;
            }
            return -1;
        }
//���弯��Ԫ��λ�ú���int Find()������ֻ��һ����������Ҫ���ҵ�Ԫ��ֵ��Ԫ��λ�ô�0��ʼ���Ҳ����򷵻�-1��
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
//������뼯��Ԫ�غ���Add()������ֻ��һ����������Ҫ���뼯�ϵ�Ԫ��ֵ�������Ԫ���ڼ������Ѿ����ڣ��򷵻�false����������Ԫ�أ�������true��
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
//�����Ƴ�����Ԫ�غ���Remove()������ֻ��һ����������Ҫ�Ƴ����ϵ�Ԫ��ֵ�������Ԫ���ڼ����в����ڣ��򷵻�false�������Ƴ���Ԫ�أ�������true��
        Gather operator+(const Gather& g2){
            Gather temp = *this;
            int n = g2.m_count;
            for(int i=0; i<n;i++){
                temp.Add(g2.m_data[i]);
            }
            return temp;
        }
//���ؼӺ�������������ϲ����㣬����ֻ��һ����������Gather���ͼ���g2����ĳ����á�
        Gather operator-(const Gather& g2){
            Gather temp = *this;
            int n = g2.m_count;
            for(int i=0; i<n; i++){
                temp.Remove(g2.m_data[i]);
            }
            return temp;
        }
//���ؼ���������������ϲ����㣬����ֻ��һ����������Gather���ͼ���g2����ĳ����á�
        friend ostream& operator<<(ostream& dout, const Gather & g){
            dout<<"(";
            for(int i=0; i<g.m_count-1;i++){
                dout<<g.m_data[i]<<",";
            }
            dout<<g.m_data[g.m_count-1]<<")"<<endl;
            return dout;
        }
//��������<<������Ԫ������������������������ostream����dout�����á�Gather���ͼ���g����ĳ����á�
};
int main()
{
    Gather g1,g2;
//����Gather����g1��g2
   int x, y, a, b;
   cin>>x>>y;
   for(int i=x; i<=y;i++){
       g1.Add(i);
   }
//��������x��y��Ȼ��[x, y]֮��������������뼯��g1��
    g2 = g1;
//����Ĭ�ϸ�ֵ��������غ�������g1����g2
   cout << "����g2�������£�" << g2 << endl; //���������������غ���

    Gather g3 = g1;//����Ĭ�Ͽ������캯������g1����g3

   cin >> x >> y >> a >> b;
    g3.Remove(x);
    g3.Remove(y);//��g3�����߼���Ԫ�غ���x��y
    g3.Add(a);
    g3.Add(b);//����a��b������g3��

   cout << "����g3�������£�" << g3 << endl;
   cout << "����g2��g3�Ĳ" << g2 - g3 << endl;
   cout << "����g2��g3�ĺϣ�" << g2 + g3 << endl;
   return 0;
}
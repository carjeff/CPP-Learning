#include<iostream>
using namespace std;
class Staff{
    protected:
        int code;
        string name;
        static int count;
    public:
        Staff(string a){name = a; code = count; count++;}
        void SetName(string a){name = a;}
        string GetName(){return name;}
        int GetCode(){return code;}
        static int GetStaffCount(){return count;}

};
int Staff::count = 0;

class Teacher: virtual public Staff{
    protected:
        string subject;
    public:
        Teacher(string a, string b):Staff(a),subject(b){}
        void SetSubject(string a){subject = a;}
        string GetSubject(){return subject;}
};

class Officer: virtual public Staff{
    protected:
        string work;
    public:
        Officer(string a, string b):Staff(a),work(b){}
        void SetWork(string a){work = a;}
        string GetWork(){return work;}
};

class Teacher_Officer:public Teacher,public Officer{
    public:
        Teacher_Officer(string a, string b, string c):Staff(a),Teacher(a,b),Officer(a,c){}
};


int main()
{
   Teacher t1("����","�����ѧ"); //������ѧ��Ա��t1
   Teacher t2 ("�����","����ѧ");
   Officer o1("��ľ��","����Ƴ�"); //�����̸���Ա��o1
   Teacher_Officer to3("�ջ�","�����ѧ","��Ժ��");//������ʦ�̸���Ա��to3

   cout << "���н�ְ��" << Staff::GetStaffCount() << "��" << endl;
   cout << t1.GetCode() << ", " << t1.GetName() << ", " << t1.GetSubject() << endl;
   cout << t2.GetCode() << ", " << t2.GetName() << ", " << t2.GetSubject() << endl;
   cout << o1.GetCode() << ", " << o1.GetName() << ", " << o1.GetWork() << endl;
   cout << to3.GetCode() << ", " << to3.GetName() << ", " << to3.GetSubject() << ", " << to3.GetWork() << endl;
   return 0;
}
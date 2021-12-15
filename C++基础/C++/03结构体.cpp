#include "swap.h"

void print_struct(struct Teacher tea1);
void print_struct_1(struct Teacher * p);
void print_struct_2(const struct Teacher* p);

// �ṹ�� �����û��Զ������������:  struct �ṹ���� {�ṹ���Ա�б�};
struct Student
{
	string name;
	int age;
	float score;
}s3;   // s3Ϊ�����ṹ�嶨��ʱ˳�㴴���Ľṹ����� ��ʡ


// �ṹ��Ƕ��
struct Teacher
{
	int id;
	string name;
	int age;
	struct Student stu;
};


void struct_1()
{
	struct Student s1;
	s1.name = "����";
	s1.age = 23;
	s1.score = 99.5;
	cout <<"������" << s1.name<<"\t���䣺" << s1.age<<" ������"<< s1.score<< endl;

	Student s2 = { "����", 25,98 };      //C++�д����ṹ�����ʱ��struct�ǿ�ʡ��
	s3.name = "С��"; s3.age = 26; s3.score = 59;
	cout << "������" << s3.name << "\t���䣺" << s3.age << " ������" << s3.score << endl;
	

	// �ṹ������    struct �ṹ���� ������[Ԫ�ظ���] = {{},{},...{}};
	struct Student stu_array[3] =
	{
		{"����",18,60},
		{"��ʣ",15,71},
		{"����",23,67}
	};
	// ֵ���޸�
	stu_array[0].name = "����";
	stu_array[0].age = 22;
	stu_array[1].score = 86;

	// �����ṹ������
	for (int i = 0; i < 3; i++)
	{
		cout << "������" << stu_array[i].name << "\t���䣺" << stu_array[i].age << " ������" << stu_array[i].score << endl;
	}


	// �ṹ��ָ�� ͨ��ָ����ʽṹ���еĳ�Ա   
	// p->name   ͨ���ṹ��ָ������ʽṹ������
	Student* p = &s3;           // p��ָ��ṹ�������ָ��
	cout << p->name << endl;    // ͨ�� p->name �����ʽṹ������


	Teacher tea1;
	tea1.id = 3794; tea1.name = "��÷÷"; tea1.age = 68;
	tea1.stu.name = "��ʣ";
	tea1.stu.age = 24;
	tea1.stu.score = 59.5;
	Teacher tea2 = { 9527,"�",55,{"����",25,78} };
	Teacher tea3 = { 1122,"��ȫ��", 28,	s3 };
	

	// �ṹ������������
	// ֵ���ݣ��´��һ�����ݣ� ʵ�β���ı�
	print_struct(tea1);
	cout << "(�ں������޸�Ϊ ÷÷�� ��)��ʦ������" << tea1.name << "  ˵��ֵ����ʱ�βθı䲻��Ӱ��ʵ��" << endl;

	// ��ַ���� ��ı��������б���
	print_struct_1(&tea2);
	cout << "(�ں������޸ĺ�)ѧ��������" << tea2.stu.name << endl;


	// �ṹ����const��ʹ�ã����ڵ�ַ����ʱ ��ֹ�������
	// ����const Teacher * p����ָ�� ���ṹ����ֻ����ʽ���� �����޸� �ҽ�Լ�ڴ�ռ�
	print_struct_2(&tea3);

}

void print_struct(struct Teacher tea1)
{
	cout <<  "��ʦ������(����ṹ��:tea1.name)" << tea1.name << endl;
	tea1.name = "÷÷��";
}

void print_struct_1(struct Teacher * p)
{
	cout << "ѧ��������(����ָ��:p->stu.name)" << p->stu.name << endl;
	p->stu.name = "����";
}

void print_struct_2(const struct Teacher* p)   // ���ó���ָ�� ���ṹ����ֻ����ʽ���� �����޸� �ҽ�Լ�ڴ�ռ�
{
	// p->stu.age = 1000;   // �ᱨ��
	cout << "ѧ������(����const Teacher * p����ָ�� ֻ���ҿɽ�ʡ�ڴ�ռ�)��" << p->stu.age << endl;
}

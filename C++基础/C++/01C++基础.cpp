#include <iostream>
#include <string>    // ʹ��C++�����ַ���Ҫ������ͷ�ļ�
#include "swap.h"   // ˫���ű�ʾ�����Զ���ͷ�ļ�
using namespace std;

#define A1 10  //����곣��

// ��������
void show_arr(int arr[2][3]);

 // �����ķ��ļ���д
  // 1 ����.h��׺����ͷ�ļ�
  // 2 ����.cpp��׺����Դ�ļ�
  // 3 ��ͷ�ļ���д��������
  // 4 ��Դ�ļ���д��������

int main()
{
	const int aa1 = 10;         //��const���α���ʹ���Ϊ����
	// ���� cin >> aa1;
	// ��� cout << a << endl;  // ֻ��ʾ��С�����5λ

	// ����
	int aa2 = 10;              //���ͣ�ռ�ĸ��ֽڣ�
	short aa3 = 10;                 //�����ͣ�ռ�����ֽڣ�
	long aa4 = 10;                  // 4�ֽ�
	aa2 = sizeof(aa4);
	// cout << aa2 << endl;
	long long aa5 = 20;             // �������ͣ�ռ�˸��ֽڣ�

	// ǿ������ת��   ֻ���γ���
	cout << sizeof((short)aa4) << endl;
	cout << sizeof(aa4) << endl;
	cout << &aa4 << endl;   // &ȡ��ַ

	// ʵ�ͣ������ͣ�
	float aa6 = 3.14f;         // 4�ֽ� ������ֵ���'f'��ʾΪ������float
	float aa7 = 3e-2;          // ��ѧ������ 3*10^-2
	double aa8 = 3.1415926535; // 8�ֽ� 

	// �ַ������ַ���
	char ch = 'a';            // �ַ��� ռһ���ֽ� ֻ���õ�����
	char ch1[] = "hello world";     // C����ַ��� ֻ����˫����
	string ch2 = "hello world";     // C++����ַ��� ֻ����˫����

	// ��������bool
	bool bb1 = true;
	bool bb2 = false;

	// ת���ַ���\n \t \r \a....
	// ����������� + - * / % ++ -- 
	aa3 = ++aa2 * 10;        // aa2�ȼ�һ�ڽ��б��ʽ������
	aa4 = aa2++ * 10;        // aa2�Ƚ��б��ʽ������ �ټ�һ

	// ��ֵ�������= += -= *= /= %=
	// �Ƚ��������== != > <  >= <= 
	// �߼�������� &&    ||   !

    // �������̽ṹ ˳��ѡ��ѭ���ṹ
	// if���
	if(aa4)
	{
		aa4 += 1;
	}
	else if(aa5 > aa1)
	{
		aa5 -= 1;
	}
	else
	{
		aa2 += 1;
	}

	// ��Ŀ�����
	aa2 > aa3 ? aa2 : aa3 = 100 ;    // ��100 ��ֵ��aa2��aa3�нϴ��ֵ

	// switch���  �жϷ�֧ʱֻ�������ͻ��ַ��ͣ�������һ�����䣬Ч�ʸ���if
	switch (aa2)
	{
	case 100:
		aa2++;
		break;   // ����дbreak; �Ὣ���·���֧����ȫ��ִ��
	case 20:
		aa2--;
		break;
	default:
		break;
	}
	
	// ѭ���ṹ
	// while���
	while (aa2)
	{
		if (aa2-- < 0)
			break;
	}

	// do{}while(); ������ִ��һ��ѭ��������ж�����
	do
	{
		++aa2;
	} while (aa2 < 10);

	// for ѭ����� for(��ʼ���ʽ;�������ʽ;ĩβѭ����){ѭ�����;}
	for (int i = 0; i < 10; i++)
	{
		// cout << i << endl;
	}

	// ��ת��䣺break��continue��goto
	// break:����ѡ��switch����ѭ���ṹ��Ƕ��ѭ��ֻ����һ�㣩
	// continue:ѭ���������������ѭ��
	// goto:��������ת
	goto FLAG;
	++aa2;
FLAG:

	// ���� (�������Ǹ���������ʾ�׸�Ԫ�ص������ַ�����ܱ���ֵ)
	int arr1[2];
	arr1[0] = 0; arr1[1] = 1;
	char str11[5] = { 'h','e','l','l','o' };  // �˴����������ַ���
	int arr2[] = { 0,1,2,3,4,5,6,7,8,9 };
	// sizeof(str11);    // ����ռ�ÿռ��С
	cout << "�����׵�ַΪ��" << arr1 << endl;
	cout << "�����׸�Ԫ�ص�ַΪ��" << &arr1[0] << endl;

	// ����Ԫ�ص�����
	int start = 0;
	int end = sizeof(arr2) / sizeof(arr2[0]) - 1;
	for (;start < end;)
	{
		int temp = arr2[end];
		arr2[end] = arr2[start];
		arr2[start] = temp;
		start++; end--;
	}

	// ��ά����
	int arr3[2][3]; arr3[0][1] = 10;
	int arr4[2][3] = { {1,2,3},{4,5,6} };
	int arr5[2][3] = { 1,2,3,4,5,6 };
	int arr6[][3] = { 1,2,3,4,5,6 };   // ��������ʡ

	cout << "��ά����ռ���ڴ�ռ�Ϊ��" << sizeof(arr6) << "�׵�ַΪ��" << arr6 << endl;
	cout << "��ά����ÿ��ռ���ڴ�ռ�Ϊ��" << sizeof(arr6[0]) << endl;
	cout << "��ά����������" << sizeof(arr6) / sizeof(arr6[0]) << endl;
	cout << "��ά����������" << sizeof(arr6[0]) / sizeof(arr6[0][0]) << endl;

	show_arr(arr6);    // ������ʾ����
	int a= 1, b = 2,c = 0;
	c = sum_d(a, b);
	cout << c << endl;

	cout << "***********************ָ��************************" << endl;
	// ָ��
	point_1();
	cout << "**********************�ṹ��***********************" << endl;
	// �ṹ��
	struct_1();

	system("pause");
	return 0;
}


// ����(��������������)
void show_arr(int arr[2][3])    // ����ֵ���� ������ �β�(ҲҪָ������)
{
	cout << sizeof(arr) << sizeof(arr) / sizeof(arr[0]) << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return;  // �շ���ֵvoid��ʡ�˴�return
}
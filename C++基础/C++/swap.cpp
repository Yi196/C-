#include"swap.h"


// Դ�ļ���д��������
double sum_d(double a, double b)
{
	double c = a + b;
	return c;
}

// ������������ֵ
void swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
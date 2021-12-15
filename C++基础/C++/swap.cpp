#include"swap.h"


// 源文件中写函数定义
double sum_d(double a, double b)
{
	double c = a + b;
	return c;
}

// 交换两变量的值
void swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
#include "swap.h"


// 地址传递时，定义形参为指针
void swap_1(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


// 指针：指向变量的物理地址  指针每次自增都会自动偏移创建时指定数据类型个字节
void point_1() 
{
	int a = 10, c = 15, d = 20;
	// 定义指针  指针指向的数据类型 * 指针变量名
	int * p;   // int *  （数据类型 *）是指针的数据类型
	// 让指针指向变量（记录变量a的地址）
	p = &a;  // & 取址符
	// * 解引用（找到指针指向的内存中的数据）
	*p = 100;
	cout << "a=" << a << endl;

	// 指针所占空间：32位系统占4个字节 64位系统占8个字节
	int b = 100;
	int* p1 = &b;

	// 空指针：指针变量指向内存中编号为0的空间 （作用：初始化指针变量；空指针指向的内存是不可访问的0~255间被系统占用）
	int* p5 = NULL;

	// 野指针： 指针变量指向非法的内存空间
	// int* p = (int*)0x1100;

	// const修饰指针（1、const修饰指针 --常量指针 2、const修饰常量 --指针常量 3、const即修饰指针，又修饰常量）
	// 常量指针（指针的指向可以改，但指针指向的值不能修改） （*p = 10 非法）
	const int* p2 = &b;     // 即p2可改为指向其他变量，但指向b时，b的内容不可更改
	p2 = &a;
	b = 10;                 // 当p2指向其他变量时，之前的变量恢复可修改状态
	cout << "b " << b << endl;

	// 指针常量 (指针的指向不可以修改，指向的变量值可以修改)   （p = &a 非法）
	int* const p3 = &c;

	// const既修饰指针又修饰常量  (指针指向和指向的值都不可修改)
	const int* const p4 = &d;
	
	// 指针访问数组
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p6 = arr;
	for (int i = 0; i < 10; i++)
	{
		cout << "arr[i]\t" << *p6++ << endl;  // 指针每次自增都会自动偏移创建时指定数据类型个字节 此处每次偏移四个字节
	}

	// 地址传递  可以在函数内改变函数外变量的值
	int a1 = 10, a2 = 20;
	int* p7 = &a2;
	swap_1(&a1, p7);   // 调用时传入地址或指针变量
	cout << "a1,a2  "<< a1 << a2 <<endl;

}
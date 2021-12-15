#include <iostream>
#include <string>    // 使用C++风格的字符串要包含该头文件
#include "swap.h"   // 双引号表示导入自定义头文件
using namespace std;

#define A1 10  //定义宏常量

// 函数声明
void show_arr(int arr[2][3]);

 // 函数的分文件编写
  // 1 创建.h后缀名的头文件
  // 2 创建.cpp后缀名的源文件
  // 3 在头文件中写函数声明
  // 4 在源文件中写函数定义

int main()
{
	const int aa1 = 10;         //用const修饰变量使其变为常量
	// 输入 cin >> aa1;
	// 输出 cout << a << endl;  // 只显示到小数点后5位

	// 整型
	int aa2 = 10;              //整型（占四个字节）
	short aa3 = 10;                 //短整型（占两个字节）
	long aa4 = 10;                  // 4字节
	aa2 = sizeof(aa4);
	// cout << aa2 << endl;
	long long aa5 = 20;             // 长长整型（占八个字节）

	// 强制类型转换   只本次成立
	cout << sizeof((short)aa4) << endl;
	cout << sizeof(aa4) << endl;
	cout << &aa4 << endl;   // &取地址

	// 实型（浮点型）
	float aa6 = 3.14f;         // 4字节 常在数值后加'f'表示为单精度float
	float aa7 = 3e-2;          // 科学计数法 3*10^-2
	double aa8 = 3.1415926535; // 8字节 

	// 字符型与字符串
	char ch = 'a';            // 字符型 占一个字节 只能用单引号
	char ch1[] = "hello world";     // C风格字符串 只能用双引号
	string ch2 = "hello world";     // C++风格字符串 只能用双引号

	// 布尔类型bool
	bool bb1 = true;
	bool bb2 = false;

	// 转义字符：\n \t \r \a....
	// 算术运算符： + - * / % ++ -- 
	aa3 = ++aa2 * 10;        // aa2先加一在进行表达式的运算
	aa4 = aa2++ * 10;        // aa2先进行表达式的运算 再加一

	// 赋值运算符：= += -= *= /= %=
	// 比较运算符：== != > <  >= <= 
	// 逻辑运算符： &&    ||   !

    // 程序流程结构 顺序、选择、循环结构
	// if语句
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

	// 三目运算符
	aa2 > aa3 ? aa2 : aa3 = 100 ;    // 将100 赋值给aa2、aa3中较大的值

	// switch语句  判断分支时只能是整型或字符型，不能是一个区间，效率高于if
	switch (aa2)
	{
	case 100:
		aa2++;
		break;   // 若不写break; 会将其下方分支内容全部执行
	case 20:
		aa2--;
		break;
	default:
		break;
	}
	
	// 循环结构
	// while语句
	while (aa2)
	{
		if (aa2-- < 0)
			break;
	}

	// do{}while(); 语句会先执行一次循环语句再判断条件
	do
	{
		++aa2;
	} while (aa2 < 10);

	// for 循环语句 for(起始表达式;条件表达式;末尾循环体){循环语句;}
	for (int i = 0; i < 10; i++)
	{
		// cout << i << endl;
	}

	// 跳转语句：break、continue、goto
	// break:跳出选择（switch）、循环结构（嵌套循环只跳出一层）
	// continue:循环语句中跳出本次循环
	// goto:无条件跳转
	goto FLAG;
	++aa2;
FLAG:

	// 数组 (数组名是个常量，表示首个元素的物理地址，不能被赋值)
	int arr1[2];
	arr1[0] = 0; arr1[1] = 1;
	char str11[5] = { 'h','e','l','l','o' };  // 此处构建的是字符串
	int arr2[] = { 0,1,2,3,4,5,6,7,8,9 };
	// sizeof(str11);    // 数组占用空间大小
	cout << "数组首地址为：" << arr1 << endl;
	cout << "数组首个元素地址为：" << &arr1[0] << endl;

	// 数组元素的逆置
	int start = 0;
	int end = sizeof(arr2) / sizeof(arr2[0]) - 1;
	for (;start < end;)
	{
		int temp = arr2[end];
		arr2[end] = arr2[start];
		arr2[start] = temp;
		start++; end--;
	}

	// 二维数组
	int arr3[2][3]; arr3[0][1] = 10;
	int arr4[2][3] = { {1,2,3},{4,5,6} };
	int arr5[2][3] = { 1,2,3,4,5,6 };
	int arr6[][3] = { 1,2,3,4,5,6 };   // 列数不能省

	cout << "二维数组占用内存空间为：" << sizeof(arr6) << "首地址为：" << arr6 << endl;
	cout << "二维数组每行占用内存空间为：" << sizeof(arr6[0]) << endl;
	cout << "二维数组行数：" << sizeof(arr6) / sizeof(arr6[0]) << endl;
	cout << "二维数组列数：" << sizeof(arr6[0]) / sizeof(arr6[0][0]) << endl;

	show_arr(arr6);    // 调用显示函数
	int a= 1, b = 2,c = 0;
	c = sum_d(a, b);
	cout << c << endl;

	cout << "***********************指针************************" << endl;
	// 指针
	point_1();
	cout << "**********************结构体***********************" << endl;
	// 结构体
	struct_1();

	system("pause");
	return 0;
}


// 函数(定义在主函数外)
void show_arr(int arr[2][3])    // 返回值类型 函数名 形参(也要指定类型)
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
	return;  // 空返回值void可省此处return
}
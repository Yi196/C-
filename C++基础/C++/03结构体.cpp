#include "swap.h"

void print_struct(struct Teacher tea1);
void print_struct_1(struct Teacher * p);
void print_struct_2(const struct Teacher* p);

// 结构体 创建用户自定义的数据类型:  struct 结构体名 {结构体成员列表};
struct Student
{
	string name;
	int age;
	float score;
}s3;   // s3为创建结构体定义时顺便创建的结构体变量 可省


// 结构体嵌套
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
	s1.name = "张三";
	s1.age = 23;
	s1.score = 99.5;
	cout <<"姓名：" << s1.name<<"\t年龄：" << s1.age<<" 分数："<< s1.score<< endl;

	Student s2 = { "李四", 25,98 };      //C++中创建结构体变量时的struct是可省的
	s3.name = "小明"; s3.age = 26; s3.score = 59;
	cout << "姓名：" << s3.name << "\t年龄：" << s3.age << " 分数：" << s3.score << endl;
	

	// 结构体数组    struct 结构体名 数组名[元素个数] = {{},{},...{}};
	struct Student stu_array[3] =
	{
		{"狗蛋",18,60},
		{"狗剩",15,71},
		{"花狗",23,67}
	};
	// 值的修改
	stu_array[0].name = "大购置";
	stu_array[0].age = 22;
	stu_array[1].score = 86;

	// 遍历结构体数组
	for (int i = 0; i < 3; i++)
	{
		cout << "姓名：" << stu_array[i].name << "\t年龄：" << stu_array[i].age << " 分数：" << stu_array[i].score << endl;
	}


	// 结构体指针 通过指针访问结构体中的成员   
	// p->name   通过结构体指针访来问结构体属性
	Student* p = &s3;           // p是指向结构体变量的指针
	cout << p->name << endl;    // 通过 p->name 来访问结构体属性


	Teacher tea1;
	tea1.id = 3794; tea1.name = "韩梅梅"; tea1.age = 68;
	tea1.stu.name = "狗剩";
	tea1.stu.age = 24;
	tea1.stu.score = 59.5;
	Teacher tea2 = { 9527,"李华",55,{"狗蛋",25,78} };
	Teacher tea3 = { 1122,"张全蛋", 28,	s3 };
	

	// 结构体做函数参数
	// 值传递（会拷贝一份数据） 实参不会改变
	print_struct(tea1);
	cout << "(在函数内修改为 梅梅韩 后)教师姓名：" << tea1.name << "  说明值传递时形参改变不会影响实参" << endl;

	// 地址传递 会改变主函数中变量
	print_struct_1(&tea2);
	cout << "(在函数内修改后)学生姓名：" << tea2.stu.name << endl;


	// 结构体中const的使用（用于地址传递时 防止误操作）
	// 定义const Teacher * p常量指针 将结构体以只读形式传入 不可修改 且节约内存空间
	print_struct_2(&tea3);

}

void print_struct(struct Teacher tea1)
{
	cout <<  "教师姓名：(传入结构体:tea1.name)" << tea1.name << endl;
	tea1.name = "梅梅韩";
}

void print_struct_1(struct Teacher * p)
{
	cout << "学生姓名：(传入指针:p->stu.name)" << p->stu.name << endl;
	p->stu.name = "花狗";
}

void print_struct_2(const struct Teacher* p)   // 利用常量指针 将结构体以只读形式传入 不可修改 且节约内存空间
{
	// p->stu.age = 1000;   // 会报错
	cout << "学生年龄(定义const Teacher * p常量指针 只读且可节省内存空间)：" << p->stu.age << endl;
}

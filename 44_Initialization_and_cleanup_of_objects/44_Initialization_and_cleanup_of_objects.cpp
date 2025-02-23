﻿//// 44_Initialization_and_cleanup_of_objects.cpp: 目标的源文件。
////
//
//#include "44_Initialization_and_cleanup_of_objects.h"
//
////对象的初始化和清理
////构造函数初始化
///*
//两种分类方式：
//	按参数类型分：有参构造和无参构造（默认构造）
//	按类型分为：普通构造和拷贝构造
//
//三种调用方式：
//	括号法
//	显示法
//	隐式转换法
//*/
//class Person 
//{
//public:
//	//1.构造函数没有返回值不用写void
//	//函数名和类名相同
//	//构造函数可以有参数，可以发生重载
//	//创建对象的时候，构造函数会自动调用，且只调用一次
//
//	//无参构造函数
//	Person()
//	{
//		cout << "Person类的默认构造函数的调用" << endl;
//	}
//	//有参构造函数
//	Person(int a)
//	{
//		age = a;
//		cout << "Person类的有参构造函数的调用" << endl;
//	}
//	//拷贝构造函数
//	Person(const Person &p)
//	{
//		//将传入类所有属性拷贝到此类
//		age = p.age;
//		cout << "Person类的拷贝构造函数的调用" << endl;
//	}
//
//	//2.析构函数清理
//	//没有返回值不写void
//	//函数名和类名相同，在名称前加~
//	//析构函数没有参数，不可以重载
//	//对象在销毁前，会自动调用析构函数，而且只调用一次
//	~Person()
//	{
//		cout << "Person类的析构函数的调用" << endl;
//	}
//	int age;
//};
//
////构造和析构都是必须有的，如果程序员不提供，编译器会进行空实现
//void test01()
//{
//	Person p;//在栈上的数据，test01执行完后，释放这个对象
//}
//
////调用
//void test02()
//{
//	//括号法
//	//Person p1;		//默认构造函数调用
//	//Person p2(10);	//有参构造函数调用
//	//Person p3(p2);	//拷贝构造函数调用
//
//	////注意：调用默认构造函数时不要加（）,因为该行代码编译器会以为时函数声明，不会认为在创造对象
//	//cout << "P2年龄:" << p2.age << endl;
//	//cout << "P3年龄:" << p3.age << endl;
//
//	//显示法
//	Person p1;
//	Person p2 = Person(10);//有参构造
//	Person p3 = Person(p2);//拷贝构造
//
//	Person(10);//匿名对象，当前行执行结束后，系统会立即回收匿名对象
//	//注意：不要用拷贝构造函数初始化匿名对象  编译器会认为在对象声明
//
//
//	//隐式转换法
//	Person p4 = 10;// 相当于Person p4 = Person（10）
//
//}
////int main()
////{
////	test01();
////
////	return 0;
////}
//
//
////拷贝构造函数调用时机
//// 1.使用一个已经创建完毕的对象初始化一个新对象
//// 2.值传递的方式给函数参数传值
//// 3.值方式返回局部对象
///*
//Person dowork()
//{
//	Person p1;
//	cout << (int*)&p1 << endl;
//	return p1;
//}
//void test()
//{
//	Person p = dowork();
//	cout << (int*)&p << endl;
//}
//*/
//
////构造函数调用规则
////如果用户定义有参构造函数 C++不再提供默认无参构造
////如果用户定义拷贝构造函数 C++不再提供其他构造函数
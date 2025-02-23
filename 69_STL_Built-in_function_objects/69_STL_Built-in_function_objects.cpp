﻿// 69_STL_Built-in_function_objects.cpp: 目标的源文件。
// STL内建了一些函数对象
//算术仿函数
//关系仿函数
//逻辑仿函数

//用法：
//这些仿函数所产生的对象，用法和一般函数完全相同
//使用内建函数对象，需要引入头文件 #include<functional>

#include "69_STL_Built-in_function_objects.h"

//算数仿函数
//template<class T> T plus<T>			//加法仿函数
//template<class T> T minus<T>			//减法仿函数
//template<class T> T multiplies<T>		//乘法仿函数
//template<class T> T divides<T>		//除法仿函数
//template<class T> T modulus<T>		//取模仿函数
//template<class T> T negate<T>			//取反仿函数

//negate 一元仿函数 取反
//plus   二元仿函数 加法
void test01()
{
	negate<int> n;
	cout << n(50) << endl;

	plus<int> p;
	cout << p(10, 20) << endl;
}

//关系仿函数
//template<class T> bool equal_to<T>					//等于
//template<class T> bool not_equal_to<T>				//不等于
//template<class T> bool greater<T>						//大于
//template<class T> bool greater_equal<T>				//大于等于
//template<class T> bool less<T>						//小于
//template<class T> bool less_equal<T>					//小于等于
class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//自己实现仿函数
	//sort(v.begin(), v.end(), MyCompare());
	
	//STL内建仿函数 大于仿函数
	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << accumulate(v.begin(), v.end(), 0) << endl;
	fill(v.begin(), v.end(), 99);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//逻辑仿函数
//template<class T> bool logical_and<T>		//逻辑与
//template<class T> bool logical_or<T>		//逻辑或
//template<class T> bool logical_not<T>		//逻辑非
void test03() 
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//逻辑非 将v容器搬运到v2中，并执行逻辑非运算
	vector<bool> v2;

	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());

	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test01();
	test02();
	test03();

	return 0;
}

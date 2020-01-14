// TechniquesCPlus.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include "pch.h"
#include <iostream>
#include <memory>
#include "VirtualConstructor.h"
#include "LimitClassCount.h"
#include "ReferenceCounting.h"
#include "SmartPtr.h"
#include "MyStack.hpp"
#include "accum.hpp"

inline
std::ostream& operator<<(std::ostream &s, const NLComponent &c)
{
	return c.p_stream(s);
}


void displayAll(A* a)
{
	a->display();
}

void CountTest()
{
	//String a = "aaaa";
	//String b = a;

	String a("aaa");

	String b;
	//重载等号
	b = a;

	//重载拷贝构造
	String c = a;
	c = "aa";
	std::cout << std::endl;

	
}

void StackTest()
{
	try
	{
		Stack<int> intStack;
		Stack<float> floatStack;

		intStack.push(7);
		intStack.push(42);

		floatStack.push(7.7);

		floatStack = intStack;

		std::cout << floatStack.top() << std::endl;
		floatStack.pop();
		std::cout << floatStack.top() << std::endl;
		floatStack.pop();
		std::cout << floatStack.top() << std::endl;
		floatStack.pop();
	}
	catch (std::exception const & ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}

	Stack<int, std::vector> vStack;

	vStack.push(42);
	vStack.push(7);
	std::cout << vStack.top() << std::endl;
	vStack.pop();
}

void accumTest()
{
	int num[] = {1,2,3,4,5};
	std::cout<<"the average value of the integer value is "<<accum(&num[0],&num[5]) /5<<std::endl;

	char name[] = "templates";
	int length = sizeof(name) -1;

	std::cout<< "the average value of  the characters in \"" <<name<<"\" is " << accum(&name[0],&name[length]) / length <<std::endl;
	}

int main()
{	
	//StackTest();
	//CountTest();
	accumTest();
    std::cout << "Hello World!"<<std::endl; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

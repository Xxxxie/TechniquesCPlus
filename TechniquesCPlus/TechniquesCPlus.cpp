// TechniquesCPlus.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
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
	//���صȺ�
	b = a;

	//���ؿ�������
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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ������ʾ: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�

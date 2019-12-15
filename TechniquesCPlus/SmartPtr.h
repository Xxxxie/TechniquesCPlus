#pragma once
#include<iostream>




class A
{
public:
	virtual void display()
	{
		std::cout << "class A" << std::endl;
	}

};

class B :public A
{
public:
	void display()
	{
		std::cout << "class B" << std::endl;
	}
};

class C :public A
{
public:
	void display()
	{
		std::cout << "class C" << std::endl;
	}
};

#pragma once

#include <cstddef>
template<class BeingCount>
class Counted
{
public:
	class TooMangObject{};
	static int ObjectCount() { return numObject; }
	
	
protected:
	Counted();
	Counted(const Counted& rhs);
	~Counted() { --numObject; }
private:
	static int numObject;
	//此处所有的类的最大个数为确定值
	static const size_t maxObject = 3;
	void init();
};

class Printer :private Counted<Printer>
{
public:
	static Printer* makePrint();
	static Printer* makePrint(const Printer& rhs);
	~Printer() {};
	using Counted<Printer>::ObjectCount;
	using Counted<Printer>::TooMangObject;
	
private:
	Printer();
	Printer(const Printer& rhs);
};


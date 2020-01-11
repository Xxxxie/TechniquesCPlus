#include "LimitClassCount.h"
#include <iostream>

template<class BeingCount>
Counted<BeingCount>::Counted()
{
	init();
}
template<class BeingCount>
Counted<BeingCount>::Counted(const Counted<BeingCount>& rhs)
{
	init();
}

template<class BeingCount>
void Counted<BeingCount>::init()
{
	if (numObject >= maxObject)
	{
		throw TooMangObject();
	}
	++numObject;
	std::cout << "The number of class is " << numObject << std::endl;
	
}

template<class BeingCount>
int Counted<BeingCount>::numObject = 0;

Printer* Printer::makePrint()
{
	return new Printer();
}

Printer* Printer::makePrint(const Printer& rhs)
{
	return new Printer(rhs);
}

Printer::Printer()
{
	std::cout << "constructor" << std::endl;
}

Printer::Printer(const Printer& rhs)
{
	std::cout << "constructor reference" << std::endl;
}


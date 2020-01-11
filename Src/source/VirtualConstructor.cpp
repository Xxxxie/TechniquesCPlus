#include "VirtualConstructor.h"

void NLComponent::Print()
{
	std::cout << "This is NLComponent." << std::endl;
}

std::ostream& NLComponent::p_stream(std::ostream &out) const
{
	out << "This is NLComponent." << std::endl;
	return out;
}

void TextBolck::Print()
{
	std::cout << "This is TextBlock." << std::endl;
}

std::ostream& TextBolck::p_stream(std::ostream &out) const
{
	out << "This is TextBlock." << std::endl;
	return out;
}

void Graphic::Print()
{
	std::cout << "This is Graphic." << std::endl;
}

std::ostream& Graphic::p_stream(std::ostream &out) const
{
	out << "This is Graphic." << std::endl;
	return out;
}

void NewLetter::add(NLComponent* comp)
{
	components.push_back(comp);
}

void NewLetter::Print()
{
	for (std::vector<NLComponent*>::const_iterator iter =components.begin(); iter != components.end(); ++iter)
	{
		(*iter)->Print();
	}
}

/*
inline
std::ostream& operator<<(std::ostream &s, const NLComponent &c)
{
	return c.p_stream(s);
}
*/

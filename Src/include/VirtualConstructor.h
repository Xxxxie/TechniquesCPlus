#pragma once
#include <vector>
#include <iostream>

// 根据不同的输入构造不同的类型，并存入NewLetter中
class NLComponent
{
public:
	virtual void Print() ;
	virtual std::ostream& p_stream(std::ostream &out) const ;
};

class TextBolck :public NLComponent 
{
public:
	void Print();
	std::ostream& p_stream(std::ostream &out) const;

	
};

class Graphic :public NLComponent
{
	void Print();
	std::ostream& p_stream(std::ostream &out) const;
};

class NewLetter
{
public:
	void add(NLComponent* comp);
	void Print();
private:
	std::vector<NLComponent*> components;
};
#pragma once
#include <vector>
#include <iostream>

// ���ݲ�ͬ�����빹�첻ͬ�����ͣ�������NewLetter��
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
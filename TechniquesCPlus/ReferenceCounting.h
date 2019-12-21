#pragma once

#include <string>

///����ָ��
template <class T>
class RCPtr
{
public:
	RCPtr(T *realPtr = 0);
	RCPtr(const RCPtr &rhs);
	~RCPtr();

	RCPtr & operator=(const RCPtr& rhs);

	T* operator->() const;

	T& operator*() const;
	
private:

	T * pointpee;
	void init();
};


///���ü����Ļ���
class RCObject
{
protected:
	RCObject();
	RCObject(const RCObject &rhs);
	RCObject & operator=(const RCObject & rhs);
	virtual ~RCObject() = 0;
public:
	void addReference();
	void removeReference();
	void makeUnShareable();
	bool isShareable() const;
	bool isShared() const;

private:
	int refCount;
	bool shareable;
};


///��Ҫ���ü�������
//String ������ü���
class String 
{
public:
	
	String(const char* value = 0);
	const char& operator[](int index) const;
	char& operator[](int index);
	String & operator=(const String& rhs);
	String(const String& rhs)
	{
		value = rhs.value;
	}

private:

	struct StringValue:public RCObject
	{
		char* data;
		StringValue(const char* initValue);
		StringValue(const StringValue& rhs);
		void init(const char* initvalue);
		~StringValue();
	};

	RCPtr<StringValue> value;
};

//��չ���ü���

template<class T>
class RCIPtr 
{
public:
	RCIPtr(T* realPtr = 0);
	RCIPtr(const RCIPtr &rhs);
	~RCIPtr();

	RCIPtr & operator=(const RCIPtr &rhs);

	const T* operator->() const;
	T* operator->();

	const T& operator*() const;

	T& operator*();

private:
	struct CountHolder:public RCObject
	{
		T* pointee;
		~CountHolder();
	};

	CountHolder *counter;
	void init();
	void makeCopy();
};


//���һ����ͨ��
class Widget
{
public:
	Widget(int size);
	Widget(const Widget& rhs);
	~Widget();

	Widget& operator=(const Widget& rhs);

	void doThis();

	void showThat() const;

private:
	int value;
};


//������ͨ������ü�����
class RCWidget
{
public:
	RCWidget(int size) :value(new Widget(size)) {}

	void doThis() { value->doThis(); }

	void showThat() const { value->showThat(); }

private:
	RCIPtr<Widget> value;
};
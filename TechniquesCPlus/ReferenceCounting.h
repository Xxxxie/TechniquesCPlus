#pragma once

#include <string>

///智能指针
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


///引用计数的基类
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


///需要引用计数的类
//String 类的引用计数
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

//扩展引用计数

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


//设计一个普通类
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


//对于普通类的引用计数类
class RCWidget
{
public:
	RCWidget(int size) :value(new Widget(size)) {}

	void doThis() { value->doThis(); }

	void showThat() const { value->showThat(); }

private:
	RCIPtr<Widget> value;
};
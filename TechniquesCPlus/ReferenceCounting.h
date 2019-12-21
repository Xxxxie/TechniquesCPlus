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


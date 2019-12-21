#include "ReferenceCounting.h"


template<class T>
void RCPtr<T>::init()
{
	//确保模板类中有这些函数
	if (pointpee == 0) return;
	if (pointpee->isShareable() == false)
	{
		pointpee = new T(*pointpee);
	}

	pointpee->addReference();
}

template<class T>
RCPtr<T>::RCPtr(T *realPtr):pointpee(realPtr)
{
	init();
}

template<class T>
RCPtr<T>::RCPtr(const RCPtr & rhs):pointpee(rhs.pointpee)
{
	
	init();
}

template<class T>
RCPtr<T> & RCPtr<T>::operator=(const RCPtr<T>& rhs)
{
	if (pointpee != rhs.pointpee)
	{
		//确保pointpee不为空
		if (pointpee != nullptr)
			pointpee->removeReference();

		pointpee = rhs.pointpee;
		init();
	}
	return *this;
}

template <class T>
RCPtr<T>::~RCPtr()
{
	if (pointpee) pointpee->removeReference();
}

template <class T>
T* RCPtr<T>::operator->()const { return pointpee; }

template <class T>
T& RCPtr<T>::operator*()const { return *pointpee; }

RCObject::~RCObject() {}
RCObject::RCObject() :refCount(0), shareable(true) {}
RCObject::RCObject(const RCObject &rhs) :refCount(0), shareable(true){}
RCObject& RCObject::operator=(const RCObject &) { return *this; }

void RCObject::addReference()
{
	++refCount;
}

void RCObject::removeReference()
{
	if (--refCount == 0)
	{
		delete this;
	}
}

void RCObject::makeUnShareable()
{
	shareable = false;
}

bool RCObject::isShareable() const
{
	return shareable;
}

bool RCObject::isShared() const
{
	return  refCount>1;
}



String::String(const char* initValue):value(new StringValue(initValue))
{
	
}

const char& String::operator[](int index) const
{
	return value->data[index];
}

char & String::operator[](int index)
{
	if (value->isShareable() == false)
	{
		value = new StringValue(value->data);
	}

	value->makeUnShareable();
	return value->data[index];
}

String::StringValue::StringValue(const StringValue& rhs)
{
	
	init(rhs.data);
}

String::StringValue::StringValue(const char* initValue)
{
	init(initValue);
}


String& String::operator=(const String &rhs)
{
	value = rhs.value;
	return *this;
}


void String::StringValue::init(const char* initvalue)
{
	//initvalue 为空时
	if (initvalue == 0)
	{
		data = nullptr;
	}
	else
	{
		data = new char[strlen(initvalue) + 1];
		strcpy(data, initvalue);
	}
	
}

String::StringValue::~StringValue()
{
	delete[] data;
}

template<class T>
void RCIPtr<T>::init()
{
	if (counter->isShareable() == false)
	{
		T* oldValue = counter->pointee;
		counter = new CountHolder;
		counter->pointee = new T(*oldValue);
	}

	counter->addReference();
}


template<class T>
RCIPtr<T>::RCIPtr(T * realPtr):counter(new CountHolder)
{
	counter->pointee = realPtr;
	init();
}


//此对象的counter与 rhs的相同，直接使用拷贝构造
template<class T>
RCIPtr<T>::RCIPtr(const RCIPtr & rhs):counter(rhs->counter)
{
	init();
}


template<class T>
RCIPtr<T>::~RCIPtr()
{
	//当引用为0时 析构
	counter->removeReference();
}

template<class T>
RCIPtr<T>&  RCIPtr<T>::operator=(const RCIPtr<T> &rhs)
{
	if (counter != rhs.counter)
	{
		counter->removeReference();
		counter = rhs.counter;
		init();
	}

	return *this;
}

template<class T>
const T*  RCIPtr<T>::operator->() const
{
	return counter->pointee;
}

template<class T>
const T& RCIPtr<T>::operator*() const
{
	return *(counter->pointee);
}
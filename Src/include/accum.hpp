#ifndef ACCUM_HPP
#define ACCUM_HPP

#include "accumtraits.hpp"

template <typename T>
inline typename AccumulationTraits<T>::AccT accum(T * beg , T* end)  //typename 说明AccT是一个类型而不是一个成员变量
{
    typedef typename AccumulationTraits<T>::AccT Acct;

    Acct total = AccumulationTraits<T>::zero();

    while(beg != end)
    {
        total +=*beg;
        ++beg;
    }

    return total;
} 


#endif
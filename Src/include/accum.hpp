#ifndef ACCUM_HPP
#define ACCUM_HPP

#include "accumtraits.hpp"

template <typename T,typename AT = AccumulationTraits<T> >
class Accum{
public:
    static typename AT::AccT accum(T const *beg , T const *end)
    {
        typename AT::AccT total = AT::zero();
        while(beg != end)
        {
            total +=*beg;
            ++beg;
        }

        return total;
    }

};



template <typename T>
inline typename AccumulationTraits<T>::AccT accum(T const *beg , T const *end)  //typename 说明AccT是一个类型而不是一个成员变量
{

    return Accum<T>::accum(beg,end);
} 


template <typename Traits, typename T>
inline typename AccumulationTraits<T>::AccT accum(T const *beg, T const *end)
{
    return Accum<T,Traits>::accum(beg,end);
}


#endif
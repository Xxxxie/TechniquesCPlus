

template <typename T>
class AccumulationTraits;


template<>
class AccumulationTraits<char>{
public:
    typedef int AccT;
    static AccT zero()   //静态初始化只能为枚举和int，因此使用函数初始化
    {
        return 0;
    }
};

template<>
class AccumulationTraits<int>{
public:
    typedef long AccT;
    static AccT zero()
    {
        return 0;
    }
};

template<>
class AccumulationTraits<short>{
public:
    typedef int AccT;
    static AccT zero()
    {
        return 0;
    }
};

template<>
class AccumulationTraits<unsigned int>{
public:
    typedef unsigned long AccT;
    static AccT zero()
    {
        return 0;
    }
};

template<>
class AccumulationTraits<float>{
public:
    typedef double AccT;
    static AccT zero()
    {
        return 0;
    }
};
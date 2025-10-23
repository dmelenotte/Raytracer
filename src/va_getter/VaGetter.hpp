#ifndef __VA_GETTER__
    #define __VA_GETTER__

#include <cstddef>
#include <type_traits>

template <class... As> struct Vargs {};

template<class A, class... As>
struct Vargs<A, As...> : Vargs<As...>
{
    Vargs(A arg, As... args) : Vargs<As...>(args...), tail(arg) {}

    A tail;
};

template<std::size_t, class> struct ElemHolder {};

template<class A, class... As>
struct ElemHolder<0, Vargs<A, As...>>
{
    typedef A type;
};

template<std::size_t k, class A, class... As>
struct ElemHolder<k, Vargs<A, As...>>
{
    typedef typename ElemHolder<(k - 1), Vargs<As...>>::type type;
};

template<std::size_t k, class... As>
typename std::enable_if<k == 0, typename ElemHolder<0, Vargs<As...>>::type &>::type
get(Vargs<As...> &arg)
{
    return arg.tail;
}

template<std::size_t k, class A, class... As>
typename std::enable_if<(k != 0), typename ElemHolder<k, Vargs<A, As...>>::type &>::type
get(Vargs<A, As...> &args)
{
    Vargs<As...> &base = args;
    return get<(k - 1)>(base);
}

#endif

//
// Created by Nadezhda Churikova on 2019-03-12.
//

#ifndef PROFILER_RANGE_H
#define PROFILER_RANGE_H

#include <iostream>
#include <vector>
#include <algorithm>

//template <typename T>
//std::vector<T> Range(std::vector<T> const &seq, size_t top)
//{
////    std::vector<T> tmp{seq.begin(), next(seq.begin(), std::min(top, seq.size()))};
//    return {seq.begin(), next(seq.begin(), std::min(top, seq.size()))};
//}

template <typename I>
class IteratorRange
{
public:
    I begin() const
    { return first;}

    I end() const
    { return last;}
    I first, last;
};

template <typename T>
IteratorRange<typename std::vector<T>::iterator> Range(std::vector<T> &v, size_t top)
{
    return {v.begin(), next(v.begin(), std::min(top, v.size()))};
}


#endif //PROFILER_RANGE_H

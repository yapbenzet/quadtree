#include "../include/point.hpp"


template<typename T>
Point<T>::Point() : x{}, y{} {}

template<typename T>
Point<T>::Point(T x, T y) : x{x}, y{y} {}

#ifndef POINT_H
#define POINT_H

template<typename T>
struct Point
{
	T x;
	T y;
	Point();
	Point(T x, T y);
};

#include "../source/point.cpp"
#endif

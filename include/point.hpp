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

template<typename T>
Point<T>::Point() : x{}, y{} {}

template<typename T>
Point<T>::Point(T x, T y) : x{x}, y{y} {}

#endif

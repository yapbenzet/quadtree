#ifndef REGION_H
#define REGION_H

#include "point.h"

template<typename T>
struct Region
{
	Point<T> center;
	T half_size;

	Region();
	Region(double half_size, Point<T> center);
};

template<typename T>
Region<T>::Region() : center{}, half_size{} {}

template<typename T>
Region<T>::Region(Point<T> center, double half_size)
	:center{center}, half_size{half_size} {}

#endif

#ifndef REGION_H
#define REGION_H

#include "point.hpp"
#include <iostream>

template<typename T>
struct Region
{
	Point<T> center;
	T half_size;

	Region();
	Region(T half_size, Point<T> center);

	template<typename S>
	friend std::ostream& operator<<(std::ostream& out, const Region<S>& rhs);

};


#include "../source/region.cpp"
#endif

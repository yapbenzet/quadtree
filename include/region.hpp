#ifndef REGION_H
#define REGION_H

#include "point.hpp"
#include <iostream>

template<typename T>
struct Region
{
	Point<T> center;
	T half_size;

	Region(): center{}, half_size{} {};
	Region(double half_size, Point<T> center):center{center}, half_size{half_size} {};


	friend std::ostream& operator<<(std::ostream& out, const Region<T>& rhs)
	{
		out << "center: " << rhs.center.x << " " << rhs.center.y << "   half size: " << rhs.half_size;
		return out;
	}
};

#endif

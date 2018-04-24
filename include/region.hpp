#ifndef REGION_H
#define REGION_H

#include "point.hpp"

template<typename T>
struct Region
{
	Point<T> center;
	T half_size;

	Region(): center{}, half_size{} {};
	Region(double half_size, Point<T> center):center{center}, half_size{half_size} {};
};
	
#endif

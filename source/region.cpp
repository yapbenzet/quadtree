#include "../include/region.hpp"

template<typename T>
Region<T>::Region() {}

template<typename T>
Region<T>::Region(T half_size, Point<T> center) :center{center}, half_size{half_size} {}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Region<T>& rhs)
{
	out << "center: " << rhs.center.x << " " << rhs.center.y << "   half size: " << rhs.half_size;
	return out;
}
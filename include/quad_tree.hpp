#ifndef quad_tree_h
#define quad_tree_h

#include <iostream>
#include "point.hpp"
#include "region.hpp"
#include "node.hpp"

template<typename scalar>
class quad_tree
{
	Node<scalar>* root;
public:
	quad_tree(const Region<scalar>& region, int bucketsize);

	bool insert(Point<scalar>& point);

	template<typename S>
	friend std::ostream& operator<<(std::ostream& out, quad_tree<S>& rhs);

};

#include "../source/quad_tree.cpp"
#endif

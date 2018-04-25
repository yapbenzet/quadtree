#ifndef QUAD_TREE_NODE
#define QUAD_TREE_NODE

#include <vector>
#include <iostream>
#include "point.hpp"
#include "region.hpp"

template<typename scalar>
class quad_tree;

enum class status : bool
{
	parent,
	leaf
};

template<typename scalar>
class Node
{
public:

	Node<scalar>* child[4];
	Region<scalar> region;
	std::vector<Point<scalar>> points;
    status state;
	int depth;
	static int bucket_size;
	Node(int depth);
	friend class quad_tree<scalar>;
private:
	bool insert(const Point<scalar>& point);
	bool split(const Point<scalar>& point);
	int get_section(const Point<scalar>& point);
	void set_region(const Region<scalar>& parent_reg, int sect);
public:

	template<typename S>
	friend std::ostream& operator<<(std::ostream& out, const Node<S>& rhs);
};

#include "../source/node.cpp"
#endif

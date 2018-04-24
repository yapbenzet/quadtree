#ifndef QUAD_TREE_NODE
#define QUAD_TREE_NODE

#include <array>
#include "point.h"
#include "region.h"

template<typename scalar, int BUCKET_SIZE>
class Node
{
public:
	Node<scalar>* child[4];
	Region<scalar> region;
	std::array<Point<scalar>, BUCKET_SIZE> points;
  status state;

	enum class status
	{
		root,
		parent,
		leaf,
		empty
	};
	Node();
};


#include "node.cpp"
#endif

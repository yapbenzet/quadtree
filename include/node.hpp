#ifndef QUAD_TREE_NODE
#define QUAD_TREE_NODE

#include <array>
#include "point.hpp"
#include "region.hpp"

template<typename scalar, int BUCKET_SIZE>
class quad_tree;

enum class status : bool
{
	parent,
	leaf
};

template<typename scalar, int BUCKET_SIZE>
class Node
{
public:

	Node<scalar, BUCKET_SIZE>* child[4];
	Region<scalar> region;
	std::array<Point<scalar>, BUCKET_SIZE>* points;
    status state;
	int point_count;

	Node();
	friend class quad_tree<scalar,BUCKET_SIZE>;

private:
	bool insert(Point<scalar> point);
	bool split(Point<scalar> point);
	int get_section(Point<scalar> point);

};



template<typename scalar, int BUCKET_SIZE>
Node<scalar,BUCKET_SIZE>::Node():
	child{nullptr,nullptr,nullptr,nullptr}, 
	state(status::leaf), 
	point_count{}, 
	points(new std::array<Point<scalar>,BUCKET_SIZE>) 
{

}


template<typename scalar, int BUCKET_SIZE>
bool Node<scalar,BUCKET_SIZE>::insert(Point<scalar> point)
{
	if(this->state == status::leaf)
	{
		if(point_count != BUCKET_SIZE)
			points[point_count++] = point;
		else
		{
			this->split(point);
		}
	}
	else
	{
		if(int sect = this->get_section(point); child[sect] == nullptr)
			child[sect] = new Node<scalar,BUCKET_SIZE>;
		this->child[this->get_section(point)]->insert(point);
	}
}


template<typename scalar, int BUCKET_SIZE>
int Node<scalar,BUCKET_SIZE>::get_section(Point<scalar> point)
{
	int X = (point.x >= region.center.x) << 1;
	int Y = (point.y >= region.center.y) << 0;
	return (X|Y);
}

template<typename scalar, int BUCKET_SIZE>
bool Node<scalar,BUCKET_SIZE>::split(Point<scalar> point)
{
	for(auto it = points->begin(); it != points->end(); it++)
	{
		this->insert(*it);
	}
	this->state = status::parent;
	delete points;
}

#endif

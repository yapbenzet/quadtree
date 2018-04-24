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
	int point_count;
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
	friend std::ostream& operator<<(std::ostream& out, const Node<scalar>& rhs)
	{
		for (int i = 0; i < rhs.depth; i++)
			out << "  ";

		out << rhs.region << "    point count:" << rhs.point_count << "\n";
		for (int i = 0; i < 4; i++)
			if (rhs.child[i] != nullptr)
				out << *rhs.child[i];
		return out;
	}
};

template<typename scalar>
int Node<scalar>::bucket_size = 5;

template<typename scalar>
Node<scalar>::Node(int depth):
	child{nullptr,nullptr,nullptr,nullptr}, 
	state{status::leaf},
	point_count{},
	depth{depth}
{

}


template<typename scalar>
bool Node<scalar>::insert(const Point<scalar>& point)
{
	if(this->state == status::leaf)
	{
		if (point_count != bucket_size)
		{
			points.push_back(point);
			return true;
		}
		else
		{
			return this->split(point);
		}
	}
	else
	{
		int sect = this->get_section(point);
		if (child[sect] == nullptr)
		{
			child[sect] = new Node<scalar>(this->depth + 1);
			child[sect]->set_region(this->region, sect);
		}
		return child[sect]->insert(point);
	}
}


template<typename scalar>
int Node<scalar>::get_section(const Point<scalar>& point)
{
	int X = (point.x >= region.center.x) << 1;
	int Y = (point.y >= region.center.y) << 0;
	return (X|Y);
}

template<typename scalar>
void Node<scalar>::set_region(const Region<scalar>& parent_reg, int sect)
{
	this->region.half_size = parent_reg.half_size / 2;
	switch (sect)
	{
	case 0:
		this->region.center.x = parent_reg.center.x - this->region.half_size;
		this->region.center.y = parent_reg.center.x - this->region.half_size;
		break;
	case 1:
		this->region.center.x = parent_reg.center.x - this->region.half_size;
		this->region.center.y = parent_reg.center.x + this->region.half_size;
		break;
	case 2:
		this->region.center.x = parent_reg.center.x + this->region.half_size;
		this->region.center.y = parent_reg.center.x - this->region.half_size;
		break;
	case 3:
		this->region.center.x = parent_reg.center.x + this->region.half_size;
		this->region.center.y = parent_reg.center.x + this->region.half_size;
		break;
	}

}

template<typename scalar>
bool Node<scalar>::split(const Point<scalar>& point)
{
	this->state = status::parent;
	for (auto it : points)
	{
		this->insert(it);
	}
	this->insert(point);
	points.clear();
	points.shrink_to_fit();

	return true;
}

#endif

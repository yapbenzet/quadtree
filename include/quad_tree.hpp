#ifndef quad_tree_h
#define quad_tree_h

#include "point.hpp"
#include "region.hpp"
#include "node.hpp"

template<typename scalar, int BUCKET_SIZE>
class quad_tree
{
	Node<scalar,BUCKET_SIZE>* root;

public:
	quad_tree(const Region<scalar>& region);

	bool insert(Point<scalar> point);

};

template<typename scalar, int BUCKET_SIZE>
quad_tree<scalar,BUCKET_SIZE>::quad_tree(const Region<scalar>& region)
{
	this->root = new Node<scalar, BUCKET_SIZE>;
	this->root->region = region;
}

template<typename scalar, int BUCKET_SIZE>
bool quad_tree<scalar,BUCKET_SIZE>::insert(Point<scalar> point)
{

	if(root->state == status::leaf)
	{
		if(root->point_count == BUCKET_SIZE)
		{
			root->split(point);
		}		
		else
		{
			root->points[root->point_count++] = point;
		}
	}
	else
	{
		if(int sect = root->get_section(point); root->child[sect] == nullptr)
			root->child[sect] = new Node<scalar,BUCKET_SIZE>;
		root->insert(point);
	}		
}

#endif

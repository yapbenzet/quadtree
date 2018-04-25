#include "../include/quad_tree.hpp"
template<typename scalar>
quad_tree<scalar>::quad_tree(const Region<scalar>& region, int bucketsize)
{
	this->root = new Node<scalar>(0);
	this->root->region = region;
	Node<scalar>::bucket_size = bucketsize;
}

template<typename scalar>
bool quad_tree<scalar>::insert(Point<scalar>& point)
{
	if(root->state == status::leaf)
	{
		if(root->points.size() == Node<scalar>::bucket_size)
		{
			return root->split(point);
		}		
		else
		{
			 root->points.push_back(point);
			 return true;
		}
	}
	else
	{
		
		if (int sect = root->get_section(point); root->child[sect] == nullptr) 
		{
			root->child[sect] = new Node<scalar>(root->depth + 1);
			root->child[sect]->set_region(root->region, sect);
		}
		return root->insert(point);
	}		
}

template<typename S>
std::ostream& operator<<(std::ostream& out, quad_tree<S>& rhs)
{
	out << *rhs.root;

	for (int i = 0; i < 4; i++)
		if (rhs.root->child[i] != nullptr)
			out << rhs.root->child[i];
	return out;

}

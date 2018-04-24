#ifndef quad_tree_h
#define quad_tree_h

#include "point.h"
#include "region.h"
#include "node.h"

template<typename scalar, int BUCKET_SIZE>
class quad_tree
{
	node<scalar,BUCKET_SIZE>* root;

public:
	quad_tree(const Region<scalar>& region);




};

#include "quad_tree.cpp"
#endif

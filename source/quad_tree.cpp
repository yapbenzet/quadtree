#ifdef quad_tree_h

template<typename scalar, int BUCKET_SIZE>
quad_tree<scalar,BUCKET_SIZE>::quad_tree(const Region<scalar>& region)
{
	root = new node<scalar, BUCKET_SIZE>;
	root->region = region;
}



#endif

#ifdef QUAD_TREE_NODE


template<typename scalar, int BUCKET_SIZE>
Node<scalar, BUCKET_SIZE>::Node()
    :child{nullptr,nullptr,nullptr,nullptr}, state(status::leaf) {}
#endif

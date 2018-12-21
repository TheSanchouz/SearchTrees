#pragma once
#include "AVLNode.h"

template<typename Key, typename Data>
class AVLTree
{
	typedef AVLNode<Key, Data> AVLNode;

private:
	AVLNode *root;

public:
	AVLTree() 
		: root(nullptr) {}
	~AVLTree()
	{
		//delete root;
	}


};

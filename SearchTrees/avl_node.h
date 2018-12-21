#pragma once

template<typename Key, typename Data>
class avl_node
{
private:
	Key key;
	Data data;

	avl_node *leftChild;
	avl_node *rightChild;

public:
	avl_node(Key key, Data data)
		: key(key), data(data), leftChild(nullptr), rightChild(nullptr) {}

	~avl_node()
	{
		delete leftChild;
		delete rightChild;
	}

	Key GetKey() const
	{
		return key;
	}
	Data GetData() const
	{
		return data;
	}

	void SetLeftChild(avl_node *node)
	{
		leftChild = node;
	}
	void SetRightChild(avl_node *node)
	{
		rightChild = node;
	}

	avl_node* GetLeftChild() const
	{
		return leftChild;
	}
	avl_node* GetRightChild() const
	{
		return rightChild;
	}
};


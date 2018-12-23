#pragma once

template<typename Key, typename Data>
class AVLNode
{
private:
	Key key;
	Data data;

	AVLNode *leftChild;
	AVLNode *rightChild;

public:
	unsigned int height;

	AVLNode(Key key, Data data)
		: key(key), data(data), leftChild(nullptr), rightChild(nullptr), height(1) {}

	~AVLNode()
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


	void SetLeftChild(AVLNode *node)
	{
		leftChild = node;
	}
	void SetRightChild(AVLNode *node)
	{
		rightChild = node;
	}

	AVLNode* GetLeftChild() const
	{
		return leftChild;
	}
	AVLNode* GetRightChild() const
	{
		return rightChild;
	}
};


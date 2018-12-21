#pragma once

template<typename Key, typename Data>
class AVLNode
{
private:
	Key key;
	Data data;

	AVLNode *parent;
	AVLNode *leftChild;
	AVLNode *rightChild;

public:
	AVLNode(Key key, Data data)
		: key(key), data(data), parent(nullptr), leftChild(nullptr), rightChild(nullptr) {};
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


	void SetParent(AVLNode *node)
	{
		parent = node;
	}
	void SetLeftChild(AVLNode *node)
	{
		leftChild = node;
	}
	void SetRightChild(AVLNode *node)
	{
		rightChild = node;
	}

	AVLNode* GetParent() const
	{
		return parent;
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
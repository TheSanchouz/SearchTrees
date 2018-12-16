#pragma once

template<typename Key, typename Data>
class SplayNode
{
private:
	Key key;
	Data data;

	SplayNode *parent;
	SplayNode *leftChild;
	SplayNode *rightChild;

public:
	SplayNode(Key key, Data data) : key(key), data(data),
		parent(nullptr), leftChild(nullptr), rightChild(nullptr) 
	{

	}
	~SplayNode()
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

	void SetParent(SplayNode *node)
	{
		parent = node;
	}
	void SetLeftChild(SplayNode *node)
	{
		leftChild = node;
	}
	void SetRightChild(SplayNode *node)
	{
		rightChild = node;
	}

	SplayNode* GetParent() const
	{
		return parent;
	}
	SplayNode* GetLeftChild() const
	{
		return leftChild;
	}
	SplayNode* GetRightChild() const
	{
		return rightChild;

	}

};


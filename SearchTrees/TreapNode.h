#pragma once

template<typename Key, typename Data>
class TreapNode
{
private:
	Key key;
	Data data;
	std::uint64_t priority;

	TreapNode *parent;
	TreapNode *leftChild;
	TreapNode *rightChild;

public:
	TreapNode(Key key, Data data, std::uint64_t priority)
		: key(key), data(data), priority(priority), parent(nullptr), leftChild(nullptr), rightChild(nullptr) {};
	~TreapNode()
	{
		delete leftChild;
		delete rightChild;

		parent = nullptr;
	}


	Key GetKey() const
	{
		return key;
	}
	Data GetData() const
	{
		return data;
	}
	std::uint64_t GetPriority() const
	{
		return priority;
	}


	void SetParent(TreapNode *node)
	{
		parent = node;
	}
	void SetLeftChild(TreapNode *node)
	{
		leftChild = node;
	}
	void SetRightChild(TreapNode *node)
	{
		rightChild = node;
	}

	TreapNode* GetParent() const
	{
		return parent;
	}
	TreapNode* GetLeftChild() const
	{
		return leftChild;
	}
	TreapNode* GetRightChild() const
	{
		return rightChild;

	}

};

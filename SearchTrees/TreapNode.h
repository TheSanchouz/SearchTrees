#pragma once

template<typename Key, typename Data>
class TreapNode
{
private:
	Key key;
	Data data;
	uint64_t priority;

	TreapNode *leftChild;
	TreapNode *rightChild;

public:
	TreapNode(Key key, Data data, uint64_t priority)
		: key(key), data(data), priority(priority), leftChild(nullptr), rightChild(nullptr) {};
	~TreapNode()
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
	std::uint64_t GetPriority() const
	{
		return priority;
	}


	void SetLeftChild(TreapNode *node)
	{
		leftChild = node;
	}
	void SetRightChild(TreapNode *node)
	{
		rightChild = node;
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

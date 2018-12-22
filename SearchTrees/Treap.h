#pragma once
#include <random>
#include <limits>
#include <utility>
#include "TreapNode.h"

template<typename Key, typename Data>
class Treap
{
	typedef TreapNode<Key, Data> TreapNode;
	typedef std::pair<TreapNode*, TreapNode*> pairTreapNode;

private:
	std::random_device random_device;
	std::mt19937 generator;
	std::uniform_int_distribution<uint64_t> distribution;

	TreapNode *root;


	TreapNode* _Search(const Key &key)
	{
		TreapNode *searchedElement = root;

		while (searchedElement != nullptr)
		{
			if (key == searchedElement->GetKey())
			{
				return searchedElement;
			}
			else if (key < searchedElement->GetKey())
			{
				searchedElement = searchedElement->GetLeftChild();
			}
			else if (key > searchedElement->GetKey())
			{
				searchedElement = searchedElement->GetRightChild();
			}
		}

		return nullptr;
	}
	pairTreapNode _Split(TreapNode *root, const Key &key)
	{
		if (root == nullptr)
		{
			return pairTreapNode(nullptr, nullptr);
		}

		if (root->GetKey() < key)
		{
			pairTreapNode splittedNode = _Split(root->GetRightChild(), key);
			root->SetRightChild(splittedNode.first);
			return pairTreapNode(root, splittedNode.second);
		}
		else
		{
			pairTreapNode splittedNode = _Split(root->GetLeftChild(), key);
			root->SetLeftChild(splittedNode.second);
			return pairTreapNode(splittedNode.first, root);
		}
	}
	TreapNode* _Merge(TreapNode *left, TreapNode *right)
	{
		if (left == nullptr) return right;
		if (right == nullptr) return left;

		if (left->GetPriority() > right->GetPriority())
		{
			left->SetRightChild(_Merge(left->GetRightChild(), right));
			return left;
		}
		else
		{
			right->SetLeftChild(_Merge(left, right->GetLeftChild()));
			return right;
		}
	}

	TreapNode* _Insert(TreapNode *root, TreapNode *insertNode)
	{
		if (root == nullptr)
		{
			return insertNode;
		}

		if (root->GetPriority() < insertNode->GetPriority())
		{
			pairTreapNode splittedNode = _Split(root, insertNode->GetKey());
			insertNode->SetLeftChild(splittedNode.first);
			insertNode->SetRightChild(splittedNode.second);

			return insertNode;
		}

		if (root->GetKey() < insertNode->GetKey())
		{
			root->SetRightChild(_Insert(root->GetRightChild(), insertNode));
		}
		else
		{
			root->SetLeftChild(_Insert(root->GetLeftChild(), insertNode));
		}

		return root;
	}
	TreapNode* _Remove(TreapNode *root, const Key &key)
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		if (root->GetKey() == key)
		{
			TreapNode *node = _Merge(root->GetLeftChild(), root->GetRightChild());
			root->SetLeftChild(nullptr);
			root->SetRightChild(nullptr);
			delete root;
			return node;
		}
		else if (root->GetKey() < key)
		{
			root->SetRightChild(_Remove(root->GetRightChild(), key));
		}
		else
		{
			root->SetLeftChild(_Remove(root->GetLeftChild(), key));
		}

		return root;
	}

public:
	Treap()
		: root(nullptr), generator(random_device()), distribution(std::uniform_int_distribution<uint64_t>(1, UINT64_MAX))
	{

	}
	~Treap()
	{
		delete root;
	}

	void Insert(const Key &key, const Data &data)
	{
		uint64_t priority = distribution(generator);

		root = _Insert(root, new TreapNode(key, data, priority));
	}
	void Remove(const Key &key)
	{
		root = _Remove(root, key);
	}
	Data Search(Key key)
	{

	}
	bool Contains(const Key &key)
	{
		return _Search(key) != nullptr;
	}
};
#pragma once
#include <random>
#include <limits>
#include "TreapNode.h"

template<typename Key, typename Data>
class Treap
{
	typedef TreapNode<Key, Data> TreapNode;

private:
	//std::random_device random_device;
	//std::mt19937 generator(random_device());
	//std::uniform_int_distribution<std::uint64_t> distribution(1, std::uint64_t);

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
	void _Split(Key key, Treap &leftTreap, Treap &rightTreap)
	{
		TreapNode *splittedPivot = _Search(key);

		if (splittedPivot != nullptr)
		{
			TreapNode *leftChild = splittedPivot->GetLeftChild();
			TreapNode *rightChild = splittedPivot->GetRightChild();

			if (leftChild != nullptr)
			{
				leftTreap.root = new TreapNode(leftChild->GetKey(), leftChild->GetData(), leftChild->GetPriority());
				leftTreap.root->SetLeftChild(leftChild->GetLeftChild());
				leftTreap.root->SetRightChild(leftChild->GetRightChild());
			}
			else
			{
				leftTreap.root = nullptr;
			}

			if (rightChild != nullptr)
			{
				rightTreap.root = new TreapNode(rightChild->GetKey(), rightChild->GetData(), rightChild->GetPriority());
				rightTreap.root->SetLeftChild(rightChild->GetLeftChild());
				rightTreap.root->SetRightChild(rightChild->GetRightChild());
			}
			else
			{
				rightTreap.root = nullptr;
			}
		}
	}

public:
	Treap()
		: root(nullptr) {}
	~Treap()
	{
		TreapNode *parentCurrent = nullptr;
		TreapNode *current = root;

		while (current != nullptr)
		{
			parentCurrent = current->GetParent();

			if (current->GetLeftChild() != nullptr)
			{
				current = current->GetLeftChild();
			}
			else if (current->GetRightChild() != nullptr)
			{
				current = current->GetRightChild();
			}
			else //нет ни левого ребенка, ни правого
			{
				if (current != root)
				{
					if (parentCurrent->GetLeftChild() == current)
					{
						parentCurrent->SetLeftChild(nullptr);
					}
					else if (parentCurrent->GetRightChild() == current)
					{
						parentCurrent->SetRightChild(nullptr);
					}
				}

				current->SetParent(nullptr);
				delete current;

				current = parentCurrent;
				if (parentCurrent != nullptr)
				{
					parentCurrent = parentCurrent->GetParent();
				}
			}
		}
	}

	void Insert(Key key, Data data, std::uint64_t priority)
	{

	}
	void Remove(Key key)
	{

	}
	Data Search(Key key)
	{

	}
};


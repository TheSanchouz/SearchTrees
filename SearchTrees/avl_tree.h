#pragma once
#include <algorithm>
#include "avl_node.h"

template<typename Key, typename Data>
class avl_tree
{
	typedef avl_node<Key, Data> avl_node;
private:
	avl_node *root;

	unsigned int Height(avl_node *subtree) const
	{
		return (subtree != nullptr) ? 1 + std::max(Height(subtree->GetLeftChild()), Height(subtree->GetRightChild())) : 0;
	}
	int BalanceFactor(avl_node *subtree) const
	{
		return Height(subtree->GetRightChild()) - Height(subtree->GetLeftChild());
	}

	avl_node* RotateLeft(avl_node *subtree)
	{
		avl_node *tmp = subtree->GetRightChild();

		subtree->SetRightChild(tmp->GetLeftChild());
		tmp->SetLeftChild(subtree);

		return tmp;
	}
	avl_node* RotateRight(avl_node *subtree)
	{
		avl_node *tmp = subtree->GetLeftChild();

		subtree->SetLeftChild(tmp->GetRightChild());
		tmp->SetRightChild(subtree);

		return tmp;
	}

	avl_node* Rebalance(avl_node *node)
	{
		int balance = BalanceFactor(node);

		if (balance > 1)
		{
			if (BalanceFactor(node->GetRightChild()) < 0)
				node->SetRightChild(RotateRight(node->GetRightChild()));

			std::cout << "REBALANCE" << std::endl;

			return RotateLeft(node);
		}
		else if (balance < -1)
		{
			if (BalanceFactor(node->GetLeftChild()) > 0)
				node->SetLeftChild(RotateLeft(node->GetLeftChild()));

			std::cout << "REBALANCE" << std::endl;

			return RotateRight(node);
		}

		return node;
	}

	avl_node* Add(avl_node *node, Key key, Data data)
	{
		if (node == nullptr)
		{
			return new avl_node(key, data);
		}
		
		if (key < node->GetKey())
		{
			node->SetLeftChild(Add(node->GetLeftChild(), key, data));
		}
		else if (key > node->GetKey())
		{
			node->SetRightChild(Add(node->GetRightChild(), key, data));
		}

		return Rebalance(node);
	}
	avl_node* FindMin(avl_node *node)
	{
		return node->GetLeftChild() ? FindMin(node->GetLeftChild()) : node;
	}
	avl_node* RemoveMin(avl_node *node)
	{
		if (node->GetLeftChild() == nullptr)
		{
			return node->GetRightChild();
		}

		node->SetLeftChild(RemoveMin(node->GetLeftChild()));

		return Rebalance(node);
	}
	avl_node* Remove(avl_node *node, Key key)
	{
		if (!node)
		{
			return nullptr;
		}

		if (key < node->GetKey())
		{
			node->SetLeftChild(Remove(node->GetLeftChild(), key));
		}
		else if (key > node->GetKey())
		{
			node->SetRightChild(Remove(node->GetRightChild(), key));
		}
		else
		{
			avl_node *left = node->GetLeftChild();
			avl_node *right = node->GetRightChild();

			delete node;

			if (!right) return right;
			avl_node *min = FindMin(right);
			min->SetRightChild(RemoveMin(right));
			min->SetLeftChild(left);

			return Rebalance(min);
		}

		return Rebalance(node);
	}

public:
	avl_tree()
	{
		root = nullptr;
	}
	virtual ~avl_tree()
	{
		delete root;
	}

	void Add(Key key, Data data)
	{
		root = Add(root, key, data);
	}
	void Remove(Key key)
	{
		root = Remove(root, key);
	}

	bool Contains(Key key)
	{
		avl_node *cur = root;

		while (cur != nullptr)
		{
			if (key == cur->GetKey())
			{
				return true;
			}
			else if (key < cur->GetKey())
			{
				cur = cur->GetLeftChild();
			}
			else
			{
				cur = cur->GetRightChild();
			}
		}

		return false;
	}
	avl_node* Find(Key key)
	{
		avl_node *cur = root;

		while (cur != nullptr)
		{
			if (key == cur->GetKey())
			{
				return cur;
			}
			else if (key < cur->GetKey())
			{
				cur = cur->GetLeftChild();
			}
			else
			{
				cur = cur->GetRightChild();
			}
		}

		return nullptr;
	}
	avl_node* Min()
	{
		avl_node *cur = root;

		while (cur->GetLeftChild() != nullptr)
		{
			cur = cur->GetLeftChild();
		}

		return cur;
	}
	avl_node* Max()
	{
		avl_node *cur = root;

		while (cur->GetRightChild() != nullptr)
		{
			cur = cur->GetRightChild();
		}

		return cur;
	}

};
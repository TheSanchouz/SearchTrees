#pragma once
#include <algorithm>
#include "AVLNode.h"

template<typename Key, typename Data>
class AVLTree
{
	typedef AVLNode<Key, Data> AVLNode;

private:
	AVLNode *root;

	//unsigned int _Height(AVLNode *subtree) const
	//{
	//	return (subtree != nullptr) ? 1 + std::max(_Height(subtree->GetLeftChild()), _Height(subtree->GetRightChild())) : 0;
	//}
	unsigned int _Height(AVLNode *subtree) const
	{
		return subtree ? subtree->height : 0;
	}

	int _BalanceFactor(AVLNode *subtree) const
	{
		return  _Height(subtree->GetRightChild()) - _Height(subtree->GetLeftChild());
		//return _Height(subtree->GetRightChild()) - _Height(subtree->GetLeftChild());
	}

	void _FixHeight(AVLNode *subtree)
	{
		unsigned int hl = _Height(subtree->GetLeftChild());
		unsigned int hr = _Height(subtree->GetRightChild());

		subtree->height = std::max(hl, hr) + 1;
	}

	AVLNode* _RotateLeft(AVLNode *subtree)
	{
		AVLNode *tmp = subtree->GetRightChild();

		subtree->SetRightChild(tmp->GetLeftChild());
		tmp->SetLeftChild(subtree);

		_FixHeight(tmp);
		_FixHeight(subtree);

		return tmp;
	}
	AVLNode* _RotateRight(AVLNode *subtree)
	{
		AVLNode *tmp = subtree->GetLeftChild();

		subtree->SetLeftChild(tmp->GetRightChild());
		tmp->SetRightChild(subtree);

		_FixHeight(tmp);
		_FixHeight(subtree);

		return tmp;
	}

	AVLNode* _Rebalance(AVLNode *node)
	{
		int balance = _BalanceFactor(node);

		_FixHeight(node);
		if (balance > 1)
		{
			if (_BalanceFactor(node->GetRightChild()) < 0)
				node->SetRightChild(_RotateRight(node->GetRightChild()));

			return _RotateLeft(node);
		}
		else if (balance < -1)
		{
			if (_BalanceFactor(node->GetLeftChild()) > 0)
				node->SetLeftChild(_RotateLeft(node->GetLeftChild()));

			return _RotateRight(node);
		}

		return node;
	}

	AVLNode* _Insert(AVLNode *node, Key key, Data data)
	{
		if (node == nullptr)
		{
			return new AVLNode(key, data);
		}

		if (key < node->GetKey())
		{
			node->SetLeftChild(_Insert(node->GetLeftChild(), key, data));
		}
		else if (key > node->GetKey())
		{
			node->SetRightChild(_Insert(node->GetRightChild(), key, data));
		}

		return _Rebalance(node);
	}
	AVLNode* _FindMin(AVLNode *node)
	{
		return node->GetLeftChild() ? _FindMin(node->GetLeftChild()) : node;
	}
	AVLNode* _RemoveMin(AVLNode *node)
	{
		if (node->GetLeftChild() == nullptr)
		{
			return node->GetRightChild();
		}

		node->SetLeftChild(_RemoveMin(node->GetLeftChild()));

		return _Rebalance(node);
	}
	AVLNode* _Remove(AVLNode *node, Key key)
	{
		if (!node)
		{
			return nullptr;
		}

		if (key < node->GetKey())
		{
			node->SetLeftChild(_Remove(node->GetLeftChild(), key));
		}
		else if (key > node->GetKey())
		{
			node->SetRightChild(_Remove(node->GetRightChild(), key));
		}
		else
		{
			AVLNode *left = node->GetLeftChild();
			AVLNode *right = node->GetRightChild();

			node->SetLeftChild(nullptr);
			node->SetRightChild(nullptr);

			delete node;

			if (!right) return left;
			AVLNode *min = _FindMin(right);
			min->SetRightChild(_RemoveMin(right));
			min->SetLeftChild(left);

			return _Rebalance(min);
		}

		return _Rebalance(node);
	}

public:
	AVLTree()
		: root(nullptr) {}
	~AVLTree()
	{
		delete root;
	}

	void Insert(Key key, Data data)
	{
		root = _Insert(root, key, data);
	}
	void Remove(Key key)
	{
		root = _Remove(root, key);
	}

	bool Contains(Key key)
	{
		AVLNode *cur = root;

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
	AVLNode* Search(Key key)
	{
		AVLNode *cur = root;

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

};
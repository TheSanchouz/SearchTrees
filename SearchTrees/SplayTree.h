#pragma once
#include "SplayNode.h"

template<typename Key, typename Data>
class SplayTree
{
	typedef SplayNode<Key, Data> SplayNode;

private:
	SplayNode *root;

	SplayNode* _Successor(SplayNode *localRoot) const
	{
		SplayNode *successor = localRoot;

		if (successor->GetRightChild() != nullptr)
		{
			successor = _Minimum(successor->GetRightChild());
		}
		else
		{
			while (successor != root || successor != successor->GetParent()->GetLeftChild())
			{
				successor = successor->GetParent();
			}
		}

		return successor;
	}
	SplayNode* _Predecessor(SplayNode *localRoot) const
	{
		SplayNode *predecessor = localRoot;

		if (predecessor->GetLeftChild() != nullptr)
		{
			predecessor = _Maximum(predecessor->GetLeftChild());
		}
		else
		{
			while (predecessor != root || predecessor != predecessor->GetParent()->GetRightChild())
			{
				predecessor = predecessor->GetParent();
			}
		}

		return predecessor;
	}

	SplayNode* _Minimum(SplayNode *localRoot) const
	{
		SplayNode *minimum = localRoot;

		while (minimum->GetLeftChild() != nullptr)
		{
			minimum = minimum->GetLeftChild();
		}

		return minimum;
	}
	SplayNode* _Maximum(SplayNode *localRoot) const
	{
		SplayNode *maximum = localRoot;

		while (maximum->GetRightChild() != nullptr)
		{
			maximum = maximum->GetRightChild();
		}

		return maximum;
	}

	SplayNode* _Search(const Key &key)
	{
		SplayNode *searchedElement = root;

		while (searchedElement != nullptr)
		{
			if (key == searchedElement->GetKey())
			{
				_Splay(searchedElement);
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

	void _LeftRotate(SplayNode *localRoot)
	{
		SplayNode *rightChild = localRoot->GetRightChild();

		if (rightChild != nullptr)
		{
			localRoot->SetRightChild(rightChild->GetLeftChild());

			if (rightChild->GetLeftChild() != nullptr)
			{
				rightChild->GetLeftChild()->SetParent(localRoot);
			}
		}

		_Transplant(localRoot, rightChild);

		if (rightChild != nullptr)
		{
			rightChild->SetLeftChild(localRoot);
			rightChild->GetLeftChild()->SetParent(rightChild);
		}
	}
	void _RightRotate(SplayNode *localRoot) 
	{
		SplayNode *leftChild = localRoot->GetLeftChild();

		if (leftChild != nullptr)
		{
			localRoot->SetLeftChild(leftChild->GetRightChild());

			if (leftChild->GetRightChild() != nullptr)
			{
				leftChild->GetRightChild()->SetParent(localRoot);
			}
		}

		_Transplant(localRoot, leftChild);

		if (leftChild != nullptr)
		{
			leftChild->SetRightChild(localRoot);
			leftChild->GetRightChild()->SetParent(leftChild);
		}
	}

	void _Transplant(SplayNode *localParent, SplayNode *localChild)
	{
		if (localParent->GetParent() == nullptr)
		{ 
			root = localChild;
		}
		else if (localParent == localParent->GetParent()->GetLeftChild())
		{
			localParent->GetParent()->SetLeftChild(localChild);
		}
		else if (localParent == localParent->GetParent()->GetRightChild())
		{
			localParent->GetParent()->SetRightChild(localChild);
		}

		if (localChild != nullptr)
		{
			localChild->SetParent(localParent->GetParent());
		}
	}

	void _Splay(SplayNode *pivotElement) 
	{
		while (pivotElement != root)
		{
			if (pivotElement->GetParent() == root)
			{
				if (pivotElement == pivotElement->GetParent()->GetLeftChild())
				{
					_RightRotate(pivotElement->GetParent());
				}
				else if (pivotElement == pivotElement->GetParent()->GetRightChild())
				{
					_LeftRotate(pivotElement->GetParent());
				}
			}
			else
			{
				// Zig-Zig step
				if (pivotElement == pivotElement->GetParent()->GetLeftChild() &&
					pivotElement->GetParent() == pivotElement->GetParent()->GetParent()->GetLeftChild())
				{
					_RightRotate(pivotElement->GetParent()->GetParent());
					_RightRotate(pivotElement->GetParent());
				}
				else if (pivotElement == pivotElement->GetParent()->GetRightChild() &&
					pivotElement->GetParent() == pivotElement->GetParent()->GetParent()->GetRightChild())
				{
					_LeftRotate(pivotElement->GetParent()->GetParent());
					_LeftRotate(pivotElement->GetParent());
				}
				// Zig-Zag step
				else if (pivotElement == pivotElement->GetParent()->GetRightChild() &&
					pivotElement->GetParent() == pivotElement->GetParent()->GetParent()->GetLeftChild())
				{
					_LeftRotate(pivotElement->GetParent());
					//_RightRotate(pivotElement->GetParent()->GetParent());
					_RightRotate(pivotElement->GetParent());
				}
				else if (pivotElement == pivotElement->GetParent()->GetLeftChild() &&
					pivotElement->GetParent() == pivotElement->GetParent()->GetParent()->GetRightChild())
				{
					_RightRotate(pivotElement->GetParent());
					//_LeftRotate(pivotElement->GetParent()->GetParent());
					_LeftRotate(pivotElement->GetParent());
				}
			}
		}
	}

public:
	SplayTree()
		: root(nullptr) {}
	~SplayTree() 
	{
		SplayNode *parentCurrent = nullptr;
		SplayNode *current = root;

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

	void Insert(const Key &key, const Data &data)
	{
		SplayNode *preInsertPlace = nullptr;
		SplayNode *insertPlace = root;

		while (insertPlace != nullptr)
		{
			preInsertPlace = insertPlace;

			if (key < insertPlace->GetKey())
			{
				insertPlace = insertPlace->GetLeftChild();
			}
			else if (key > insertPlace->GetKey())
			{
				insertPlace = insertPlace->GetRightChild();
			}
		}

		SplayNode *insertElement = new SplayNode(key, data);
		insertElement->SetParent(preInsertPlace);

		if (preInsertPlace == nullptr)
		{
			root = insertElement;
		}
		else if (insertElement->GetKey() < preInsertPlace->GetKey())
		{
			preInsertPlace->SetLeftChild(insertElement);
		}
		else if (insertElement->GetKey() > preInsertPlace->GetKey())
		{
			preInsertPlace->SetRightChild(insertElement);
		}

		_Splay(insertElement);
	}
	void Remove(const Key &key)
	{
		SplayNode *removeElement = _Search(key);

		if (removeElement != nullptr)
		{
			if (removeElement->GetLeftChild() == nullptr)
			{
				_Transplant(removeElement, removeElement->GetRightChild());
			}
			else if (removeElement->GetRightChild() == nullptr)
			{
				_Transplant(removeElement, removeElement->GetLeftChild());
			}
			else
			{
				SplayNode *newLocalRoot = _Minimum(removeElement->GetRightChild());

				if (newLocalRoot->GetParent() != removeElement)
				{
					_Transplant(newLocalRoot, newLocalRoot->GetRightChild());

					newLocalRoot->SetRightChild(removeElement->GetRightChild());
					newLocalRoot->GetRightChild()->SetParent(newLocalRoot);
				}

				_Transplant(removeElement, newLocalRoot);

				newLocalRoot->SetLeftChild(removeElement->GetLeftChild());
				newLocalRoot->GetLeftChild()->SetParent(newLocalRoot);
			}

			delete removeElement;
		}

		std::cout << root << std::endl;
	}
	Data Search(const Key &key)
	{
		SplayNode *searchedElement = _Search(key);

		return (searchedElement != nullptr) ? searchedElement->GetData() : NULL;
	}

	bool Contains(const Key &key)
	{
		return _Search(key) != nullptr;
	}
	bool Empty() const
	{
		return (root == nullptr);
	}

	Data Successor(const Key &key)
	{
		SplayNode *successor = _Successor(_Search(key));

		return (successor != nullptr) ? successor->GetData() : NULL;
	}
	Data Predecessor(const Key &key)
	{
		SplayNode *predecessor = _Predecessor(_Search(key));

		return (predecessor != nullptr) ? predecessor->GetData() : NULL;
	}

};

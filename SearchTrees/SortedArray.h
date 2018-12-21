#pragma once
#include <algorithm>
#include <vector>
#include "AssociativePair.h"

template<class Key, class Value>
class SortedArray
{
	typedef AssociativePair<Key, Value> AssociativePair;
private:
	size_t size;
	size_t count;
	bool isSorted;
	std::vector<AssociativePair> pairs;


	void _Sort()
	{
		if (isSorted == false)
		{
			std::sort(pairs.begin(), pairs.end(),
				[](AssociativePair &a, AssociativePair &b)
			{
				return a.GetKey() < b.GetKey();
			}
			);
			isSorted = true;
		}
	}
	size_t _BinarySearch(const Key &key)
	{
		_Sort();

		size_t l = -1;
		size_t start = 0;
		size_t finish = count - 1;
		size_t middle = (start + finish) / 2;

		while ((l == -1) && (start <= finish) && (start != middle))
		{
			middle = (start + finish) / 2;

			AssociativePair middleElement = pairs[middle];

			if (key == middleElement.GetKey())
				l = middle;
			if (key < middleElement.GetKey())
				finish = middle - 1;
			if (key > middleElement.GetKey())
				start = middle + 1;
		}

		return l;
	}

public:
	SortedArray(size_t _size = 0)
	{
		size = _size;
		count = 0;
		isSorted = true;

		pairs.reserve(size);
	}
	SortedArray(const SortedArray &src)
	{
		size = src.size;
		count = src.count;
		isSorted = true;

		pairs.reserve(size);
		for (size_t i = 0; i < count; i++)
		{
			pairs[i] = src.pairs[i];
		}
	}
	SortedArray& operator=(const SortedArray &src)
	{
		if (size != src.size)
		{
			pairs.clear();

			size = src.size;
			pairs.reserve(size);
		}

		count = src.count;
		isSorted = true;
		for (size_t i = 0; i < count; i++)
		{
			pairs[i] = src.pairs[i];
		}

		return *this;
	}
	~SortedArray() 
	{

	}

	bool IsFull()
	{
		return (count == size);
	}
	bool IsEmpty()
	{
		return (count == 0);
	}

	void Insert(const Key &key, Value value)
	{
		if (!IsFull())
		{
			AssociativePair insertElement(key, value);
			pairs.push_back(insertElement);
			count++;

			isSorted = false;
		}
	}
	Value Search(const Key &key)
	{
		size_t index = _BinarySearch(key);

		return (index != 1) ? pairs[index] : Value(NULL);
	}
	void Remove(const Key &key)
	{
		size_t index = _BinarySearch(key);

		if (index != -1)
		{
			pairs.erase(pairs.begin() + index);
			count--;
		}
	}
	bool Contains(const Key &key)
	{
		return (_BinarySearch(key) != -1);
	}
};
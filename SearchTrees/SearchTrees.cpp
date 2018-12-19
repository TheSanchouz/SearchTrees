// SearchTrees.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

#include "pch.h"
#include <iostream>
#include <string>
#include <list>
#include <random>
#include "avl_tree.h"
#include "SplayTree.h"

using namespace std;

int main()
{
	random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<int> distribution(-10000, 10000);

	//avl_tree<int, int> avl_tree;

	//int t;

	//for (int i = 0; i < 100; i++)
	//{
	//	int key = distribution(generator);
	//	int data = distribution(generator);

	//	if (i == 20) t = key;
	//	cout << "key & data = " << key << " & " << data << endl;
	//	avl_tree.Add(key, data);
	//}

	//cout << "Min = " << avl_tree.Min()->GetKey() << endl;
	//cout << "Max = " << avl_tree.Max()->GetKey() << endl;
	//cout << "Find = " << avl_tree.Find(t)->GetKey() << endl;
	//cout << "To delete = " << t << endl;
	//avl_tree.Remove(t);

	//avl_tree.Add(100, 100);
	//avl_tree.Add(88, 100);
	//avl_tree.Add(77, 100);

	SplayTree<int, int> splay_tree;
	const int SIZE = 100;
	int *arr = new int[SIZE];
	
	bool alreadyThere;
	for (int i = 0; i < SIZE; )
	{
		alreadyThere = false;
		int newRanomValue = distribution(generator);

		for (int j = 0; j < i; j++)
		{
			if (arr[j] == newRanomValue)
			{
				alreadyThere = true;
				break;
			}
		}
		if (!alreadyThere)
		{
			arr[i] = newRanomValue;
			i++;
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		int data = distribution(generator);

		cout << i << " key & data = " << arr[i] << " & " << data << endl;
		splay_tree.Insert(arr[i], data);
	}

	for (int i = 0; i < SIZE; i++)
	{
		cout << splay_tree.Contains(arr[i]) << " Search " << arr[i] << " has = " << splay_tree.Search(arr[i]) << endl;
	}

	for (int i = 0; i < SIZE; i++)
	{
		int key = (i + 5) % SIZE;

		cout << key << " to delete with key = " << arr[key] << endl;
		splay_tree.Remove(arr[key]);
	}

	//for (int i = 0; i < 100000; i++)
	//{
	//	int key = distribution(generator);

	//	cout << splay_tree.Contains(key) << " Search " << key << " has = " << splay_tree.Search(key) << endl;
	//}

	//cout << "Elem with key " << arr[100] << " = " << splay_tree.Search(arr[100]) << endl;

	cout << "Splay Tree correct" << endl;

	//_CrtDumpMemoryLeaks();

	return 0;
}

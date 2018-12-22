// SearchTrees.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <random>
#include <map>
#include <chrono>
#include "avl_tree.h"
#include "Treap.h"
#include "SplayTree.h"
#include "SortedArray.h"

using namespace std;

//vector<int> FillRandomNumbers(int &size)
//{
//	vector<int> result(size);
//
//	bool alreadyThere;
//	for (int i = 0; i < size; )
//	{
//		alreadyThere = false;
//		int newRanomValue = distribution(generator);
//
//		for (int j = 0; j < i; j++)
//		{
//			if (result[j] == newRanomValue)
//			{
//				alreadyThere = true;
//				break;
//			}
//		}
//		if (!alreadyThere)
//		{
//			result[i] = newRanomValue;
//			i++;
//		}
//	}
//}


int main()
{
	random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<int> distribution(-10000000, 10000000);

	vector<int> keys_int;
	vector<string> keys_string;


	avl_tree	<int, int> avl_tree_int;
	Treap		<int, int> treap_int;
	SplayTree	<int, int> splay_tree_int;
	map			<int, int> red_black_tree_int;
	SortedArray	<int, int> sorted_array_int;

	avl_tree	<string, int> avl_tree_string;
	Treap		<string, int> treap_string;
	SplayTree	<string, int> splay_tree_string;
	map			<string, int> red_black_tree_string;
	SortedArray	<string, int> sorted_array_string;


	const int SIZE = 100000;
	for (int i = 0; i < SIZE; i++)
	{
		int key = distribution(generator);
		int data = distribution(generator);

		treap_int.Insert(key, data);
	}

	for (int i = 0; i < SIZE; i++)
	{
		int key = distribution(generator);

		if (treap_int.Contains(key))
		{
			cout << "key = " << key << " in treap will be deleted" << endl;
		}

		treap_int.Remove(key);
	}


	return 0;
}
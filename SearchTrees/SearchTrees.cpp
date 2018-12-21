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
//			if (arr[j] == newRanomValue)
//			{
//				alreadyThere = true;
//				break;
//			}
//		}
//		if (!alreadyThere)
//		{
//			arr[i] = newRanomValue;
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


	const int SIZE = 1000;
	sorted_array_int = SortedArray<int, int>(SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		int key = distribution(generator);
		int value = distribution(generator);

		sorted_array_int.Insert(key, value);
	}

	auto start = chrono::steady_clock::now();
	for (int i = 0; i < SIZE * 100; i++)
	{
		int key = distribution(generator);
		
		if (sorted_array_int.Contains(key))
		{
			sorted_array_int.Remove(key);

			cout << "key = " << key << " find" << endl;
		}
	}
	auto end = chrono::steady_clock::now();
	cout << chrono::duration<double, milli>(end - start).count() << endl;

	return 0;
}

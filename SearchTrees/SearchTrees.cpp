// SearchTrees.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include <iterator>

#include "generatorURN.h"

#include "AVLTree.h"
#include "Treap.h"
#include "SplayTree.h"
#include <map>
#include "SortedArray.h"

using namespace std;


int main()
{
	std::random_device random_device;
	std::mt19937 generator(random_device());

	const int LOWER_BOUND		= 100000;	// 100 000
	const int UPPER_BOUND		= 1000000;	// 1 000 000
	const int STEP_ITERATION	= 100000;	// 100 000


	//vector<int>			unique_keys_int32	= FillUniqueRandomNumbersINT32(UPPER_BOUND, generator);
	//std::cout << "Creation a unique vector INT32  finished" << endl;
	//std::ofstream int32_file("./keys_int32.txt");
	//std::ostream_iterator<int> iter_int32(int32_file, "\n");
	//std::copy(unique_keys_int32.begin(), unique_keys_int32.end(), iter_int32);

	//vector<uint64_t>	unique_keys_uint64	= FillUniqueRandomNumbersUINT64(UPPER_BOUND, generator);
	//std::cout << "Creation a unique vector UINT64 finished" << endl;
	//std::ofstream uint64_file("./keys_uint64.txt");
	//std::ostream_iterator<uint64_t> iter_uint64(uint64_file, "\n");
	//std::copy(unique_keys_uint64.begin(), unique_keys_uint64.end(), iter_uint64);

	//vector<string>		unique_keys_string	= FillUniqueRandomNumbersSTRING(UPPER_BOUND, generator);
	//std::cout << "Creation a unique vector STRING finished" << endl;
	//std::ofstream string_file("./keys_string.txt");
	//std::ostream_iterator<string> iter_string(string_file, "\n");
	//std::copy(unique_keys_string.begin(), unique_keys_string.end(), iter_string);


	vector<int>			unique_keys_int32;
	unique_keys_int32.reserve(UPPER_BOUND);
	std::ifstream input_int32("./keys_int32.txt");
	if (input_int32)
	{
		int key;

		while (input_int32 >> key)
		{
			unique_keys_int32.push_back(key);
		}
	}

	vector<uint64_t>	unique_keys_uint64;
	unique_keys_uint64.reserve(UPPER_BOUND);
	std::ifstream input_uint64("./keys_uint64.txt");
	if (input_uint64)
	{
		unsigned long long key;

		while (input_uint64 >> key)
		{
			unique_keys_uint64.push_back(key);
		}
	}

	vector<string>		unique_keys_string;
	unique_keys_string.reserve(UPPER_BOUND);
	std::ifstream input_string("./keys_string.txt");
	if (input_string)
	{
		string key;

		while (input_string >> key)
		{
			unique_keys_string.push_back(key);
		}
	}

	//////////////////////////////////////////////
	//////////////////////////////////////////////
	AVLTree		<int, int>				avl_tree_int32;
	AVLTree		<uint64_t, uint64_t>	avl_tree_uint64;
	AVLTree		<string, int>			avl_tree_string;

	Treap		<int, int>				treap_int32;
	Treap		<uint64_t, uint64_t>	treap_uint64;
	Treap		<string, int>			treap_string;

	SplayTree	<int, int>				splay_tree_int32;
	SplayTree	<uint64_t, uint64_t>	splay_tree_uint64;
	SplayTree	<string, int>			splay_tree_string;

	map			<int, int>				red_black_tree_int32;
	map			<uint64_t, uint64_t>	red_black_tree_uint64;
	map			<string, int>			red_black_tree_string;

	SortedArray	<int, int>				sorted_array_int32;
	SortedArray	<uint64_t, uint64_t>	sorted_array_uint64;
	SortedArray	<string, int>			sorted_array_string;
	//////////////////////////////////////////////
	//////////////////////////////////////////////

	std::cout.setf(std::ios::fixed);
	std::cout.precision(10);

	std::cout << "AVL TREE" << endl;
	for (int cur_count = LOWER_BOUND; cur_count <= UPPER_BOUND; cur_count += STEP_ITERATION)
	{
		avl_tree_int32 = AVLTree<int, int>();
		std::cout << "CURRENT SIZE " << cur_count << endl;

		std::cout << "TIME INSERT INT32" << endl;
		auto start = chrono::steady_clock::now();
		for (int i = 0; i < cur_count; i++)
		{
			//avl_tree_int32.Insert(unique_keys_int32[i], i);
			avl_tree_int32.Insert(distributionINT32(generator), i);
		}
		auto end = chrono::steady_clock::now();

		std::cout << chrono::duration<double>(end - start).count() << endl;

		std::cout << "TIME SEARCH INT32" << endl;
		start = chrono::steady_clock::now();
		for (int i = 0; i < cur_count; i++)
		{
			//avl_tree_int32.Contains(unique_keys_int32[rand() % cur_count]);
			avl_tree_int32.Contains(distributionINT32(generator));
		}
		end = chrono::steady_clock::now();
		std::cout << chrono::duration<double>(end - start).count() << endl;

		std::cout << "TIME REMOVE INT32" << endl;
		start = chrono::steady_clock::now();
		for (int i = 0; i < cur_count; i++)
		{
			//avl_tree_int32.Remove(unique_keys_int32[rand() % cur_count]);
			avl_tree_int32.Remove(distributionINT32(generator));
		}
		end = chrono::steady_clock::now();
		std::cout << chrono::duration<double>(end - start).count() << endl;
	}
	for (int cur_count = LOWER_BOUND; cur_count <= UPPER_BOUND; cur_count += STEP_ITERATION)
	{
		avl_tree_uint64 = AVLTree<uint64_t, uint64_t>();
		std::cout << "CURRENT SIZE " << cur_count << endl;

		std::cout << "TIME INSERT UINT64" << endl;
		auto start = chrono::steady_clock::now();
		for (int i = 0; i < cur_count; i++)
		{
			avl_tree_uint64.Insert(unique_keys_uint64[i], i);
		}
		auto end = chrono::steady_clock::now();

		std::cout << chrono::duration<double>(end - start).count() << endl;

		std::cout << "TIME SEARCH UINT64" << endl;
		start = chrono::steady_clock::now();
		for (int i = 0; i < cur_count; i++)
		{
			avl_tree_uint64.Contains(unique_keys_uint64[rand() % cur_count]);
		}
		end = chrono::steady_clock::now();
		std::cout << chrono::duration<double>(end - start).count() << endl;

		std::cout << "TIME REMOVE UINT64" << endl;
		start = chrono::steady_clock::now();
		for (int i = 0; i < cur_count; i++)
		{
			avl_tree_uint64.Remove(unique_keys_uint64[rand() % cur_count]);
		}
		end = chrono::steady_clock::now();
		std::cout << chrono::duration<double>(end - start).count() << endl;
	}
	for (int cur_count = LOWER_BOUND; cur_count <= UPPER_BOUND; cur_count += STEP_ITERATION)
	{
		avl_tree_string = AVLTree<string, int>();
		std::cout << "CURRENT SIZE " << cur_count << endl;

		std::cout << "TIME INSERT STRING" << endl;
		auto start = chrono::steady_clock::now();
		for (int i = 0; i < cur_count; i++)
		{
			avl_tree_string.Insert(unique_keys_string[i], i);
		}
		auto end = chrono::steady_clock::now();

		std::cout << chrono::duration<double>(end - start).count() << endl;

		std::cout << "TIME SEARCH STRING" << endl;
		start = chrono::steady_clock::now();
		for (int i = 0; i < cur_count; i++)
		{
			avl_tree_string.Contains(unique_keys_string[rand() % cur_count]);
		}
		end = chrono::steady_clock::now();
		std::cout << chrono::duration<double>(end - start).count() << endl;

		std::cout << "TIME REMOVE STRING" << endl;
		start = chrono::steady_clock::now();
		for (int i = 0; i < cur_count; i++)
		{
			avl_tree_string.Remove(unique_keys_string[rand() % cur_count]);
		}
		end = chrono::steady_clock::now();
		std::cout << chrono::duration<double>(end - start).count() << endl;
	}
	std::cout << endl;

	//////////////////////////////////////////

	//std::cout << "TREAP" << endl;
	//for (int cur_count = LOWER_BOUND; cur_count <= UPPER_BOUND; cur_count += STEP_ITERATION)
	//{
	//	treap_int32 = Treap<int, int>();
	//	std::cout << "CURRENT SIZE " << cur_count << endl;

	//	std::cout << "TIME INSERT INT32" << endl;
	//	auto start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		treap_int32.Insert(unique_keys_int32[i], i);
	//		//treap_int32.Insert(distributionINT32(generator), i);
	//	}
	//	auto end = chrono::steady_clock::now();

	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//	std::cout << "TIME SEARCH INT32" << endl;
	//	start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		treap_int32.Contains(unique_keys_int32[rand() % cur_count]);
	//		//treap_int32.Contains(distributionINT32(generator));
	//	}
	//	end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//	std::cout << "TIME REMOVE INT32" << endl;
	//	start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		treap_int32.Remove(unique_keys_int32[rand() % cur_count]);
	//		//treap_int32.Remove(distributionINT32(generator));
	//	}
	//	end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;
	//}
	//for (int cur_count = LOWER_BOUND; cur_count <= UPPER_BOUND; cur_count += STEP_ITERATION)
	//{
	//	treap_uint64 = Treap<uint64_t, uint64_t>();
	//	std::cout << "CURRENT SIZE " << cur_count << endl;

	//	std::cout << "TIME INSERT UINT64" << endl;
	//	auto start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		treap_uint64.Insert(unique_keys_uint64[i], i);
	//		//treap_uint64.Insert(distributionUINT64(generator), i);
	//	}
	//	auto end = chrono::steady_clock::now();

	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//	std::cout << "TIME SEARCH UINT64" << endl;
	//	start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		treap_uint64.Contains(unique_keys_uint64[rand() % cur_count]);
	//		//treap_uint64.Contains(distributionUINT64(generator));
	//	}
	//	end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//	std::cout << "TIME REMOVE UINT64" << endl;
	//	start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		treap_uint64.Remove(unique_keys_uint64[rand() % cur_count]);
	//		//treap_uint64.Remove(distributionUINT64(generator));
	//	}
	//	end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;
	//}
	//for (int cur_count = LOWER_BOUND; cur_count <= UPPER_BOUND; cur_count += STEP_ITERATION)
	//{
	//	treap_string = Treap<string, int>();
	//	std::cout << "CURRENT SIZE " << cur_count << endl;

	//	std::cout << "TIME INSERT STRING" << endl;
	//	auto start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		treap_string.Insert(unique_keys_string[i], i);
	//		//treap_string.Insert(GenerateRandomString(distributionSTRING(generator)), i);
	//	}
	//	auto end = chrono::steady_clock::now();

	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//	std::cout << "TIME SEARCH STRING" << endl;
	//	start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		treap_string.Contains(unique_keys_string[rand() % cur_count]);
	//		//treap_string.Contains(GenerateRandomString(distributionSTRING(generator)));
	//	}
	//	end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//	std::cout << "TIME REMOVE STRING" << endl;
	//	start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		treap_string.Remove(unique_keys_string[rand() % cur_count]);
	//		//treap_string.Remove(GenerateRandomString(distributionSTRING(generator)));
	//	}
	//	end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;
	//}
	//std::cout << endl;

	/////////////////////////////////////////////////

	//std::cout << "SPLAY TREE" << endl;
	//for (int cur_count = LOWER_BOUND; cur_count <= UPPER_BOUND; cur_count += STEP_ITERATION)
	//{
	//	splay_tree_int32 = SplayTree<int, int>();
	//	std::cout << "CURRENT SIZE " << cur_count << endl;

	//	std::cout << "TIME INSERT INT32" << endl;
	//	auto start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		splay_tree_int32.Insert(unique_keys_int32[i], i);
	//		//splay_tree_int32.Insert(distributionINT32(generator), i);
	//	}
	//	auto end = chrono::steady_clock::now();

	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//	std::cout << "TIME SEARCH INT32" << endl;
	//	start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		splay_tree_int32.Contains(unique_keys_int32[rand() % cur_count]);
	//		//splay_tree_int32.Contains(distributionINT32(generator));
	//	}
	//	end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//	std::cout << "TIME REMOVE INT32" << endl;
	//	start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		splay_tree_int32.Remove(unique_keys_int32[rand() % cur_count]);
	//		//splay_tree_int32.Remove(distributionINT32(generator));
	//	}
	//	end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;
	//}
	//for (int cur_count = LOWER_BOUND; cur_count <= UPPER_BOUND; cur_count += STEP_ITERATION)
	//{
	//	splay_tree_uint64 = SplayTree<uint64_t, uint64_t>();
	//	std::cout << "CURRENT SIZE " << cur_count << endl;

	//	std::cout << "TIME INSERT UINT64" << endl;
	//	auto start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		splay_tree_uint64.Insert(unique_keys_uint64[i], i);
	//		//splay_tree_uint64.Insert(distributionUINT64(generator), i);
	//	}
	//	auto end = chrono::steady_clock::now();

	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//	std::cout << "TIME SEARCH UINT64" << endl;
	//	start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		splay_tree_uint64.Contains(unique_keys_uint64[rand() % cur_count]);
	//		//splay_tree_uint64.Contains(distributionUINT64(generator));
	//	}
	//	end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//	std::cout << "TIME REMOVE UINT64" << endl;
	//	start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		splay_tree_uint64.Remove(unique_keys_uint64[rand() % cur_count]);
	//		//splay_tree_uint64.Remove(distributionUINT64(generator));
	//	}
	//	end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;
	//}
	//for (int cur_count = LOWER_BOUND; cur_count <= UPPER_BOUND; cur_count += STEP_ITERATION)
	//{
	//	splay_tree_string = SplayTree<string, int>();
	//	std::cout << "CURRENT SIZE " << cur_count << endl;

	//	std::cout << "TIME INSERT STRING" << endl;
	//	auto start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		splay_tree_string.Insert(unique_keys_string[i], i);
	//		//splay_tree_string.Insert(GenerateRandomString(distributionSTRING(generator)), i);
	//	}
	//	auto end = chrono::steady_clock::now();

	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//	std::cout << "TIME SEARCH STRING" << endl;
	//	start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		splay_tree_string.Contains(unique_keys_string[rand() % cur_count]);
	//		//splay_tree_string.Contains(GenerateRandomString(distributionSTRING(generator)));
	//	}
	//	end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//	std::cout << "TIME REMOVE STRING" << endl;
	//	start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		splay_tree_string.Remove(unique_keys_string[rand() % cur_count]);
	//		//splay_tree_string.Remove(GenerateRandomString(distributionSTRING(generator)));
	//	}
	//	end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;
	//}
	//std::cout << endl;

	///////////////////////////////////////////////

	//std::cout << "RED-BLACK TREE" << endl;
	//for (int cur_count = LOWER_BOUND; cur_count <= UPPER_BOUND; cur_count += STEP_ITERATION)
	//{
	//	red_black_tree_int32 = map<int, int>();
	//	std::cout << "CURRENT SIZE " << cur_count << endl;

	//	std::cout << "TIME INSERT INT32" << endl;
	//	auto start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		red_black_tree_int32.insert({ unique_keys_int32[i], i });
	//	}
	//	auto end = chrono::steady_clock::now();

	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//	std::cout << "TIME SEARCH INT32" << endl;
	//	start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		red_black_tree_int32.find(unique_keys_int32[rand() % cur_count]);
	//	}
	//	end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//	std::cout << "TIME REMOVE INT32" << endl;
	//	start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		red_black_tree_int32.erase(unique_keys_int32[rand() % cur_count]);
	//	}
	//	end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;
	//}
	//for (int cur_count = LOWER_BOUND; cur_count <= UPPER_BOUND; cur_count += STEP_ITERATION)
	//{
	//	red_black_tree_uint64 = map<uint64_t, uint64_t>();
	//	std::cout << "CURRENT SIZE " << cur_count << endl;

	//	std::cout << "TIME INSERT UINT64" << endl;
	//	auto start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		red_black_tree_uint64.insert({ unique_keys_uint64[i], (uint64_t)i });
	//	}
	//	auto end = chrono::steady_clock::now();

	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//	std::cout << "TIME SEARCH UINT64" << endl;
	//	start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		red_black_tree_uint64.find(unique_keys_uint64[rand() % cur_count]);
	//	}
	//	end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//	std::cout << "TIME REMOVE UINT64" << endl;
	//	start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		red_black_tree_uint64.erase(unique_keys_uint64[rand() % cur_count]);
	//	}
	//	end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;
	//}
	//for (int cur_count = LOWER_BOUND; cur_count <= UPPER_BOUND; cur_count += STEP_ITERATION)
	//{
	//	red_black_tree_string = map<string, int>();
	//	std::cout << "CURRENT SIZE " << cur_count << endl;

	//	std::cout << "TIME INSERT STRING" << endl;
	//	auto start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		red_black_tree_string.insert({ unique_keys_string[i], i });
	//	}
	//	auto end = chrono::steady_clock::now();

	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//	std::cout << "TIME SEARCH STRING" << endl;
	//	start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		red_black_tree_string.find(unique_keys_string[rand() % cur_count]);
	//	}
	//	end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//	std::cout << "TIME REMOVE STRING" << endl;
	//	start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		red_black_tree_string.erase(unique_keys_string[rand() % cur_count]);
	//	}
	//	end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;
	//}
	//std::cout << endl;

	//////////////////////////////////////////////

	//std::cout << "SORTED ARRAY" << endl;
	//for (int cur_count = LOWER_BOUND; cur_count <= UPPER_BOUND; cur_count += STEP_ITERATION)
	//{
	//	sorted_array_int32 = SortedArray<int, int>();
	//	std::cout << "CURRENT SIZE " << cur_count << endl;

	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		sorted_array_int32.Insert(unique_keys_int32[i], i);
	//	}

	//	std::cout << "TIME SEARCH INT32" << endl;
	//	auto start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		sorted_array_int32.Contains(unique_keys_int32[rand() % cur_count]);
	//	}
	//	auto end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;

	//}
	//for (int cur_count = LOWER_BOUND; cur_count <= UPPER_BOUND; cur_count += STEP_ITERATION)
	//{
	//	sorted_array_uint64 = SortedArray<uint64_t, uint64_t>();
	//	std::cout << "CURRENT SIZE " << cur_count << endl;

	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		sorted_array_uint64.Insert(unique_keys_uint64[i], i);
	//	}

	//	std::cout << "TIME SEARCH UINT64" << endl;
	//	auto start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		sorted_array_uint64.Contains(unique_keys_uint64[rand() % cur_count]);
	//	}
	//	auto end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;
	//}
	//for (int cur_count = LOWER_BOUND; cur_count <= UPPER_BOUND; cur_count += STEP_ITERATION)
	//{
	//	sorted_array_string = SortedArray<string, int>();
	//	std::cout << "CURRENT SIZE " << cur_count << endl;

	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		sorted_array_string.Insert(unique_keys_string[i], i);
	//	}

	//	std::cout << "TIME SEARCH STRING" << endl;
	//	auto start = chrono::steady_clock::now();
	//	for (int i = 0; i < cur_count; i++)
	//	{
	//		sorted_array_string.Contains(unique_keys_string[rand() % cur_count]);
	//	}
	//	auto end = chrono::steady_clock::now();
	//	std::cout << chrono::duration<double>(end - start).count() << endl;
	//}

	//std::cout << endl;

	return 0;
}
#pragma once
#include <random>
#include <string>
#include <vector>

std::uniform_int_distribution<int> distributionINT32(-10000000, 10000000);
std::uniform_int_distribution<uint64_t> distributionUINT64(0, 10000000000);
std::uniform_int_distribution<int> distributionSTRING(3, 12);

std::string GenerateRandomString(size_t length)
{
	auto randchar = []() -> char
	{
		const char alphanum[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";

		const size_t max_index = (sizeof(alphanum) - 1);
		return alphanum[rand() % max_index];
	};

	std::string str(length, 0);
	std::generate_n(str.begin(), length, randchar);

	return str;
}

std::vector<int> FillUniqueRandomNumbersINT32(size_t size, std::mt19937 generator)
{	
	std::vector<int> result(size);

	bool alreadyThere;
	for (int i = 0; i < size; )
	{
		alreadyThere = false;
		int newRandomValue = distributionINT32(generator);

		for (int j = 0; j < i; j++)
		{
			if (result[j] == newRandomValue)
			{
				alreadyThere = true;
				break;
			}
		}
		if (!alreadyThere)
		{
			result[i] = newRandomValue;
			i++;
		}
	}

	return result;
}
std::vector<uint64_t> FillUniqueRandomNumbersUINT64(size_t size, std::mt19937 generator)
{
	std::vector<uint64_t> result(size);

	bool alreadyThere;
	for (int i = 0; i < size; )
	{
		alreadyThere = false;
		uint64_t newRandomValue = distributionUINT64(generator);

		for (int j = 0; j < i; j++)
		{
			if (result[j] == newRandomValue)
			{
				alreadyThere = true;
				break;
			}
		}
		if (!alreadyThere)
		{
			result[i] = newRandomValue;
			i++;
		}
	}

	return result;
}
std::vector<std::string> FillUniqueRandomNumbersSTRING(size_t size, std::mt19937 generator)
{
	std::vector<std::string> result(size);

	bool alreadyThere;
	for (int i = 0; i < size; )
	{
		alreadyThere = false;
		int length = distributionSTRING(generator);
		std::string str = GenerateRandomString(length);

		for (int j = 0; j < i; j++)
		{
			if (result[j] == str)
			{
				alreadyThere = true;
				break;
			}
		}
		if (!alreadyThere)
		{
			result[i] = str;
			i++;
		}
	}

	return result;
}
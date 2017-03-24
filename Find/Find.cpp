// Find.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	vector<int> v{ 2,4,6,6,1,3,-2,0,11,2,3,2,4,4,2,4 };
	string s{ "Hello! I am finding you." };

	auto result = find(begin(v), end(v), 0);
	int lookUp = *result;

	//lookUp = count_if(result, end(v), [](auto elem) {return elem == elem; });
	result = find(result, end(v), 2);
	if (result != end(v))
	{
		lookUp = *result;
	}

	auto letter = find(begin(s),end(s),'a');

	char a = *letter;

	result = find_if(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
	lookUp = *result;

	result = find_if_not(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
	lookUp = *result;

	vector<int> primes{ 2,3,5,7,11,13 };

	result = find_first_of(begin(v), end(v), begin(primes), end(primes));
	lookUp = *result;

	vector<int> subsequence{2,4};

	result = search(begin(v), end(v), begin(subsequence), end(subsequence));
	lookUp = *result;
	result++; result++;
	lookUp = *result;

	string am = "am";
	letter = search(begin(s), end(s), begin(am),end(am));
	a = *letter;
	letter++; letter++;
	a = *letter;

	result = find_end(begin(v),end(v), begin(subsequence), end(subsequence));
	result++; result++;
	if (result != end(v))
	{
		lookUp = *result;
	}

	result = search_n(begin(v),end(v),2,4);
	result--;
	lookUp = *result;

	result = adjacent_find(begin(v), end(v));
	lookUp = *result;
	result++;
	lookUp = *result;

	return 0;
}


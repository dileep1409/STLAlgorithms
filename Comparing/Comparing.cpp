// Comparing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

int main()
{
	vector<int> a{ 1,2,3,4,5 };
	vector<int> b{ 1,2,0,5,6 };

	bool same = a.size() == b.size();

	/*for (int i = 0; i < a.size() && same; i++)
	{
		if (a[i] != b[i])
		{
			same = false;
		}
	}*/

	same = equal(begin(a), end(a), begin(b), end(b)); 

	auto firstchange = mismatch(begin(a), end(a), begin(b)); //mismatch only worked with same sizes of a and b
	int first = *(firstchange.first);
	int second = *(firstchange.second);
	auto distance = firstchange.first - begin(a);

	int total  = 0;

	for (int i : a)
	{
		total += i;
	}

	total = accumulate(begin(a), end(a), 0);
	total = accumulate(begin(a), end(a), 0,
		[](int total, int i) {if (i % 2 == 0) return total + i; return total; });

	total = accumulate(begin(a), end(a), 1,
		[](int total, int i) {return total*i; });

	vector<string> words{ "one","two","three" };

	auto allwords = accumulate(begin(words), end(words), string{});
	int length = allwords.size();
	allwords = accumulate(begin(words), end(words), string{ "Words:" },
		[](string s, string i) {return s + " " + i; });
	length = allwords.size();

	string s = accumulate(begin(a), end(a), string{ "Number are : " },
		[](string ss, int ii) {return ss + " " + to_string(ii); }); //const ref string preferable in both cases

	b = a;

	for (auto i = begin(b); i != end(b); i++)
	{
		*i = 0;
	}

	for (auto &i : b)
	{
		i = 1;
	}

	for_each(begin(b), end(b), [](int& elem) {elem = 2; });

	b = a;
	auto firstthree = find(begin(b), end(b), 3);
	for_each(firstthree, end(b), [](int &elem) {elem = 0; });

    return 0;
}


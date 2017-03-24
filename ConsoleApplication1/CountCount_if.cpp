// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main()
{
	vector<int> v = {1,2,3,4,5,2,5,7,5};
	const int target = 5;
	int fives = 0;
	fives = count(v.begin(), v.end(), target);
	fives = count(begin(v), end(v), target);

	int odds = 0;
	for (auto elem : v)
	{
		if (elem % 2 != 0)
		{
			odds++;
		}
	}

	odds = count_if(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });

	map<int, int> monthlengths{ {1,31},{2,28}, {3,31},{4,30},{5,31},{6,30},{7,31},{ 8,31 },{ 9,30 },{ 10,31 },{ 11,30 },{12,31} };

	int longmonths = count_if(begin(monthlengths), end(monthlengths), [](auto elem) {return elem.second == 31; });

	bool allof, anyof, noneof;

	allof = (odds == v.size());
	noneof = (odds == 0);
	anyof = (odds > 0);

	allof = all_of(begin(v), end(v),
		[](auto elem) {return elem % 2 != 0; });
	noneof = none_of(begin(v), end(v),
		[](auto elem) {return elem % 2 != 0; });
	anyof = any_of(begin(v), end(v),
		[](auto elem) {return elem % 2 != 0; });
    return 0;
}


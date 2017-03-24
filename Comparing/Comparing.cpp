// Comparing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
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

	auto firstchange = mismatch(begin(a), end(a), begin(b));
	int first = *(firstchange.first);
	int second = *(firstchange.second);


    return 0;
}


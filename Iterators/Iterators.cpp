// Iterators.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<vector>
#include<deque>
#include<algorithm>
#include<iterator>
#include<numeric>
#include<array>
using namespace std;

int main()
{
	vector<int> v1(10);
	fill(begin(v1), end(v1), 1);
	fill_n(begin(v1), 6, 2);
	iota(begin(v1), end(v1), 1);

	vector<int> v2;
	fill_n(back_inserter(v2), 6, 2);
	generate_n(back_inserter(v2), 10, [n = 0]()mutable{return n++; });

	deque<int> q3;
	fill_n(back_inserter(q3), 6, 2);
	generate_n(front_inserter(q3), 10, [n = 0]()mutable{return n++; });

	v2.clear();
	transform(begin(v1), end(v1), back_inserter(v2),
		[](int elem) {return elem *= 2; });

	vector<int> v3{ 3,6,1,0,-2,5 };
	vector<int> v5;
	copy_if(begin(v3), end(v3), back_inserter(v5),
		[](int elem) { return elem%2; });

	v3[3] = -2;
	vector<int> v6;
	unique_copy(begin(v3), end(v3), back_inserter(v6));

	string sentence = "Hello, World!";
	string reverse;
	reverse_copy(begin(sentence), end(sentence), back_inserter(reverse));

	v2.clear();
	copy(rbegin(v1), rend(v1), back_inserter(v2));

	v1[5] = 2;
	auto two = find(begin(v1), end(v1), 2);
	auto distance = two - begin(v1);
	two++;

	auto rtwo = find(rbegin(v1), rend(v1), 2);
	distance = rtwo - rbegin(v1);
	rtwo++;

	auto three = find(begin(v1), end(v1), 3);
	bool firsthalf = (three - begin(v1)) < (end(v1) - three);

	auto nine = find(begin(v1), end(v1), 9);
	firsthalf = (nine - begin(v1)) < (end(v1) - nine);

	array<const int, 5> a = { 3,1,6,0,2 };
	auto it = begin(a);
	it++;
	int i = *it;
	//*it = 7;

	//vector<const int> v;

	it = find(begin(a), end(a), 1);
	it++;
	//it = cbegin(ca);

	auto it2 = begin(v2);
	it2++;
	*it2 = 7;

	auto it3 = cbegin(v2);
	it3++;
	//*it3 = 7;

    return 0;
}


// Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include "Employee.h"
#include <random>

using namespace std;


int main()
{
	vector<int> v{4,1,0,1,-2,3,0,0,-9,1,-1,7,-6};
	auto v2 = v;
	sort(begin(v2), end(v2));
	sort(begin(v2), end(v2), [](auto elem1, auto elem2) {return elem1 > elem2; });
	sort(begin(v2), end(v2), [](auto elem1, auto elem2) {return abs(elem1) > abs(elem2); });

	vector<Employee> staff{
		{"Dileep","Godithi",1000},
		{"Venkatesh","Rayala",2000},
		{"Sneha","Annam",1000},
		{"Indra","Chalavadi",3000},
		{"Nooo","Oneee",500},
		{"Arya","Stark",2000}

	};

	//sort(begin(staff), end(staff));  do not work unless < overloaded
	sort(begin(staff), end(staff), [](Employee e1, Employee e2) {return e1.getSalary() < e2.getSalary(); });
	sort(begin(staff), end(staff), [](Employee e1, Employee e2) {return e1.getSortingName() < e2.getSortingName(); });
	sort(begin(staff), end(staff), [](Employee e1, Employee e2) {return e1.getSortingName() < e2.getSortingName(); });

	stable_sort(begin(staff), end(staff), [](Employee e1, Employee e2) {return e1.getSortingName() < e2.getSortingName(); });

	auto sorted = is_sorted(begin(v2), end(v2));
	sorted = is_sorted(begin(v2), end(v2), [](int elem1, int elem2) {return abs(elem1) > abs(elem2); });

	int high = *max_element(begin(v), end(v));
	int low = *min_element(begin(v), end(v));

	sort(begin(v2), end(v2));

	low = *begin(v2);
	high = *(end(v2) - 1);

	int positive = *upper_bound(begin(v2), end(v2),0);
	positive = *lower_bound(begin(v2), end(v2), 0);

	sort(begin(staff), end(staff), [](Employee e1, Employee e2) {return e1.getSortingName() < e2.getSortingName(); });

	auto p = lower_bound(begin(staff), end(staff), "Godithi, Dileep",
		[](Employee e1, string n) {return e1.getSortingName() < n; });

	int salary = p->getSalary();

	random_device randomdevice;
	mt19937 generator(randomdevice());

	shuffle(begin(v2), end(v2), generator);

	partial_sort(begin(v2), find(begin(v2),end(v2),3),end(v2));

	int until = *is_sorted_until(begin(v2), end(v2));

	vector<int> v3(3);
	partial_sort_copy(begin(v), end(v), begin(v3), end(v3));

	v2 = { 1,5,4,2,9,7,3,8,2 };
	int nth = *(begin(v2) + 4);
	nth_element(begin(v2), begin(v2) + 4, end(v2));
	nth = *(begin(v2) + 4);
	int dummy = 0;

    return 0;
}
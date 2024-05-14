#include <iostream>
#include <ctime>
#include <set>

using namespace std;

int main() {
	srand(time(NULL));

	set<int> myset = { 9,1 };

	myset.insert(10);
	myset.insert(5);
	myset.insert(20);
	myset.insert(7);
	myset.insert(3);

	myset.insert(7);
	myset.insert(7);
	myset.insert(7);

	for (auto el : myset) {
		cout << el << '\t';
	}
	cout << '\n';

	for (int i = 0; i < 10; ++i) {
		myset.insert(rand() % 30);
	}

	for (auto el : myset) {
		cout << el << '\t';
	}
	cout << '\n';


	
	set<int> myset2 = { 15,5,25,4,-7 };

	// ---------------------------------------------------

	multiset<int> mymset = { 15,5,25,4,-7,0 };

	mymset.insert(5);
	mymset.insert(5);
	mymset.insert(5);

	cout << "\n\n\n";
	for (auto el : mymset) {
		cout << el << '\t';
	}
	cout << '\n';

	auto it1 = mymset.lower_bound(5);
	auto it2 = mymset.upper_bound(5);
	auto it3 = mymset.equal_range(5);

	cout << *it1 << ' ' << *it2 << '\n';
	cout << *it3.first << ' ' << *it3.second << '\n';



	return 0;
}

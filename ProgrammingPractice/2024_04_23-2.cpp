#include <iostream>

#include <list>
#include <iterator>

using namespace std;

int main() {
	list<int> mylist = { 50, 20,30,20,20 };
	mylist.push_back(100);
	mylist.push_front(10);

	auto it = mylist.begin();
	cout << *it << "\n\n";

	for (auto i = mylist.begin(); i != mylist.end(); ++i) {
		cout << *i << '\t';
	}
	cout << '\n';

	for (auto el : mylist) cout << el << '\t';
	cout << '\n';

	cout << "pop: ";
	mylist.pop_back();
	mylist.pop_front();
	for (auto el : mylist) cout << el << '\t';
	cout << '\n';

	cout << "unique: ";
	mylist.unique();
	for (auto el : mylist) cout << el << '\t';
	cout << '\n';

	cout << "reverse: ";
	mylist.reverse();
	for (auto el : mylist) cout << el << '\t';
	cout << '\n';

	cout << "insert: ";
	it = mylist.begin();
	advance(it, 2);
	mylist.insert(it, 55);
	for (auto el : mylist) cout << el << '\t';
	cout << '\n';

	cout << "remove: ";
	mylist.remove(55);
	for (auto el : mylist) cout << el << '\t';
	cout << '\n';

	cout << "assign1: ";
	mylist.assign(3, 1000);
	for (auto el : mylist) cout << el << '\t';
	cout << '\n';
	cout << "assign2: ";
	list<int> list2 = { 1,2,3,4 };
	mylist.assign(list2.begin(), list2.end());
	for (auto el : mylist) cout << el << '\t';
	cout << '\n';


	return 0;
}

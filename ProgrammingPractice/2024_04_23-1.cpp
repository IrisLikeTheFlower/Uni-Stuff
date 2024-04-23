#include <iostream>

#include <vector>
#include <iterator>

using namespace std;

int main() {
	vector<int> v1 = { 4,7,1,6,9 };
	vector<int>::iterator it;
	// auto it;

	it = v1.begin();

	cout << *it << '\n';

	for (auto i = v1.begin(); i != v1.end(); ++i) {
		cout << *i << '\t';
	}
	cout << '\n';

	cout << "Reverce: ";
	for (vector<int>::reverse_iterator i = v1.rbegin(); i != v1.rend(); ++i) {
		cout << *i << '\t';
	}
	cout << '\n';

	cout << "Advance: ";
	it = v1.begin();
	cout << *(it + 2) << '\t';
	advance(it, 2);
	cout << *it << '\n';

	cout << "Incert: ";
	it = v1.begin();
	v1.insert(it, 100);
	for (vector<int>::iterator i = v1.begin(); i != v1.end(); ++i) {
		cout << *i << '\t';
	}
	cout << '\n';

	cout << "Erase1: ";
	it = v1.begin();
	v1.erase(it);
	for (vector<int>::iterator i = v1.begin(); i != v1.end(); ++i) {
		cout << *i << '\t';
	}
	cout << '\n';

	cout << "Erase2: ";
	it = v1.begin();
	v1.erase(it, it + 2);
	for (vector<int>::iterator i = v1.begin(); i != v1.end(); ++i) {
		cout << *i << '\t';
	}
	cout << '\n';

	return 0;
}

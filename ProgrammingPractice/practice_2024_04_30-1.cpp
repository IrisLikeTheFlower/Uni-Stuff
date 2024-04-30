#include <iostream>

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool pred(int a, int b) {
	return a > b;
}

struct Student {
	string name;
	double mark;

	Student(string n, double m) : name(n), mark(m) {}

	friend ostream& operator<<(ostream& out, const Student& st) {
		cout << st.name << ": " << st.mark << '\n';
		return out;
	}
};

int main() {
	vector<int> v = { 1,9,4,2,7,6,8,5,3 };
	for (auto el : v) {
		cout << el << ' ';
	}
	cout << '\n';

	sort(v.begin(), v.end());
	for (auto el : v) {
		cout << el << ' ';
	}
	cout << '\n';

	sort(v.begin(), v.end(), pred);
	for (auto el : v) {
		cout << el << ' ';
	}
	cout << '\n';

	sort(v.begin(), v.end(), [](int a, int b) {return a > b; });
	for (auto el : v) {
		cout << el << ' ';
	}
	cout << '\n';

	cout << '\n';

	vector<Student> gr = { Student("Iris", 3), Student("Taras", 5), Student("Andriy", 4.5) };
	for (auto el : gr) {
		cout << el;
	}
	cout << '\n';

	sort(gr.begin(), gr.end(), [](const Student& a, const Student& b) {return a.mark > b.mark; });
	for (auto el : gr) {
		cout << el;
	}
	cout << '\n';

	sort(gr.begin(), gr.end(), [](const Student& a, const Student& b) {return a.name < b.name; });
	for (auto el : gr) {
		cout << el;
	}
	cout << '\n';

	cout << '\n';

	cout << count_if(v.begin(), v.end(), [](int a) {return a % 2 == 0; }) << '\n';
	cout << count_if(gr.begin(), gr.end(), [](Student a) { return a.mark > 4; }) << '\n';


	vector<Student> gr2;
	/*copy(gr.begin(), gr.end(), back_inserter(gr2));
	for (auto el : gr2) {
		cout << el;
	}
	cout << '\n';*/

	/*copy(gr.begin(), gr.end(), [](const Student& st) { return st.mark > 4; });
	for (auto el : gr2) {
		cout << el;
	}
	cout << '\n';*/

	auto it1 = find(v.begin(), v.end(), 5);
	if (it1 == v.end()) cout << '-';
	else cout << '+';
	cout << '\n';

	auto it2 = find_if(v.begin(), v.end(), [](int a) { return a % 2 == 0; });
	if (it1 == v.end()) cout << '-';
	else cout << '+';
	cout << '\n';

	auto it3 = min_element(v.begin(), v.end());
	cout << *it3 << '\n';

	auto rez = minmax_element(v.begin(), v.end());
	cout << *(rez.first) << ' ' << *(rez.second) << '\n';

	
	return 0;
}

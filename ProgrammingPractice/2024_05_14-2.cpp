#include <iostream>
#include <ctime>
#include <string>
#include <map>

using namespace std;

int main() {
	srand(time(NULL));

	map<int, string> mymap;

	mymap.insert(make_pair(2, "milk"));
	mymap.insert(pair<int, string>(1, "bread"));
	mymap.emplace(3, "fish");
	mymap.emplace(10, "sugar");
	mymap.emplace(10, "spice");

	for (auto i = mymap.begin(); i != mymap.end(); ++i) {
		cout << (*i).first << ' ' << i->second << '\n';
	}
	cout << '\n';

	auto it = mymap.find(3);

	if (it != mymap.end()) {
		cout << it->first << ' ' << it->second << '\n';
	}
	cout << '\n';

	cout << mymap[10] << '\n';
	mymap[10] = "salt";
	cout << mymap[10] << '\n';
	mymap[15] = "juice";
	cout << mymap[15] << '\n';
	mymap.at(10) = "pepper";
	cout << mymap.at(10) << '\n';

	try {
		mymap.at(20) = "water";
	}
	catch (const exception& ex){
		cout << ex.what() << "\n\n";
	}

	cout << "\n\n";

	// ------------------------------------------

	multimap<string, int> mymmap;

	mymmap.emplace("Olga", 5);
	mymmap.emplace("Olga", 4);
	mymmap.emplace("Nazar", 3);
	mymmap.emplace("Oleg", 5);

	for (auto el : mymmap) {
		cout << el.first << ' ' << el.second << '\n';
	}

	cout << "\n\n";



	return 0;
}

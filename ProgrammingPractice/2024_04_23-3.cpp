#include <iostream>

#include <vector>
#include <list>
#include <iterator>
#include <string>

using namespace std;

bool isPalindrome(string line) {
	int size = line.size();
	bool result = true;

	for (int i = 0; i < size; ++i) {
		if (line[i] != line[size - i - 1]) {
			result = false;
		}
	}

	return result;
}

int main() {
	string inp;
	vector<string> vect;

	while (true) {
		getline(cin, inp);
		
		if (inp.empty()) {
			break;
		}

		vect.push_back(inp);
	}

	for (auto el : vect) {
		if (isPalindrome(el)) {
			cout <<el << '\n';
		}
	}

	return 0;
}

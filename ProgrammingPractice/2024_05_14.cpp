#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
	ifstream inf("Text.txt");

	map<int, int> text;

	string word;

	while (inf >> word) {
		for (int i = 0, len = word.size(); i < len; i++) {
			if (ispunct(word[i])) {
				word.erase(i--, 1);
				len = word.size();
			}
		}

		int len = word.size();

		auto it = text.find(len);

		if (it != text.end()) {
			text[len] += 1;
		}
		else {
			text.emplace(len, 1);
		}

	}


	for (auto i = text.begin(); i != text.end(); ++i) {
		cout << i->first << " - " << i->second << "\n";
	}
	cout << '\n';


	int all_leters = 0;
	int all_words = 0;

	for (auto el : text) {
		all_leters += el.first * el.second;
		all_words += el.second;
	}


	cout << "There are " << all_leters << " leters in the text;\n\n";
	cout << "There are " << all_words << " words in the text;\n\n";

  
	return 0;
}

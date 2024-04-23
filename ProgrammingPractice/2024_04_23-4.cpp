#include <iostream>

#include <string>
#include <vector>
#include <iterator>

using namespace std;

struct Movie {
	string name;
	double rating;
	Movie(string n, double r) : name(n), rating(r) {}
};

bool isSorted(vector<Movie> vect) {
	bool result = true;
	for (int i = 0; i < vect.size()-1; ++i) {
		if (vect[i].rating < vect[i+1].rating) {
			result = false;
		}
	}
	return result;
}

void sortbyrating(vector<Movie>& vect) {
	Movie temp("", 0);
	while (!isSorted (vect)) {
		for (int i = 0; i < vect.size() - 1; ++i) {
			if (vect[i].rating < vect[i + 1].rating) {
				temp = vect[i];
				vect[i] = vect[i + 1];
				vect[i + 1] = temp;
			}
		}
	}
}

int minratingindex(vector<Movie> vect) {
	int min = 0;
	for (int i = 0; i < vect.size(); ++i) {
		if (vect[i].rating < vect[min].rating) {
			min = i;
		}
	}
	return min;
}

int main() {
	vector<Movie> vect1 = { Movie("Arrival", 7.9), Movie("Amistad", 7.3), Movie("Anaconda", 4.9), Movie("Analyze This", 6.7), Movie("American Psycho", 7.6) };

	vector<Movie> vect2 = vect1;

	vect2.erase(vect2.begin() + minratingindex(vect2));
	sortbyrating(vect1);


	cout << "Vector 1:\n";
	for (auto el : vect1) cout << el.name << " (" << el.rating << ")\n";
	cout << '\n';
	cout << "Vector 2:\n";
	for (auto el : vect2) cout << el.name << " (" << el.rating << ")\n";
	cout << '\n';

	return 0;
}

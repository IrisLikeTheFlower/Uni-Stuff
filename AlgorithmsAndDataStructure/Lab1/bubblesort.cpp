#include <iostream>
#include <ctime>

bool IsSorted(int* arr, int size) {
	for (int i = 0; i < size - 1; ++i) {
		if (arr[i] > arr[i + 1]) { return false; }
	}
	return true;
}

int* Sort(int* arr, int N) {
	int temp;
	if(!IsSorted(arr, N)){
		for (int i = 0; i < N - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
	return arr;
}

int main() {
	srand(time(NULL));

	int N = 20;
	int* arr = new int[N];

	for (int i = 0; i < N; ++i) {
		arr[i] = rand() % 201 - 100;
		std::cout << arr[i] << '\t';
	}
	std::cout << '\n';

	arr = Sort(arr, N);
	for (int i = 0; i < N; ++i) {
		std::cout << arr[i] << '\t';
	}
	std::cout << '\n';
}

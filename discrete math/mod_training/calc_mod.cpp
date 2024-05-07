#include <iostream>
#include <ctime>

int main() {
	srand(time(NULL));

	while (true) {
		int num1 = rand() % 1998 - 999;
		int num2 = rand() % 99;

		std::cout << num1 << " mod" << num2 << '\n';
		system("pause");
		if (num1 % num2 >= 0) {
			std::cout << num1 % num2 << '\n';
		}
		else {
			std::cout << (num1 % num2) + num2 << '\n';
		}
		system("pause");

		system("cls");
	}

	return 0;
}

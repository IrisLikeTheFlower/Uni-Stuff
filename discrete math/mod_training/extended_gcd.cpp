#include <iostream>
#include <ctime>

using namespace std;
int extended_gcd(int a, int b, int& s, int& t) {
    if (a == 0) {
        s = 0;
        t = 1;
        return b;
    }

    int s1, t1;
    int gcd = extended_gcd(b % a, a, s1, t1);

    s = t1 - (b / a) * s1;
    t = s1;

    return gcd;
}

int main() {
    srand(time(NULL));

    while (true) {
        int num1 = rand() % 999;
        int num2 = rand() % 999;

        cout << "gcd(" << num1 << "," << num2 << ")\n";
        system("pause");

        int s, t;
        int ans = extended_gcd(num1, num2, s, t);
        cout << "gcd(" << num1 << "," << num2 << ") = " << ans << '\n';
        system("pause");
        cout << "gcd(" << num1 << "," << num2 << ") = " << s << " * " << num1 << " + " << t << " * " << num2 << '\n';
        system("pause");

        system("cls");
    }

    return 0;
}

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

int mod(int num1, int num2) {
    if (num1 % num2 >= 0) {
        return num1 % num2;
    }
    else {
        return (num1 % num2) + num2;
    }
}

class Task {
private:
    int a;
    int b;
    int m;
    int a_1;
public:
    Task() : a(0), b(0), m(0) {}
    Task(int a, int b, int m) : a(a), b(b), m(m) {}

    friend std::ostream& operator<<(std::ostream& os, const Task& task) {
        os << task.a << "*x≡" << task.b << "(mod" << task.m << ")\n";
        return os;
    }

    void findx() {
        int s, t;
        int gcd = extended_gcd(this->m, this->a, s, t);

        if (t > 0) {
            this->a_1 = t;
        }
        else {
            this->a_1 = t + m;
        }
        
        this->a = 1;
        while (a_1 * b > m) {
            b = mod(a_1 * b, m);
        }
    }
};

int main() {
    srand(time(NULL));

    while (true) {
        int a = rand() % 99;
        int b = rand() % 99;
        int m = rand() % 99;

        Task tsk(a, b, m);
        cout << tsk;
        system("pause");

        cout << "gcd(" << m << "," << a << ")\n";
        system("pause");

        int s, t;
        int ans = extended_gcd(m, a, s, t);
        cout << "gcd(" << m << "," << a << ") = " << ans << '\n';
        system("pause");

        cout << "gcd(" << m << "," << a << ") = " << s << " * " << m << " + " << t << " * " << a << '\n';
        system("pause");

        tsk.findx();
        cout << tsk;
        system("pause");

        system("cls");
    }

    return 0;
}

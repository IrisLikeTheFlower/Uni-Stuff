#include <iostream>
using namespace std;
void echoArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << '\t';
    cout << '\n';
}

int* array_remove(int* a, int& n, int index) {
    int p = 0;
    int* newArray = new int[n - 1];
    for (int i = 0; i < n; i++) {
        if (i != index) {
            newArray[p] = a[i];
            p++;
        }
    }
    n--;
    return newArray;
}

int* array_append(int* a, int& n, int el) {
    int* newArray = new int[n + 1];
    int i = 0;
    for (; i < n; i++) {
        newArray[i] = a[i];
    }
    if (n == 0)
        i = 0;
    newArray[i] = el;
    n++;
    return newArray;
}

int* array_insert(int* a, int& n, int p, int el) {
    int c = 0;
    n++;
    int* newArray = new int[n];
    for (int i = 0; i < n; i++) {
        if (i != p) {
            newArray[i] = a[c];
            c++;
        }
        else {
            newArray[i] = el;
        }
    }
    return newArray;
}

int* strandSort(int* a, int n) {
    int arrC = n;
    int resC = 0;
    int subC = 0;
    int* result = new int[1];
    while (arrC > 0) {
        subC = 0;
        int* sublist = new int[1];
        sublist = array_append(sublist, subC, a[0]);
        a = array_remove(a, arrC, 0);
        for (int i = 0; i < arrC; i++) {
            if (a[i] > sublist[subC - 1]) {
                sublist = array_append(sublist, subC, a[i]);
                a = array_remove(a, arrC, i);
                i--;
            }
        }
        if (resC > 0) {
            int j = 0;
            for (int i = 0; i < subC; i++) {
                bool spliced = false;
                for (; j < resC; j++) {
                    if (sublist[i] < result[j]) {
                        result = array_insert(result, resC, j++, sublist[i]);
                        spliced = true;
                        break;
                    }
                }
                if (!spliced) {
                    result = array_append(result, resC, sublist[i]);
                }
            }
        }
        else {
            result = sublist;
            resC = subC;
        }
    }
    echoArray(result, resC);
    return result;
}

int main() {
    srand(time(NULL));

    int N = 20;
    int* arr = new int[N];

    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % 201 - 100;
    }
    echoArray(arr, N);
    strandSort(arr, N);
    return 0;
}

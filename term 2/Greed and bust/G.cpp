#include <iostream>
#include <cmath>

using namespace std;

int n, r, * a;

void swap(int* a, int i, int j) {
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}

bool nextPermutation(int* a, int n) {
    int j = n - 2;
    while (j != -1 && a[j] >= a[j + 1])
        j--;

    if (j == -1)return false;
    int k = n - 1;
    while (a[j] >= a[k])
        k--;

    swap(a, j, k);
    int l = j + 1;
    int r = n - 1;
    while (l < r) {
        swap(a, l++, r--);
    }

    return true;
};

bool isBeautiful(int number) {
    if (number == 0)
        return true;

    int divcounter = 0;
    for (int i = 1; i <= sqrt(number); i++) {
        if (number % i == 0) {
            divcounter++;
            if (i != sqrt(number))divcounter++;
        }
    }

    return divcounter % 3 == 0;
}

int sum() {
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += a[i] * a[i + 1];
    }
    sum = sum % r;
    return sum;
}

int main() {
    freopen("beautiful.in", "r", stdin);
    freopen("beautiful.out", "w", stdout);

    scanf("%d %d", &n, &r);
    a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    int counter = 0;
    int number = sum();
    if (isBeautiful(number))
        counter++;

    while (nextPermutation(a, n)) {
        number = sum();
        if (isBeautiful(number))counter++;
    }

    printf("%d", counter);

    return 0;
}
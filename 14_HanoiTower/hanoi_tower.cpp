#include <iostream>
#include <limits>
#include <vector>
using namespace std;

void move_rings(int a, int b) {
    cout << a << " --> " << b << endl;
}

void recursive_move(int n, int a, int b, int c) {
    if (n == 0) return;
    recursive_move(n - 1, a, c, b);
    move_rings(a, b);
    recursive_move(n - 1, c, b, a);
}

int main() {
    int n, a, b, c;
    cout << "Введите количество колец: ";
    cin >> n;
    cout << "Ваш алгоритм перемещений: " << endl;
    a = 1;
    b = 3;
    c = 2;
    recursive_move(n, a, b, c);
}
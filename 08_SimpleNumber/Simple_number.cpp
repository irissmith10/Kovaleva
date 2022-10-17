#include <iostream>
using namespace std;


int main() {
    int i, n, k = 0;
    cout << "Введите натуральное число: ";
    cin >> n;
    for (i = 2; i<n; i++) {
        if (n % i == 0) {
            cout << 
            k++;
        } 
    }
     if (k != 0) {
        cout << "Это составное число!\n";
     } else {
        cout << "Это простое число!\n";
     }
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    int a = 0, b = 100;
    int flag;
    int number;
    cout << "Задумайте число N от 1 до 100, а я угадаю!\n\n";
    while (flag != 3) {
        cout << "N больше "<< a + (b - a) / 2 << "(1 да, 2 нет, 3 равно)?\n\n";
        cin >> flag;
        if (flag == 1) {
            a += (b - a) / 2;
        } else if (flag == 2) {
            b -= (b - a) / 2;
        } else {
            number = a + (b - a) / 2;
        }
        i++;
    }
    cout << "Вы задумали " << number << "! А я молодец! Количество попыток: " << i << "\n\n";
    return 0;
}
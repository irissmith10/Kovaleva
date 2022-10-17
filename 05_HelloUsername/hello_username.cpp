#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;
int main() {
    string name;
    cout << "Введите ваше имя: ";
    cin >> name ;
    cout << "Привет, " << name << "!" << std::endl;
    return 0;
}
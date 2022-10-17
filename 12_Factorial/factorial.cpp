#include <iostream>  // Считает факториал до n = 20
#include <string>
#include <vector>
#include <cctype>
using namespace std;

unsigned long long factorial(int n);
int check(string s);

int main() {
    string s;
    cout << "Введите число для вычисления факториала: ";
    cin >> s;
    int nn = check(s);
     while (nn == -3 || nn == -2 || nn == -1 || nn == -100) {
        if (nn == -3 ) cout << "пользователь ввел нецелое число" << endl;
        else if ( nn == -2 ) cout << "пользователь ввел не число, а строку" << endl;
        else if ( nn == -1 ) cout << "пользователь ввел число < 0" << endl;
        else if ( nn == -100 ) cout << "пользователь ввел число > 100000" << endl; 
        cout << "Введите число для вычисления факториала: ";
        cin >> s;
        nn = check(s);
    }
    int n = nn;
    cout << "Факториал числа "<< n << " - " << factorial(n) << endl;
    return 0;
}

unsigned long long factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n*factorial(n-1);
    }
}

int check(string s) {
    for (int i=0 ; i<s.length(); i++) {
        if ( isalpha(s[i]) != 0 ) return -2;
    }
    if (s.find(".") != -1) return -3;
    else if ( stoi(s) < 0 ) return -1;
    else if (stoi(s)  > 100000) return -100;
    else return stoi(s) ;
        
}

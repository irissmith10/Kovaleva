#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int check(string s);

int main() {
    string s;
    cout << "Введите число: ";
    cin >> s;
    int nn = check(s);
    while (nn == -3 || nn == -2 || nn == -1 || nn == -100) {
        if (nn == -3 ) cout << "пользователь ввел нецелое число" << endl;
        else if ( nn == -2 ) cout << "пользователь ввел не число, а строку" << endl;
        else if ( nn == -1 ) cout << "пользователь ввел число < 1" << endl;
        else if ( nn == -100 ) cout << "пользователь ввел число > 100" << endl; 
        cin >> s;
        nn = check(s);
    }
    int n = nn;
    vector <long long> f(n);
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < n; i++) {
        f[i] = f[i-1] + f[i-2];
        
    };
    cout << "Числа Фибоначчи: ";
    for (int i = 0; i < n; i++) {
        cout << f[i] << " ";
    }
    cout << endl ;
   return 0;
}

int check(string s) {
    for (int i=0 ; i<s.length(); i++) {
        if ( isalpha(s[i]) != 0 ) return -2;
    }
    if (s.find(".") != -1) return -3;
    else if ( stoi(s) < 1 ) return -1;
    else if (stoi(s)  > 100) return -100;
    else return stoi(s) ;
        
}

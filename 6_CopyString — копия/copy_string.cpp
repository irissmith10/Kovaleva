#include <iostream>
using namespace std;

int main() {
    string s, s_new;
    getline(cin, s);
    int i, l;
    for (i = 0; i <= s.length()-1; i++) {
        s_new = s_new.append(1, s[i]);
    }
    cout << s_new << "\n";
    return 0;
};
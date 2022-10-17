#include <iostream>
#include <string>
#include <vector>
#include <clocale>
using namespace std;


string fill_gaps(string word, int lang);
void guess_eng(string word, string def, int lang);
int check_language(string word);

int main() {
    setlocale(LC_ALL, "Russian");
    string word;
    cout << "Введите слово: ";
    cin >> word;
    int lang = check_language(word);
    string def = fill_gaps(word, lang);
    cout << def << endl;
    guess_eng(word, def, lang);
    return 0;
}

string fill_gaps(string word, int lang) {
    string def = "";
    def += string(word.length() / lang , '-');
    return def;
} 

int check_language(string word) {
    string alf, alf_rus;
    alf_rus = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    if (alf_rus.find(word[0]) == -1) {
        return 1;
    } else {
        return 2;
    }
}

void guess_eng(string word, string def, int lang) {
    int exit = 0;
    while ( def.find(word) == -1 && exit == 0 ) {
        string letter, c_word;
        c_word = word;
        int f = 0;
        string attempt = "";
        cout << "Введите букву: ";
        cin >> letter;
        attempt += letter;
        for (int i = 0; i < word.length() / lang; i++) {
            if ((int) word[lang*i] == (int) letter[0]) {
                def.replace(lang*i, 1*lang, letter);
                f += 1;
            }
        }
        if (f == 0) {
            cout << "Нет такой буквы!" << endl << endl;
        } else {
            cout << "Угадали!" << endl << endl;
        }
        if ( def.find(word) == -1 ) {
            cout << def << endl; 
        } else {
            cout << "Вы угадали слово — " << def << "! Поздравляю!" << endl; 
        }
    }
}

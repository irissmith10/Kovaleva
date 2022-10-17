#include <iostream>
#include <string>
#include <vector>
#include <clocale>
using namespace std;

void array_output(string[], int);
int check_language(string);
int array_compare(string[], string[], int);
void congrats(string[], int);

int main() {
    string word, letter = "л";
    cout << "Введите слово: ";
    cin >> word;
    int lang = check_language(word);
    int len = word.length()/lang;
    string a[len];
    for (int i=0; i<len; i++) a[i].append(word, i*lang, lang); // перевод строки в массив
    string b[len];
    for (int i = 0; i < len; i++) b[i] = "-"; // заполнение массива прочерками
    array_output(a, len);
    cout << endl << endl;
    string attempt = "";
    int check = 0;
    while (array_compare(a, b, len) == -1) {
        array_output(b, len);
        cout << endl;
        string att[attempt.length()/lang];
        for (int i=0; i < attempt.length()/lang; i++) att[i].append(attempt, i*lang, lang);
        cout << "Введите букву: ";
        cin >> letter;
        if (letter.length() != lang) {
            check = 1; // переменная попытки угадывания слова целиком
            break;
        }
        int ch = 0;                     // переменная проверки на ввод уже введенной буквы
        for (int i=0; i < attempt.length(); i++) if (att[i] == letter) ch = 1;//
        if (ch == 0) {
            int f = 0;                  // переменная проверки на наличие введенной буквы в загаданном слове
            for (int i=0; i<len; i++) { 
                if (a[i] == letter) {   
                    b[i] = letter;      
                    f++;                
                }                       
            }                           
            if (f == 0) cout << "Нет такой буквы!" << endl << endl;
            else cout << "Угадали!" << endl << endl;
            attempt.append(letter);
        } else cout << "Эта буква уже была, попробуйте еще раз." << endl << endl;
    }
    if (check == 0) congrats(b, len);
    else {
        cout << endl;
        if (letter == word) congrats(a, len);
        else cout << "К сожалению, вы не угадали слово. Вы проиграли." << endl;
    }
}

void array_output(string a[], int len) {        //Вывод массива букв
    for (int i=0; i<len; i++) cout << a[i];
}

void congrats(string a[], int len) {            // Поздравления при угадывании слова
    cout << "Вы угадали слово — ";
    array_output(a, len);
    cout << "! Поздравляю!" << endl;
}

int check_language(string word) {               //Проверка языка введенного слова
    string alf, alf_rus;
    alf_rus = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    if (alf_rus.find(word[0]) == -1) return 1;
    else return 2;
}

int array_compare(string a[], string b[], int len) { // сравнение двух массивов из букв
    for (int i=0; i<len; i++) if (a[i] != b[i]) return -1;
    return 0;
}
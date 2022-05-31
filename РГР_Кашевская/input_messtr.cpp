#include "input_messtr.h"

string input_mes()
{
    setlocale(0, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string letter;
    string alphabet = "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþÿ &.,_=+?>\n;:/!-*@#^%|`~'(){}[]&0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char symbol;
    cout << "Please, write your letter from this alphabet: " << alphabet << endl <<"Enter your letter: ";
    while (cin.get(symbol))
    {
        letter.push_back(symbol);
    }
    cin.clear();
    return letter.substr(1);
}

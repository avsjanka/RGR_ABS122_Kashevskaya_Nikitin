#include "input_vector.h"

vector<char> input_vector(int number)
{
    setlocale(0, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<char> letter;
    if (number == 1)//Notebook
    {
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz .0123456789,!?;:()-'\n";
        char symbol;
        cout << "Please, write your letter from this alphabet: " << alphabet;
        while (cin.get(symbol))
        {
            letter.push_back(symbol);
        }
        cin.clear();
    }
    else if (number == 2)//Vernam
    {
        char symbol;
        cout << "Please, write your letter: ";
        while (cin.get(symbol))
        {
            letter.push_back(symbol);
        }
        cin.clear();
    }
    else//Caesar
    {
        string alphabet = "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþÿ ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        char symbol;
        cout << "Please, write your letter from this alphabet: " << alphabet << endl;
        while (cin.get(symbol))
        {
            letter.push_back(symbol);
        }
        cin.clear();
    }
    letter.erase(letter.begin());
    return letter;
}

#include "input_vector.h"

vector<char> input_vector(int number)
{
    setlocale(0, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<char> letter;
    if (number == 1)//Notebook
    {
        string alphabet;
        char symbol;
        cout << "Please, write your letter from this alphabet: " << alphabet;
        while (cin.get(symbol))
        {
            letter.push_back(symbol);
        }
    }
    else if (number == 2)//Vernam
    {
        string alphabet;
        char symbol;
        cout << "Please, write your letter from this alphabet: " << alphabet;
        while (cin.get(symbol))
        {
            letter.push_back(symbol);
        }
    }
    else//Caesar
    {
        string alphabet;
        char symbol;
        cout << "Please, write your letter from this alphabet: " << alphabet;
        while (cin.get(symbol))
        {
            letter.push_back(symbol);
        }
    }
    return letter;
}

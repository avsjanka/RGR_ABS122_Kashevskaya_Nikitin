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
            if (alphabet.find_first_of(symbol) == string::npos)
            {
                if (symbol == '\x1a')
                {
                    continue;
                }
                else
                {
                    cout << "This letter is incorrect!" << endl;
                    cin.clear();
                    cin.ignore(std::cin.rdbuf()->in_avail());
                    letter.erase(letter.begin());
                    return letter;
                }
            }
            else
            {
                letter.push_back(symbol);
            }
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
        cin.ignore(std::cin.rdbuf()->in_avail());
    }
    else//Caesar
    {
        cin.clear();
        cin.ignore(std::cin.rdbuf()->in_avail());
        string alphabet = "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞßàáâãäåæçèéêëìíîïğñòóôõö÷øùúûüışÿ ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        char symbol;
        cout << "Please, write your letter from this alphabet: " << alphabet << endl;
        while (cin.get(symbol))
        {
            if (alphabet.find_first_of(symbol) == string::npos)
            {
                if (symbol == '\x1a')
                {
                    continue;
                }
                else
                {
                    cout << "This letter is incorrect!" << endl;
                    cin.clear();
                    cin.ignore(std::cin.rdbuf()->in_avail());
                    letter.erase(letter.begin());
                    return letter;
                }
            }
            else
            {
                letter.push_back(symbol);
            }
        }
    }
    cin.clear();
    cin.ignore(std::cin.rdbuf()->in_avail());
    return letter;
}

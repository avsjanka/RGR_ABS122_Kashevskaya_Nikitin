#include "input_messtr.h"

string input_mes()
{
    setlocale(0, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string letter;
    string alphabet = "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞ‗אבגדהוזחטיךכלםמןנסעףפץצקרשתûü‎‏ÿ .,_=+?><\n;:/!-*@#^%|`~'(){}[]&0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char symbol;
    cout << "Please, write your letter from this alphabet: " << alphabet << endl <<"Enter your letter: ";
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
                return letter.substr(1);
            }
        }
        else
        {
            letter.push_back(symbol);
        }
    }
    cin.clear();
    return letter.substr(1);
}

#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <cmath>
#include "vigenere.h"
#include "hill.h"
#include "rsa.h"
#include "input_from_file.h"
#include "input_string_from_file.h"
using namespace std;
enum CIPHER { NOTEBOOK = 1, VERNAM = 2, CAESAR = 3, RSA = 4, VIGENERE = 5, HILL = 6 };
int main()
{
    setlocale(LC_ALL, "Ru");
    int number = 0;
    cout << "Ciphers that you can use:" << endl;
    cout << "1) NOTEBOOK" << endl;
    cout << "2) VERNAM" << endl;
    cout << "3) CAESAR" << endl;
    cout << "4) RSA" << endl;
    cout << "5) VIGENERE" << endl;
    cout << "6) HILL" << endl;
    cout << "Write number of cipher: "; 
    cin >> number;
    switch (number)  // switch/case дяя номеров шифров
    {
        case NOTEBOOK ://english nums prep
        {
            for (char let : input_from_file(number))
            {
                cout << let;
            }
            break;
        }
        case VERNAM :  //any
        {
            for (char let : input_from_file(number))
            {
                cout << let;
            }
            break;
        }
        case CAESAR : //eng rus A\a
        {
            for (char let : input_from_file(number))
            {
                cout << let;
            }
            break;
        }
        case RSA :
        {
            rsa(input_string(), 101, 59);
            break;
        }
        case VIGENERE :
        {
            vigenere(input_string(), "key");
            break;
        }
        case HILL :
        {
            hill(input_string(), "keys123456");
            break;
        }
        default :
            break;
    }
}
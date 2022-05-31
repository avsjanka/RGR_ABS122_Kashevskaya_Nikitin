#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <cmath>
#include <Windows.h>
#include "vigenere.h"
#include "hill.h"
#include "rsa.h"
#include "input_from_file.h"
#include "input_string_from_file.h"
#include "input_vector.h"
#include "input_messtr.h"
using namespace std;
enum CIPHER { NOTEBOOK = 1, VERNAM = 2, CAESAR = 3, RSA = 4, VIGENERE = 5, HILL = 6, ALL = 7 };
int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int number = 0;
    cout << "Ciphers that you can use:" << endl;
    cout << "1) NOTEBOOK" << endl;
    cout << "2) VERNAM" << endl;
    cout << "3) CAESAR" << endl;
    cout << "4) RSA" << endl;
    cout << "5) VIGENERE" << endl;
    cout << "6) HILL" << endl;
    cout << "7) ALL" << endl;
    cout << "Write number of cipher: "; 
    cin >> number;
    switch (number)
    {
        case NOTEBOOK :
        {
            vector<char> letter;
            int is_gen = 0;
            cout << "Do you want to input message? Input 1, if you want: ";
            cin >> is_gen;
            if (is_gen == 1)
            {
                letter = input_vector(number);
            }
            else
                letter = input_from_file(number);
            break;
        }
        case VERNAM :  
        {
            vector<char> letter;
            int is_gen = 0;
            cout << "Do you want to input message? Input 1, if you want: ";
            cin >> is_gen;
            if (is_gen == 1)
            {
                letter = input_vector(number);
            }
            else
                letter = input_from_file(number);
            break;
        }
        case CAESAR :
        {
            vector<char> letter;
            int is_gen = 0;
            cout << "Do you want to input message? Input 1, if you want: ";
            cin >> is_gen;
            if (is_gen == 1)
            {
                letter = input_vector(number);
            }
            else
                letter = input_from_file(number);
            break;
        }
        case RSA :
        {
            string letter;
            int is_gen = 0;
            cout << "Do you want to input message? Input 1, if you want: ";
            cin >> is_gen;
            if (is_gen == 1)
            {
                rsa(input_mes(), 101, 59);
            }
            else
            {
                string message = input_string();
                rsa(message, 101, 59);
            }
            break;
        }
        case VIGENERE :
        {
            string letter;
            int is_gen = 0;
            cout << "Do you want to input message? Input 1, if you want: ";
            cin >> is_gen;
            if (is_gen == 1)
            {
                string key = "key";
                cout << "Please, input key without ' ': ";
                cin >> key;
                vigenere(input_mes(), key);
            }
            else
            {
                string message = input_string();
                vigenere(message, "key");
            }
            break;
        }
        case HILL :
        {
            string letter;
            int is_gen = 0;
            cout << "Do you want to input message? Input 1, if you want: ";
            cin >> is_gen;
            if (is_gen == 1)
            {
                string key = "keys123456";
                cout << "Please, input key without ' ': ";
                cin >> key;
                hill(input_mes(), key);
            }
            else
            {
                string message = input_string();
                hill(message, "keys123456");
            }
            break;
        }
        case ALL :
        {
            vector<string> all_crypted;
            all_crypted.push_back(rsa(input_string(), 101, 59)[0]);
            all_crypted.push_back(vigenere(input_string(), "key")[0]);
            all_crypted.push_back(hill(input_string(), "keys123456")[0]);
            break;
        }
        default :
            break;
    }
}
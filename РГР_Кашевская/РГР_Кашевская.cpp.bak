
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <string>
#include <locale>
#include <cmath>
#include <fstream>
#include <Windows.h>
#include "input_from_file.h"
#include "print_vector.h"
#include "vector_to_string.h"
#include "remaind_of_div.h"
#include "notebook_key.h"
#include "notebook_crypt.h"
#include "notebook_decrypt.h"
#include "vernam_key.h"
#include "vernam_crypt.h"
#include "vernam_decrypt.h"
#include "caesar_crypt.h"
#include "ceasar_decrypt.h"
#define FILE_NAME "C:\\Users\\пользователь\\Desktop\\РГР.txt"
using namespace std;
enum CIPHER { NOTEBOOK = 1, VERNAM , CAESAR , RSA , VIGENERE , HILL,ALL };

int main()
{
    string password;
    cout << "Write password ";
    cin >> password;
    if (password.compare("1111") == 0)
    {
        setlocale(LC_ALL, "ru");
        int number = 0;
        cout << "Ciphers that you can use:" << endl;
        cout << "1) NOTEBOOK" << endl;
        cout << "2) VERNAM" << endl;
        cout << "3) CAESAR" << endl;
        cout << "4) RSA" << endl;
        cout << "5) VIGENERE" << endl;
        cout << "6) HILL" << endl;
        cout << "6) All Ciphers by 1 to 6" << endl;
        cout << "Write number of cipher ";
        cin >> number;
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        switch (number)
        {
            case NOTEBOOK:
            {
                vector<char> letter;
                int is_gen = 0;
                cin >> is_gen;
                if (is_gen == 1)   //Вводим сообщение
                {
                    cout << "Write your letter: " << endl;
                    letter ;
                }
                else
                    letter = input_from_file(number);
                vector<vector<char>> key = notebook_key();
                vector <char> result = notebook_crypt(letter, key);
                print_vector(result);
                vector <char> result_encrypt = notebook_decrypt(result, key);
                print_vector(result_encrypt);
                break;
            }
            case VERNAM:
            {
                vector<char> letter;
                int is_gen = 0;
                cin >> is_gen;
                if (is_gen == 1)   //Вводим сообщение
                {
                    cout << "Write your letter: " << endl;
                    letter;
                }
                else
                    letter = input_from_file(number);
                vector <int> key = vernam_key((static_cast<int> (letter.size())));
                vector<char> result = vernam_crypt(letter, key);
                print_vector(result );
                vector <char> decrypt_result = vernam_decrypt(result, key);
                print_vector(decrypt_result );
                break;
            }
            case CAESAR:
            {
                vector<char> letter;
                int is_gen = 0;
                cin >> is_gen;
                if (is_gen == 1)   //Вводим сообщение
                {
                    cout << "Write your letter: " << endl;
                    letter;
                }
                else
                    letter = input_from_file(number);
                vector<char> result = caesar_crypt(letter);
                print_vector(result);
                vector<char> decrypt_result = caesar_decrypt(result);
                print_vector(decrypt_result);
                break;
            }
            case RSA:
            {
                break;
            }
            case VIGENERE:
            {

                break;
            }
            case HILL:
            {

                break;
            }
            case ALL:
            {

                break;
            }
            default:
                break;

        }
    }
    else
        cout << "That password is incorrect!" << endl;
}


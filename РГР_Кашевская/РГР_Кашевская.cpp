<<<<<<< HEAD
﻿#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <cmath>
using namespace std;
enum CIPHER { NOTEBOOK = 0, VERNAM = 1, CAESAR = 2, RSA = 3, VIGENERE = 4, HILL = 5 };

char encrypt_symb(char letter, char key_letter)
{
    string vigLine = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя .,_=+?><;:/!-*(){}[]&0123456789@#^%ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int numOfLet = vigLine.find_first_of(letter);
    int numOfKeyLine = vigLine.find_first_of(key_letter);
    if (numOfLet == string::npos || numOfKeyLine == string::npos)//Если не нашли какую-то из букв, то шифруем как '$'
    {
        return '$';
    }
    string keyLine = vigLine.substr(numOfKeyLine) + vigLine.substr(0, numOfKeyLine);
    return keyLine[numOfLet];
}
char decrypt_symb(char encrletter, char key_letter)
{
    string vigLine = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя .,_=+?><;:/!-*(){}[]&0123456789@#^%ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int numOfKeyLine = vigLine.find_first_of(key_letter);
    if (numOfKeyLine == string::npos)
    {
        return '$';
    }
    string keyLine = vigLine.substr(numOfKeyLine) + vigLine.substr(0, numOfKeyLine);
    int numOfLet = keyLine.find_first_of(encrletter);
    return vigLine[numOfLet];
}
void vigenere(const string& message, const string& key)
{
    setlocale(LC_ALL, "Ru");
    vector<char> encrypt_mes, full_key, decrypt_mes;
    int i = 0;
    cout << "Entered message:" << endl;
    for (char letter : message)
    {
        cout << letter;
    }
    while (full_key.size() < message.size())//Формирование полного ключа
    {
        if (i == key.size())
        {
            i = 0;
        }
        full_key.push_back(key[i]);
        i++;
    }
    i = 0;
    for (char letter : message)//Шифровка текста посимвольно
    {
        encrypt_mes.push_back(encrypt_symb(letter, full_key[i]));
        i++;
    }
    cout << endl << "Encrypted message:" << endl;
    for (char letter : encrypt_mes)
    {
        cout << letter;
    }
    cout << endl;
    i = 0;
    for (char letter : encrypt_mes)//Дешифровка побуквенно
    {
        decrypt_mes.push_back(decrypt_symb(letter, full_key[i]));
        i++;
    }
    cout << "Decrypted message:" << endl;
    for (char letter : decrypt_mes)
    {
        cout << letter;
    }
}
void hill(const string& message, const string& key)
{
    string alphabet = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя .,_=+?><;:/!-*@#^%|`~'(){}[]&0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string keyLast = key;
    int numOfMatrix = sqrt(key.length()), i = 0, j = 0, numOfBlocks = message.length() / numOfMatrix + 1;
    vector<vector<int>> keyMatrix(numOfMatrix), mesMatrix(numOfBlocks);
    if (pow(numOfMatrix, 2) != key.length())
    {
        keyLast = key.substr(0, pow(numOfMatrix, 2));
    }
    for (char letter : keyLast)
    {
        if (i != numOfMatrix)
        {
            keyMatrix[j].push_back(alphabet.find_first_of(letter));
            i++;
        }
        else
        {
            i = 0;
            j++;
            keyMatrix[j].push_back(alphabet.find_first_of(letter));
        }
    }
}

int main()
{
    int number = 0;
    cout << "Ciphers that you can use:" << endl;
    cout << "0) NOTEBOOK" << endl;
    cout << "1) VERNAM" << endl;
    cout << "2) CAESAR" << endl;
    cout << "3) RSA" << endl;
    cout << "4) VIGENERE" << endl;
    cout << "5) HILL" << endl;
    cout << "Write number of cipher: "; 
    cin >> number;
    switch (number)  // switch/case дяя номеров шифров
=======
﻿
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
>>>>>>> Ann_branch
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

<<<<<<< HEAD
            break;
        }
        case CAESAR :
        {
            break;
        }
        case RSA :
        {
            break;
        }
        case VIGENERE :
        {
            vigenere("stringg,gj,h.fg.kg.ofyit7cyjhjvh,.c7vhctlvglctulvgcltyvh.g ,jkcutlyvhj g", "key");
            break;
        }
        case HILL :
        {
            hill("stringg,gj,h.fg.kg.ofyit7cyjhjvh,.c7vhctlvglctulvgcltyvh.g ,jkcutlyvhj g", "keys");
            break;
        }
        default :
            break;
=======
                break;
            }
            case ALL:
            {
>>>>>>> Ann_branch

                break;
            }
            default:
                break;

        }
    }
    else
        cout << "That password is incorrect!" << endl;
}


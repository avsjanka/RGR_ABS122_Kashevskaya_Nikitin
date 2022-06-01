#define NOMINMAX
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <string>
#include <locale>
#include <cmath>
#include <fstream>
#include <Windows.h>
#include <numeric>
#include <limits>
#include "input_from_file.h"
#include "input_vector.h"
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
using namespace std;
enum CIPHER { NOTEBOOK = 1, VERNAM, CAESAR, RSA, VIGENERE, HILL, ALL };

int main()
{
    system("color F0");
    string password;
    cout << "Write password ";
    cin >> password;
    if (password.compare("1111") == 0)
    {
        setlocale(LC_ALL, "ru");
        cout << "Ciphers that you can use:" << endl;
        cout << "1) NOTEBOOK" << endl;
        cout << "2) VERNAM" << endl;
        cout << "3) CAESAR" << endl;
        cout << "4) RSA" << endl;
        cout << "5) VIGENERE" << endl;
        cout << "6) HILL" << endl;
        cout << "7) All Ciphers by 1 to 6" << endl;
        int number = 0;
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        while (cin)
        {
            cout << "\nWrite number of cipher ";
            cin >> number;
            if (cin.fail())
            {
                cout << "You write not a number of cipher!! Please write 1-7! \n";
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                if (number > 0 && number < 8)
                {
                    switch (number)
                    {
                    case NOTEBOOK:
                    {
                        vector<char> letter;
                        int is_gen = 0;
                        cout << "Do you want to input message? Input 1, if you want: ";
                        cin >> is_gen;
                        if (is_gen == 1)   //Вводим сообщение
                            letter = input_vector(number);
                        else
                            letter = input_from_file(number);
                        cout << "Entered message:" << endl;
                        print_vector(letter);
                        vector<vector<char>> key = notebook_key();
                        vector <char> result = notebook_crypt(letter, key);
                        cout << endl << "Encrypted message:" << endl;
                        print_vector(result);
                        cout << "\nDo you want to decrypt message? Input 1, if you want: ";
                        cin >> is_gen;
                        if (is_gen == 1)
                        {
                            vector <char> result_encrypt = notebook_decrypt(result, key);
                            cout << "Decrypted message:" << endl;
                            print_vector(result_encrypt);
                        }
                        break;
                    }
                    case VERNAM:
                    {
                        vector<char> letter;
                        int is_gen = 0;
                        cout << "Do you want to input message? Input 1, if you want: ";
                        cin >> is_gen;
                        if (is_gen == 1)   //Вводим сообщение
                            letter = input_vector(number);
                        else
                            letter = input_from_file(number);
                        cout << "Entered message:" << endl;
                        print_vector(letter);
                        vector <int> key = vernam_key((static_cast<int> (letter.size())));
                        vector<char> result = vernam_crypt(letter, key);
                        cout << endl << "Encrypted message:" << endl;
                        print_vector(result);
                        cout << "\nDo you want to decrypt message? Input 1, if you want: ";
                        cin >> is_gen;
                        if (is_gen == 1)
                        {
                            vector <char> decrypt_result = vernam_decrypt(result, key);
                            cout << "Decrypted message:" << endl;
                            print_vector(decrypt_result);
                        }
                        break;
                    }
                    case CAESAR:
                    {
                        vector<char> letter;
                        int is_gen = 0;
                        cout << "Do you want to input message? Input 1, if you want: ";
                        cin >> is_gen;
                        if (is_gen == 1)   //Вводим сообщение
                            letter = input_vector(number);
                        else
                            letter = input_from_file(number);
                        cout << "Entered message:" << endl;
                        print_vector(letter);
                        vector<char> result = caesar_crypt(letter);
                        cout << endl << "Encrypted message:" << endl;
                        print_vector(result);
                        cout << "\nDo you want to decrypt message? Input 1, if you want: ";
                        cin >> is_gen;
                        if (is_gen == 1)
                        {
                            vector<char> decrypt_result = caesar_decrypt(result);
                            cout << "Decrypted message:" << endl;
                            print_vector(decrypt_result);
                        }
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
                    break;
            }
        }
        cout << "Thanks for use our programm!!";
    }
    else
        cout << "That password is incorrect!" << endl;
}



#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <string>
#include <locale>
#include <cmath>
#include <fstream>
#include <Windows.h>
#include "remaind_of_div.h"
#include "notebook_crypt.h"

#include "caesar_crypt.h"
#include "ceasar_decrypt.h"
#define FILE_NAME "C:\\Users\\пользователь\\Desktop\\РГР.txt"
using namespace std;
enum CIPHER { NOTEBOOK = 0, VERNAM = 1, CAESAR = 2, RSA = 3, VIGENERE = 4, HILL = 5 };

vector<char> vernam_key(int length)
{
    vector<char> key ;
    for (int i = 0; i <= length; i++)
    {

        key.push_back('0'+rand() % 2);
    }
    return key;
}


int main()
{
    setlocale(LC_ALL, "ru");
    int number = 0; 
    int ind = 0;
    char in_char, out_char;
    vector<char> letter;
    cout << "Ciphers that you can use:" << endl;
    cout << "0) NOTEBOOK" << endl;
    cout << "1) VERNAM" << endl;
    cout << "2) CAESAR" << endl;
    cout << "3) RSA" << endl;
    cout << "4) VIGENERE" << endl;
    cout << "5) HILL" << endl;
    cout << "Write number of cipher ";
    cin >> number;
    cout << "Write your letter: " << endl;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ofstream input;
    input.open(FILE_NAME, ios::out);
    while (cin >> in_char)        
        input << in_char;
    input.close();
    ifstream output;
    output.open(FILE_NAME, ios::in);
    while( output >> out_char)
        letter.push_back(out_char);
    output.close();
    switch (number) 
    {
        case NOTEBOOK :
        {
            char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz .0123456789,!?;:()-";
            vector < vector <char>> vec_alp(10, vector<char>(10));
            for (int i = 0, k = 0; i<10 ; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (alphabet[k] != '\0')
                        vec_alp[i][j] = alphabet[k];
                    else
                        break;
                    k++;
                    if (k == 72)
                        k = 0;
                }
            }
            random_shuffle(vec_alp.begin(), vec_alp.end());
            for (vector <char> element : vec_alp)
                random_shuffle(element.begin(), element.end());
            notebook_crypt(letter,vec_alp);
            break;
        }
        case VERNAM :  
        {
            vector <char> key = vernam_key(((int) letter.size()) * 8);
            break;
        }
        case CAESAR :
        {
            vector<char> result = caesar_crypt(letter);
            for (char element : result)
                cout << element;
            cout << endl;
            vector<char> decrypt_result = caesar_decrypt(result);
            for (char element : decrypt_result)
                cout << element;
            break;
        }
        case RSA :
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
        default :
            break;

    }
}


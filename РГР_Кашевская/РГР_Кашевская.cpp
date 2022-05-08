#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include <locale>
#include <vector>
#include <string>
#include <locale>
#include <cmath>
#include <fstream>
#define FILE_NAME "C:\\Users\\пользователь\\Desktop\\РГР.txt"
using namespace std;
enum CIPHER { NOTEBOOK = 0, VERNAM = 1, CAESAR = 2, RSA = 3, VIGENERE = 4, HILL = 5 };

int remaind_of_div(int a, int x, int p)
{
    int remaind = 1;
    for (int i = 1; i <= x; i++)
    {
        remaind *= a;
        remaind %= p;
    }
    return remaind;
}

vector<int> find_symbol(vector<vector <char>> key, char symbol)
{
    vector<int> value;
        for (int i = 0 ; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (key[i][j] == symbol)
                {
                    value.push_back(i);
                    value.push_back(j);
                }
            }
        }
        return value;
}

int vernam_key(int length)
{
    int key = 0;
    for (int i = 0; i <= length; i++)
        key = key + rand() % 2;
    return key;
}

int chip(int p, int g)
{
    int xa = 7, xb = 13;
    int Ya = 0;
    Ya = remaind_of_div(g, xa, p);
    return  remaind_of_div(Ya, xb, p);
}

int dechip(int p, int g)
{
    int xa = 7, xb = 13;
    int Yb = 0;
    Yb = remaind_of_div(g, xb, p);
    return remaind_of_div(Yb, xa, p);
}

vector<char> caesar_chip(vector<char> letter)
{
    int shift = chip(821, 97);
    vector<char> chip_letter;
    for (char element : letter)
    {
        if (element >= 'A' && element <= 'Z' || element >= 'a' && element <= 'z')
        {
            int chr_int = (int)element + (shift % 26);
            if (chr_int > (int)'Z' && element >= 'A' && element <= 'Z')
            {
                chr_int -= 25;
                element = (char)chr_int;
            }
            else if (chr_int <= (int)'Z' && element >= 'A' && element <= 'Z')
                element = (char)chr_int;
            if( chr_int > (int)'z' && element >= 'a' && element <= 'z')
            {
                chr_int -= 25;
                element = (char)chr_int;
            }
            else if (chr_int <= (int)'z' && element >= 'a' && element <= 'z')
                element = (char)chr_int;
        }
        if (element >= 'А' && element <= 'Я' || element >= 'а' && element <= 'я') 
        {
            int chr_int = (int)element - (shift % 33);
            if (chr_int > (int)'А' && element >= 'А' && element <= 'Я')
            {
                chr_int += 32;
                element = (char)chr_int;
            }
            else if (chr_int <= (int)'Я' && element >= 'А' && element <= 'Я')
                element = (char)chr_int;
            if (chr_int > (int)'я' && element >= 'а' && element <= 'я')
            {
                chr_int += 32;
                element = (char)chr_int;
            }
            else if (chr_int <= (int)'я' && element >= 'а' && element <= 'я')
                element = (char)chr_int;
        }
        chip_letter.push_back(element);
    }
    return chip_letter;
}
   
vector<char> caesar_dechip(vector<char> letter)
{
    int shift = dechip(821, 97);
    vector<char> dechip_letter;
    for (char element : letter)
    {
        if (element >= 'A' && element <= 'Z' || element >= 'a' && element <= 'z')
        {
            int chr_int = (int)element - (shift % 26);
            if (chr_int > (int)'Z' && element >= 'A' && element <= 'Z')
            {
                chr_int += 25;
                element = (char)chr_int;
            }
            else if (chr_int <= (int)'Z' && element >= 'A' && element <= 'Z')
                element = (char)chr_int;
            if (chr_int > (int)'z' && element >= 'a' && element <= 'z')
            {
                chr_int += 25;
                element = (char)chr_int;
            }
            else if (chr_int <= (int)'z' && element >= 'a' && element <= 'z')
                element = (char)chr_int;
        }
        if (element >= 'А' && element <= 'Я' || element >= 'а' && element <= 'я')
        {
            int chr_int = (int)element + (shift % 33);
            if (chr_int > (int)'А' && element >= 'А' && element <= 'Я')
            {
                chr_int -= 32;
                element = (char)chr_int;
            }
            else if (chr_int <= (int)'Я' && element >= 'А' && element <= 'Я')
                element = (char)chr_int;
            if (chr_int > (int)'я' && element >= 'а' && element <= 'я')
            {
                chr_int -= 32;
                element = (char)chr_int;
            }
            else if (chr_int <= (int)'я' && element >= 'а' && element <= 'я')
                element = (char)chr_int;
        }
        dechip_letter.push_back(element);
    }
    return dechip_letter;
}

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
                    if (k == 80)
                        k = 0;
                }
            }
            random_shuffle(vec_alp.begin(), vec_alp.end());
            for (vector <char> element : vec_alp)
                random_shuffle(element.begin(), element.end());
            break;
        }
        case VERNAM :  
        {
            int key = vernam_key(((int) letter.size()) * 8);

            break;
        }
        case CAESAR :
        {
            vector<char> result = caesar_chip(letter);
            break;
        }
        case RSA :
        {
            break;
        }
        case VIGENERE:
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

    }
}



#include <iostream>
#include <string>
#include <locale>
#include <vector>
using namespace std;
enum CIPHER { NOTEBOOK = 0, VERNAM = 1, CAESAR = 2, RSA = 3, VIGENERE = 4, HILL = 5 };

char rus_encrypt(char letter)
{
    char encrypted_letter = 'M';
    return encrypted_letter;
}

char eng_encrypt(char letter)
{
    char encrypted_letter = 'И';
    return encrypted_letter;
}

void vigenere(const string message, const string key)
{
    setlocale(LC_ALL, "Ru");//32 - 126 Eng  -64 - -1 Рус
    vector<char> encrypt_mes, full_key(message.size());
    if (message.size() <= key.size())
    {
        for(int i = 0, k = 0; i <)
    }
    for (char letter : message)
    {
        if (int(letter) > 31 && int(letter) < 127)
        {
            encrypt_mes.push_back(eng_encrypt(letter));
        }
        else if (int(letter) > -63 && int(letter) < 0)
        {
            encrypt_mes.push_back(rus_encrypt(letter));
        }
    }
    for (char letter : encrypt_mes)
    {
        cout << letter;
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
    {
        case NOTEBOOK :
        {

            break;
        }
        case VERNAM :  
        {

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
            vigenere("stringытппыктп", "key");
            break;
        }
        case HILL :
        {
            break;
        }
        default :
            break;

    }

}


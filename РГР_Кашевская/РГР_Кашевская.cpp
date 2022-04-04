
#include <iostream>
using namespace std;
enum CIPHER { NOTEBOOK = 0, VERNAM = 1, CAESAR = 2, RSA = 3, VIGENERE = 4, HILL = 5 };

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
    cout << "Write number of cipher:  "; 
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


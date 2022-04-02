
#include <iostream>
using namespace std;
enum CIPHER { NOTEBOOK = 0, VERNAM = 1, CAESAR = 2, RSA = 3, VIGENERE = 4, LAST = 5 };

int main()
{
    int number = 0;
    cout << "Write number of cipher";
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
        case LAST :
        {
            break;
        }
        default :
            break;

    }

}


#include <iostream>
#include <string>
#include <locale>
#include <vector>
#include <cmath>
#include "vigenere.h"
#include "hill.h"
#include "rsa.h"
using namespace std;
enum CIPHER { NOTEBOOK = 0, VERNAM = 1, CAESAR = 2, RSA = 3, VIGENERE = 4, HILL = 5 };
int main()
{
    setlocale(LC_ALL, "Ru");
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
        case RSA ://5760509, 9624859
        {
            rsa("strgnlsbjnkaef73920bnsv01odq=-avjd@е#%^ЛПКМТВГЛЫИМД ФОшокма", 101, 59);
            break;
        }
        case VIGENERE :
        {
            vigenere("stringg,gj,h.fg.kg.ofyit7cyjhjvh,.c7vhctlvglctulvgcltyvh.g ,jkcutlyvhj g", "key");
            break;
        }
        case HILL :
        {
            hill("string111", "keys123456");
            break;
        }
        default :
            break;
    }
}
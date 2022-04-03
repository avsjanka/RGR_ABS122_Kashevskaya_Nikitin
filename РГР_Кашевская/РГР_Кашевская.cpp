
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
enum CIPHER { NOTEBOOK = 0, VERNAM = 1, CAESAR = 2, RSA = 3, VIGENERE = 4, HILL = 5 };

int main()
{
    int number = 0;
    cout << "Write number of cipher ";
    cin >> number;
    switch (number)  // switch/case дяя номеров шифров
    {
        case NOTEBOOK :
        {
            char alphabet[] = "abcdefgijhklmnopqrstuvwxyz .ABCDEFGIHJKLMNOPQRTSUVWXYZ0123456789,!?;:()-";
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
            {
                random_shuffle(element.begin(), element.end());
                for (char symbol : element)
                    cout << symbol;
                cout << endl;
            }
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


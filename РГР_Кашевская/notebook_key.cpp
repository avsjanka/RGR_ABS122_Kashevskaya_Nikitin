#include "notebook_key.h"

vector<vector<char>> notebook_key()
{
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz .0123456789,!?;:()-'\n";
    vector < vector <char>> vec_alp(10, vector<char>(10));
    for (int i = 0, k = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (alphabet[k] != '\0')
                vec_alp[i][j] = alphabet[k];
            else
                break;
            k++;
            if (k == 74)
                k = 0;
        }
    }
    random_shuffle(vec_alp.begin(), vec_alp.end());
    for (vector <char> element : vec_alp)
        random_shuffle(element.begin(), element.end());
    return vec_alp;
}

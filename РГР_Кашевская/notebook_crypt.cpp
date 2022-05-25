#include "notebook_crypt.h"

vector<int> find_symbol(vector<vector <char>>& key, char symbol)
{
    vector<int> value;
    for (int i = 0; i < 10; i++)
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

vector<char> notebook_crypt(vector<char>& letter, vector<vector <char>>& key)
{
    vector<char> crypt_letter;
    for (char chr : letter)
    {
        vector<int> crypt_symb=find_symbol(key,chr);
        if (crypt_symb.size() == 4)
        {
            int random = rand() % 2;
            if (random == 0)
            {
                crypt_letter.push_back(crypt_symb[2] + '0');
                crypt_letter.push_back(crypt_symb[3] + '0');
            }
            else
            {
                crypt_letter.push_back(crypt_symb[0] + '0');
                crypt_letter.push_back(crypt_symb[1] + '0');
            }
        }
        else if (crypt_symb.size() == 2)
        {
            crypt_letter.push_back(crypt_symb[0]+'0'); 
            crypt_letter.push_back(crypt_symb[1]+'0');
        }
        
    }
        return crypt_letter;

}

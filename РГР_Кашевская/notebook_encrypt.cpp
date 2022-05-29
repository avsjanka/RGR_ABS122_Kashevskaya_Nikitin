#include "notebook_encrypt.h"
char find_symbol(int str, int coll, vector<vector<char>>& key)
{
    return key[str][coll];
}

vector<char> notebook_encrypt(vector<char>& crypt_letter, vector<vector<char>>& key)
{
    vector<char> result;
    for (int i = 0; i < static_cast<int> (crypt_letter.size()); i += 2)
    {
        result.push_back(find_symbol(i,i+1, key));
    }
    return result;
}

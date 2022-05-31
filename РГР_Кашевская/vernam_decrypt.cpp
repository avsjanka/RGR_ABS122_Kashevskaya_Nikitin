#include "vernam_decrypt.h"

vector<char> vernam_decrypt(vector<char>& crypt_letter, vector<int>& key)
{
    vector<char> result;
    for (size_t i = 0; i < crypt_letter.size(); i++)
    {
        int chr = ((int)crypt_letter[i]) ^ key[i];
        result.push_back((char)chr);
    }
    return result;
}
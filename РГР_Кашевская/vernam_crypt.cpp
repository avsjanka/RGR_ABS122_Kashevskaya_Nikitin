#include "vernam_crypt.h"

vector<char> vernam_crypt(vector<char>& letter, vector<int>& key)
{
    vector<char> result;
    for (size_t i = 0; i < letter.size(); i ++ )
    {
        int chr = ((int)letter[i]) ^ key[i];
        result.push_back((char) chr);
    }
    return result;
}

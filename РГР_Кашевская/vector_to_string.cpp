#include "vector_to_string.h"

string vector_to_string(vector<char> letter)
{
    string str;
    for (char symbol : letter)
        str.push_back(symbol);
    return str;
}

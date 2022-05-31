#include "ceasar_decrypt.h"

int dechip(int p, int g)
{
    int xa = 7, xb = 13;
    int Yb = 0;
    Yb = remaind_of_div(g, xb, p);
    return remaind_of_div(Yb, xa, p);
}


vector<char> caesar_decrypt(vector<char>& letter)
{
    int shift = dechip(821, 97);
    vector<char> dechip_letter;
    for (char element : letter)
    {
        if (element >= 'A' && element <= 'Z' || element >= 'a' && element <= 'z')
        {
            int chr_int = (int)element - (shift % 26);
            if (chr_int < (int)'A' && element >= 'A' && element <= 'Z')
            {
                chr_int += 26;
                element = (char)chr_int;
            }
            else if (chr_int >= (int)'A' && element >= 'A' && element <= 'Z')
                element = (char)chr_int;
            if (chr_int < (int)'a' && element >= 'a' && element <= 'z')
            {
                chr_int += 26;
                element = (char)chr_int;
            }
            else if (chr_int >= (int)'a' && element >= 'a' && element <= 'z')
                element = (char)chr_int;
        }
        if (element >= 'À' && element <= 'ß' || element >= 'à' && element <= 'ÿ')
        {
            int chr_int = (int)element - (shift % 32);
            if (chr_int < (int)'À' && element >= 'À' && element <= 'ß')
            {
                chr_int += 32;
                element = (char)chr_int;
            }
            else if (chr_int >= (int)'À' && element >= 'À' && element <= 'ß')
                element = (char)chr_int;
            if (chr_int < (int)'à' && element >= 'à' && element <= 'ÿ')
            {
                chr_int += 32;
                element = (char)chr_int;
            }
            else if (chr_int >= (int)'à' && element >= 'à' && element <= 'ÿ')
                element = (char)chr_int;
        }
        dechip_letter.push_back(element);
    }
    return dechip_letter;
}
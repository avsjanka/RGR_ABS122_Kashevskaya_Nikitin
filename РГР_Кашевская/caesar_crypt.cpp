#include "caesar_crypt.h"



int chip(int p, int g)
{
    int xa = 7, xb = 13;
    int Ya = 0;
    Ya = remaind_of_div(g, xa, p);
    return  remaind_of_div(Ya, xb, p);
}

vector<char> caesar_crypt(vector<char>& letter)
{
    int shift = chip(821, 97);
    vector<char> chip_letter;
    for (char element : letter)
    {
        if (element >= 'A' && element <= 'Z' || element >= 'a' && element <= 'z')
        {
            int chr_int = (int)element + (shift % 26);
            if (chr_int > (int)'Z' && element >= 'A' && element <= 'Z')
            {
                chr_int -= 26;
                element = (char)chr_int;
            }
            else if (chr_int <= (int)'Z' && element >= 'A' && element <= 'Z')
                element = (char)chr_int;
            if (chr_int > (int)'z' && element >= 'a' && element <= 'z')
            {
                chr_int -= 26;
                element = (char)chr_int;
            }
            else if (chr_int <= (int)'z' && element >= 'a' && element <= 'z')
                element = (char)chr_int;
        }
        if (element >= 'À' && element <= 'ß' || element >= 'à' && element <= 'ÿ')
        {
            int chr_int = (int)element + (shift % 32);
            if (chr_int > (int)'ß' && element >= 'À' && element <= 'ß')
            {
                chr_int -= 32;
                element = (char)chr_int;
            }
            else if (chr_int <= (int)'ß' && element >= 'À' && element <= 'ß')
                element = (char)chr_int;
            if (chr_int > (int)'ÿ' && element >= 'à' && element <= 'ÿ')
            {
                chr_int -= 32;
                element = (char)chr_int;
            }
            else if (chr_int <= (int)'ÿ' && element >= 'à' && element <= 'ÿ')
                element = (char)chr_int;
        }
        chip_letter.push_back(element);
    }
    return chip_letter;
}

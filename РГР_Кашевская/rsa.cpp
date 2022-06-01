#include "rsa.h"
int multi_rev(int a, int b)
{
    int r = 0, u = 0, v = 0, q = 0;
    vector<int> X = { a,0 }, Y = { b, 1 }, T(2);
    while (Y[0] != 0)
    {
        q = X[0] / Y[0];
        T = { X[0] % Y[0], X[1] - Y[1] * q };
        X = Y;
        Y = T;
    }if (X[1] < 0)
    {
        X[1] += a;
    }
    return X[1];
}
vector<string> rsa(const string& message, int p, int q)
{
    int n = p * q, phi = (p - 1) * (q - 1), e = 37, d = multi_rev(phi, e), numOfLet = 0;
    string alphabet = "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞßàáâãäåæçèéêëìíîïðñòóôõö÷øùúûüýþÿ .,_=+?><\n;:/!-*@#^%|`~'(){}[]&0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string encr_mes, decr_mes;
    vector<int> code_of_let, encr_lets;
    for (int i = 0; i < message.size(); i++)
    {
        if (alphabet.find_first_of(message[i]) != string::npos)
        {
            numOfLet = static_cast<int>(alphabet.find_first_of(message[i]));
        }
        if (static_cast<int>(message[i]) == -105)
        {
            numOfLet = static_cast<int>(alphabet.find_first_of('-'));
        }
        code_of_let.push_back(numOfLet);
        encr_lets.push_back(big_rem(numOfLet, e, n));
        encr_mes.push_back(alphabet[remaind_of_div(big_rem(numOfLet, e, n), 1, alphabet.length())]);
    }
    for (int letter : encr_lets)
    {
        decr_mes.push_back(alphabet[big_rem(letter, d, n)]);
    }
    return { encr_mes, decr_mes };
}

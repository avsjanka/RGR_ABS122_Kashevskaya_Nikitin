#include "rsa.h"
ostream& operator<<(ostream& stream, vector<int>& f) {//ïåğåãğóçêà îïåğàòîğà âûâîäà âåêòîğà 
    for (int& item : f) {
        stream << item << " ";
    }
    return stream;
}
int euler_func(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    if (n > 1)
        result -= result / n;
    return result;
}
int big_rem(int a, int x, int p)
{
    int r = 0;
    r = x % euler_func(p);
    return remaind_of_div(a, r, p);
}
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
int rsa(const string& message, int p, int q)
{
    int n = p * q, phi = (p - 1) * (q - 1), e = 37, d = multi_rev(phi, e), numOfLet = 0;
    string alphabet = "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞßàáâãäåæçèéêëìíîïğñòóôõö÷øùúûüışÿ .,_=+?><;:/!-*@#^%|`~'(){}[]&0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string encr_mes, decr_mes;
    vector<int> code_of_let, encr_lets;
    cout << "Entered message:" << endl;
    cout << message << endl;
    for (int i = 0; i < message.size(); i++)
    {
        numOfLet = static_cast<int>(alphabet.find_first_of(message[i]));
        code_of_let.push_back(numOfLet);
        encr_lets.push_back(big_rem(numOfLet, e, n));
        encr_mes.push_back(alphabet[remaind_of_div(big_rem(numOfLet, e, n), 1, alphabet.length())]);
    }
    cout << "Encrypted message:" << endl;
    cout << encr_mes << endl;
    for (int letter : encr_lets)
    {
        decr_mes.push_back(alphabet[big_rem(letter, d, n)]);
    }
    cout << "Decrypted message:" << endl;
    cout << decr_mes << endl;
    return 1;
}

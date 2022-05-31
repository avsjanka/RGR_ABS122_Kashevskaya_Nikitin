#include "vigenere.h"
ostream& operator<<(ostream& stream, vector<char>& f) {//перегрузка оператора вывода вектора 
    for (char& item : f) {
        stream << item;
    }
    return stream;
}
char encrypt_symb(char letter, char key_letter)
{
    string vigLine = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя &.,_=+?>\n;:/!-*@#^%|`~'(){}[]&0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int numOfLet = static_cast<int>(vigLine.find_first_of(letter));
    int numOfKeyLine = static_cast<int>(vigLine.find_first_of(key_letter));
    if (numOfLet == string::npos || numOfKeyLine == string::npos)//Если не нашли какую-то из букв, то шифруем как '$'
    {
        return '$';
    }
    string keyLine = vigLine.substr(numOfKeyLine) + vigLine.substr(0, numOfKeyLine);
    return keyLine[numOfLet];
}
char decrypt_symb(char encrletter, char key_letter)
{
    string vigLine = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя &.,_=+?>\n;:/!-*@#^%|`~'(){}[]&0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int numOfKeyLine = static_cast<int>(vigLine.find_first_of(key_letter));
    if (numOfKeyLine == string::npos || encrletter == '$')
    {
        return '$';
    }
    string keyLine = vigLine.substr(numOfKeyLine) + vigLine.substr(0, numOfKeyLine);
    int numOfLet = static_cast<int>(keyLine.find_first_of(encrletter));
    return vigLine[numOfLet];
}
vector<string> vigenere(const string& message, const string& key)
{
    string encrypt_mes, full_key, decrypt_mes;
    int i = 0;
    if (key.length() == 0)
    {
        cout << "Please, enter key with length more than 0." << endl;
        return {};
    }
    cout << "Entered message:" << endl << message << endl;
    while (full_key.size() < message.size())//Формирование полного ключа
    {
        if (i == key.size())
        {
            i = 0;
        }
        full_key.push_back(key[i]);
        i++;
    }
    i = 0;
    for (char letter : message)//Шифровка текста посимвольно
    {
        encrypt_mes.push_back(encrypt_symb(letter, full_key[i]));
        i++;
    }
    cout << "Encrypted message:" << endl << encrypt_mes << endl;
    cout << "Do you want to decrypt this? Please, input 1, if you want: ";
    int isDecr;
    cin >> isDecr;
    if (isDecr != 1)
    {
        return { encrypt_mes , ""};
    }
    i = 0;
    for (char letter : encrypt_mes)//Дешифровка побуквенно
    {
        decrypt_mes.push_back(decrypt_symb(letter, full_key[i]));
        i++;
    }
    cout << "Decrypted message:" << endl << decrypt_mes << endl;
    return { encrypt_mes, decrypt_mes };
}
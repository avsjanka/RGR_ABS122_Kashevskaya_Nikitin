#include "vigenere.h"
char encrypt_symb(char letter, char key_letter)
{
    string vigLine = "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞßàáâãäåæçèéêëìíîïğñòóôõö÷øùúûüışÿ .,_=+?><\n;:/!-*@#^%|`~'(){}[]&0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int numOfLet = static_cast<int>(vigLine.find_first_of(letter));
    int numOfKeyLine = static_cast<int>(vigLine.find_first_of(key_letter));
    if (numOfLet == string::npos || numOfKeyLine == string::npos)//Åñëè íå íàøëè êàêóş-òî èç áóêâ, òî øèôğóåì êàê '$'
    {
        return '$';
    }
    string keyLine = vigLine.substr(numOfKeyLine) + vigLine.substr(0, numOfKeyLine);
    return keyLine[numOfLet];
}
char decrypt_symb(char encrletter, char key_letter)
{
    string vigLine = "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞßàáâãäåæçèéêëìíîïğñòóôõö÷øùúûüışÿ .,_=+?><\n;:/!-*@#^%|`~'(){}[]&0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int numOfKeyLine = static_cast<int>(vigLine.find_first_of(key_letter));
    if (numOfKeyLine == string::npos || encrletter == '$')
    {
        return '$';
    }
    string keyLine = vigLine.substr(numOfKeyLine) + vigLine.substr(0, numOfKeyLine);
    int numOfLet = static_cast<int>(keyLine.find_first_of(encrletter));
    return vigLine[numOfLet];
}
vector<string> vigenere(const string& message, const string& key, int num)
{
    string encrypt_mes, full_key, decrypt_mes;
    int i = 0;
    if (key.length() == 0)
    {
        cout << "Please, enter key with length more than 0." << endl;
        return {};
    }
    cout << "Entered message:" << endl << message << endl;
    while (full_key.size() < message.size())//Ôîğìèğîâàíèå ïîëíîãî êëş÷à
    {
        if (i == key.size())
        {
            i = 0;
        }
        full_key.push_back(key[i]);
        i++;
    }
    i = 0;
    for (char letter : message)//Øèôğîâêà òåêñòà ïîñèìâîëüíî
    {
        encrypt_mes.push_back(encrypt_symb(letter, full_key[i]));
        i++;
    }
    cout << "Encrypted message:" << endl << encrypt_mes << endl;
    if (num == 7)
    {
        i = 0;
        for (char letter : encrypt_mes)//Äåøèôğîâêà ïîáóêâåííî
        {
            decrypt_mes.push_back(decrypt_symb(letter, full_key[i]));
            i++;
        }
        cout << "Decrypted message:" << endl << decrypt_mes << endl;
        return { encrypt_mes , "" };
    }
    cout << "Do you want to decrypt this? Please, input 1, if you want: ";
    int isDecr;
    cin >> isDecr;
    if (isDecr != 1)
    {
        return { encrypt_mes , ""};
    }
    i = 0;
    for (char letter : encrypt_mes)//Äåøèôğîâêà ïîáóêâåííî
    {
        decrypt_mes.push_back(decrypt_symb(letter, full_key[i]));
        i++;
    }
    cout << "Decrypted message:" << endl << decrypt_mes << endl;
    return { encrypt_mes, decrypt_mes };
}
#include "hill.h"
int determinOfMatrix(vector<vector<int>> keyMatrix, const int rank) //Âû÷èñëåíèå îïğåäåëèòåëÿ ìàòğèöû
{
    int determin = 0;
    if (rank == 1)
    {
        determin = keyMatrix[0][0];
        return determin;
    }
    if (rank == 2)
    {
        determin = keyMatrix[0][0] * keyMatrix[1][1] - keyMatrix[1][0] * keyMatrix[0][1];
        return determin;
    }
    if (rank == 3)
    {
        determin += keyMatrix[0][0] * (keyMatrix[1][1] * keyMatrix[2][2] - keyMatrix[2][1] * keyMatrix[1][2]);
        determin -= keyMatrix[0][1] * (keyMatrix[1][0] * keyMatrix[2][2] - keyMatrix[1][2] * keyMatrix[2][0]);
        determin += keyMatrix[0][2] * (keyMatrix[1][0] * keyMatrix[2][1] - keyMatrix[2][0] * keyMatrix[1][1]);
        return determin;
    }
    return determin;
}
vector<int> multiMatrix(vector<vector<int>> keyMatrix, vector<int> curString, int rank)
{
    vector<int> encryptNums;
    if (rank == 1)
    {
        encryptNums.push_back(keyMatrix[0][0] * curString[0]);
        return encryptNums;
    }
    if (rank == 2)
    {
        int firstElement = 0, secondElement = 0;
        firstElement = curString[0] * keyMatrix[0][0] + curString[1] * keyMatrix[1][0];
        secondElement = curString[0] * keyMatrix[0][1] + curString[1] * keyMatrix[1][1];
        encryptNums.push_back(remaind_of_div(firstElement, 1, 157));
        encryptNums.push_back(remaind_of_div(secondElement, 1, 157));
        return encryptNums;
    }
    if (rank == 3)
    {
        int firstElement = 0, secondElement = 0, thirdElement = 0;
        firstElement = curString[0] * keyMatrix[0][0] + curString[1] * keyMatrix[1][0] + curString[2] * keyMatrix[2][0];
        secondElement = curString[0] * keyMatrix[0][1] + curString[1] * keyMatrix[1][1] + curString[2] * keyMatrix[2][1];
        thirdElement = curString[0] * keyMatrix[0][2] + curString[1] * keyMatrix[1][2] + curString[2] * keyMatrix[2][2];
        encryptNums.push_back(remaind_of_div(firstElement, 1, 157));
        encryptNums.push_back(remaind_of_div(secondElement, 1, 157));
        encryptNums.push_back(remaind_of_div(thirdElement, 1, 157));
        return encryptNums;
    }
    return { 0 };
}
int hill(const string& message, const string& key)
{
    if (key.length() == 0)
    {
        cout << "Please, enter key with length more than 0." << endl;
        return 0;
    }
    cout << "Entered message:" << endl << message << endl;
    string alphabet = "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞßàáâãäåæçèéêëìíîïğñòóôõö÷øùúûüışÿ .,_=+?><;:/!-*@#^%|`~'(){}[]&0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string keyLast = key, curBlock, encryptMes, newMes = message;
    int numOfMatrix = static_cast<int>(sqrt(key.length())), i = 0, j = 0, numOfBlocks = static_cast<int>((message.length() / numOfMatrix));
    if (numOfBlocks * numOfMatrix < message.length())
    {
        numOfBlocks++;
    }
    vector<vector<int>> keyMatrix(numOfMatrix), mesMatrix(numOfBlocks);
    vector<int> block(numOfMatrix);
    if (pow(numOfMatrix, 2) != key.length())
    {
        if (pow(numOfMatrix, 2) >= 9)
        {
            numOfMatrix = 3;
        }
        keyLast = key.substr(0, static_cast<const unsigned __int64>(pow(numOfMatrix, 2)));
    }
    for (char letter : keyLast)
    {
        if (i < numOfMatrix)
        {
            keyMatrix[j].push_back(alphabet.find_first_of(letter));
            i++;
        }
        else
        {
            i = 0;
            j++;
            keyMatrix[j].push_back(alphabet.find_first_of(letter));
            i++;
        }
    }
    if (determinOfMatrix(keyMatrix, numOfMatrix) == 0)
    {
        cout << "Please, enter another key." << endl;
        return 0;
    }
    for (int str = 0; str < numOfMatrix; str++)
    {
        if (str == numOfMatrix - 1 && message.length() % numOfMatrix != 0)
        {
            while (newMes.length() % numOfMatrix != 0)
            {
                newMes.push_back(' ');
            }
            curBlock = message.substr(numOfMatrix * str, numOfMatrix);
            int k = 0;
            for (char letter : curBlock)
            {
                block[k] = alphabet.find_first_of(letter);
                k++;
            }
            for (int num : multiMatrix(keyMatrix, block, numOfMatrix))
            {
                encryptMes.push_back(alphabet[num]);
            }
        }
        else
        {
            curBlock = message.substr(numOfMatrix * str, numOfMatrix);
            int k = 0;
            for (char letter : curBlock)
            {
                block[k] = alphabet.find_first_of(letter);
                k++;
            }
            for (int num : multiMatrix(keyMatrix, block, numOfMatrix))
            {
                encryptMes.push_back(alphabet[num]);
            }
        }
    }
    cout << "Encrypted message:" << endl << encryptMes << endl;
    return 1;
}

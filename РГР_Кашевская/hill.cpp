#include "hill.h"
ostream& operator<<(ostream& stream, vector<vector<int>>& f) {//перегрузка оператора вывода вектора векторов
    for (vector<int>& item : f) {
        for (int& elem : item) {
            stream << elem << " ";
        }
        stream << endl;
    }
    return stream;
}
int determinOfMatrix(vector<vector<int>> keyMatrix, const int rank) //Вычисление определителя матрицы
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
        encryptNums.push_back(remaind_of_div(keyMatrix[0][0] * curString[0], 1, 157));
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
int det_rev(int a, int b)
{
    int r = 0, u = 0, v = 0, q = 0;
    vector<int> X = { a,1,0 }, Y = { b, 0, 1 }, T(3);
    while (Y[0] != 0)
    {
        q = X[0] / Y[0];
        T = { X[0] % Y[0], X[1] - Y[1] * q, X[2] - Y[2] * q };
        X = Y;
        Y = T;
    }
    return X[1];
}
int alg_dop(vector<vector<int>> keyMatrix, int line, int col)
{
    switch (line)
    {
        case 0:
        {
            switch (col)
            {
            case 0:
            {
                return keyMatrix[1][1] * keyMatrix[2][2] - keyMatrix[2][1] * keyMatrix[1][2];
                break;
            }
            case 1 :
            {
                return keyMatrix[2][0] * keyMatrix[1][2] - keyMatrix[1][0] * keyMatrix[2][2];
                break;
            }
            case 2:
            {
                return keyMatrix[1][0] * keyMatrix[2][1] - keyMatrix[2][0] * keyMatrix[1][1];
                break;
            }
            default:
                break;
            }
        }
        case 1:
        {
            switch (col)
            {
            case 0:
            {
                return keyMatrix[0][2] * keyMatrix[2][1] - keyMatrix[0][1] * keyMatrix[2][2];
                break;
            }
            case 1:
            {
                return keyMatrix[0][0] * keyMatrix[2][2] - keyMatrix[2][0] * keyMatrix[0][2];
                break;
            }
            case 2:
            {
                return keyMatrix[0][1] * keyMatrix[2][0] - keyMatrix[0][0] * keyMatrix[2][1];
                break;
            }
            default:
                break;
            }
        }
        case 2:
        {
            switch (col)
            {
            case 0:
            {
                return keyMatrix[0][1] * keyMatrix[1][2] - keyMatrix[1][1] * keyMatrix[0][2];
                break;
            }
            case 1:
            {
                return keyMatrix[1][0] * keyMatrix[0][2] - keyMatrix[0][0] * keyMatrix[1][2];
                break;
            }
            case 2:
            {
                return keyMatrix[0][0] * keyMatrix[1][1] - keyMatrix[0][1] * keyMatrix[1][0];
                break;
            }
            default:
                break;
            }
        }
        default:
            break;
    }
    return 0;
}
vector<vector<int>> alg_dop_matr(vector<vector<int>> keyMatrix, int rank)
{
    if (rank == 1)
    {
        return keyMatrix;
    }
    else if (rank == 2)
    {
        vector<vector<int>> new_matrix;
        new_matrix.push_back({ keyMatrix[1][1], -keyMatrix[0][1] });
        new_matrix.push_back({ -keyMatrix[1][0], keyMatrix[0][0] });
        return new_matrix;
    }
    else if (rank == 3)
    {
        vector<vector<int>> new_matrix;
        for (int i = 0; i < 3; i++)
        {
            new_matrix.push_back({});
            for (int j = 0; j < 3; j++)
            {
                new_matrix[i].push_back(alg_dop(keyMatrix, i, j));
            }
        }
        return new_matrix;
    }
    return { {} };
}
string decrypt_hill(string alphabet, vector<vector<int>> keyMatrix, int numOfMatrix, string encryptMes)
{
    int det_K = determinOfMatrix(keyMatrix, numOfMatrix), rev_det;
    int x = det_rev(det_K, static_cast<int>(alphabet.length()));
    if (x > 0)
    {
        rev_det = x;
    }
    else
    {
        if (det_K > 0)
        {
            rev_det = x + static_cast<int>(alphabet.length());
        }
        else
        {
            rev_det = -x;
        }
    }
    vector<vector<int>> alg_dop_k = alg_dop_matr(keyMatrix, static_cast<int>(keyMatrix.size()));
    for (vector<int>& line : alg_dop_k)
    {
        for (int& element : line)
        {
            element = big_rem(big_rem(element, 1, static_cast<int>(alphabet.length())) * rev_det, 1, static_cast<int>(alphabet.length()));
        }
    }
    for (int i = 0; i < static_cast<int>(alg_dop_k.size()); i++)
    {
        for (int j = i; j < static_cast<int>(alg_dop_k.size()); j++)
        {
            int glass = alg_dop_k[i][j];
            alg_dop_k[i][j] = alg_dop_k[j][i];
            alg_dop_k[j][i] = glass;
        }
    }
    for (vector<int>& line : alg_dop_k)
    {
        for (int& element : line)
        {
            if (element < 0)
            {
                element += static_cast<int>(alphabet.length());
            }
        }
    }
    string decrypt_mes;
    vector<int> decr_block;
    for (char letter : encryptMes)
    {
        if (letter == '$')
        {
            decr_block.push_back(' ');
        }
        else {
            decr_block.push_back(alphabet.find_first_of(letter));
        }
        if (decr_block.size() == numOfMatrix)
        {
            decr_block = multiMatrix(alg_dop_k, decr_block, static_cast<int>(alg_dop_k.size()));
            for (int& num : decr_block)
            {
                num = big_rem(num, 1, static_cast<int>(alphabet.length()));
                if (big_rem(num, 1, static_cast<int>(alphabet.length())) < 0)
                    num += alphabet.length();
                decrypt_mes.push_back(alphabet[num]);
            }
            decr_block.clear();
        }
    }
    return decrypt_mes;
}
vector<string> hill(const string& message, const string& key)
{
    if (key.length() == 0)
    {
        cout << "Please, enter key with length more than 0." << endl;
        return {};
    }
    string alphabet = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя .,_=+?><\n;:/!-*@#^%|`~'(){}[]&0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
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
        if (alphabet.find_first_of(letter) == string::npos)
        {
            cout << "Entered key is incorrect." << endl;
            return{};
        }
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
        return {};
    }
    for (int str = 0; str < numOfBlocks; str++)
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
                if (alphabet.find_first_of(letter) == string::npos)
                {
                    block[k] = '$';
                }
                else
                {
                    block[k] = alphabet.find_first_of(letter);
                }
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
                if (alphabet.find_first_of(letter) == string::npos)
                {
                    block[k] = '$';
                }
                else
                {
                    block[k] = alphabet.find_first_of(letter);
                }
                k++;
            }
            for (int num : multiMatrix(keyMatrix, block, numOfMatrix))
            {
                encryptMes.push_back(alphabet[num]);
            }
        }
    }
    string decr_mes = "";
    decr_mes = decrypt_hill(alphabet, keyMatrix, numOfMatrix, encryptMes);
    return { encryptMes, decr_mes };
}

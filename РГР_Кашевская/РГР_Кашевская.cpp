#define NOMINMAX

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <string>
#include <locale>
#include <cmath>
#include <fstream>
#include <Windows.h>
#include <numeric>
#include <limits>

#include "vigenere.h"
#include "hill.h"
#include "rsa.h"

#include "input_from_file.h"
#include "input_messtr.h"
#include "input_string_from_file.h"
#include "input_vector.h"
#include "print_vector.h"
#include "vector_to_string.h"
#include "remaind_of_div.h"

#include "notebook_key.h"
#include "notebook_crypt.h"
#include "notebook_decrypt.h"
#include "vernam_key.h"
#include "vernam_crypt.h"
#include "vernam_decrypt.h"
#include "caesar_crypt.h"
#include "ceasar_decrypt.h"

using namespace std;
enum CIPHER { NOTEBOOK = 1, VERNAM, CAESAR, RSA, VIGENERE, HILL, ALL };

int main()
{
    system("color F0");
    string password;
    cout << "Write password ";
    cin >> password;
    if (password.compare("1111") == 0)
    {
        setlocale(LC_ALL, "ru");
        cout << "Ciphers that you can use:" << endl;
        cout << "1) NOTEBOOK" << endl;
        cout << "2) VERNAM" << endl;
        cout << "3) CAESAR" << endl;
        cout << "4) RSA" << endl;
        cout << "5) VIGENERE" << endl;
        cout << "6) HILL" << endl;
        cout << "7) All Ciphers by 1 to 6" << endl;
        int number = 0;
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        while (cin)
        {
            cout << "\nWrite number of cipher ";
            cin >> number;
            if (cin.fail())
            {
                cout << "You write not a number of cipher!! Please write 1-7! \n";
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                if (number > 0 && number < 8)
                {
					switch (number)
					{
					case NOTEBOOK:
					{
						vector<char> letter;
						int is_gen = 0;
						cout << "Do you want to input message? Input 1, if you want: ";
						cin >> is_gen;
						if (is_gen == 1)   //Вводим сообщение
							letter = input_vector(number);
						else
							letter = input_from_file(number);
						cout << "Entered message:" << endl;
						print_vector(letter);
						vector<vector<char>> key = notebook_key();
						vector <char> result = notebook_crypt(letter, key);
						cout << endl << "Encrypted message:" << endl;
						print_vector(result);
						cout << "\nDo you want to decrypt message? Input 1, if you want: ";
						cin >> is_gen;
						if (is_gen == 1)
						{
							vector <char> result_encrypt = notebook_decrypt(result, key);
							cout << "Decrypted message:" << endl;
							print_vector(result_encrypt);
						}
						break;
					}
					case VERNAM:
					{
						vector<char> letter;
						int is_gen = 0;
						cout << "Do you want to input message? Input 1, if you want: ";
						cin >> is_gen;
						if (is_gen == 1)   //Вводим сообщение
							letter = input_vector(number);
						else
							letter = input_from_file(number);
						cout << "Entered message:" << endl;
						print_vector(letter);
						vector <int> key = vernam_key((static_cast<int> (letter.size())));
						vector<char> result = vernam_crypt(letter, key);
						cout << endl << "Encrypted message:" << endl;
						print_vector(result);
						cout << "\nDo you want to decrypt message? Input 1, if you want: ";
						cin >> is_gen;
						if (is_gen == 1)
						{
							vector <char> decrypt_result = vernam_decrypt(result, key);
							cout << "Decrypted message:" << endl;
							print_vector(decrypt_result);
						}
						break;
					}
					case CAESAR:
					{
						vector<char> letter;
						int is_gen = 0;
						cout << "Do you want to input message? Input 1, if you want: ";
						cin >> is_gen;
						if (is_gen == 1)   //Вводим сообщение
							letter = input_vector(number);
						else
							letter = input_from_file(number);
						cout << "Entered message:" << endl;
						print_vector(letter);
						vector<char> result = caesar_crypt(letter);
						cout << endl << "Encrypted message:" << endl;
						print_vector(result);
						cout << "\nDo you want to decrypt message? Input 1, if you want: ";
						cin >> is_gen;
						if (is_gen == 1)
						{
							vector<char> decrypt_result = caesar_decrypt(result);
							cout << "Decrypted message:" << endl;
							print_vector(decrypt_result);
						}
						break;
					}
					case RSA:
					{
						vector<string> results;
						string letter;
						int is_gen = 0;
						cout << "Do you want to input message? Input 1, if you want: ";
						cin >> is_gen;
						if (is_gen == 1)
						{
							letter = input_mes();
							cout << endl << "Entered message: " << endl << letter << endl;
							results = rsa(letter, 101, 59);
						}
						else
						{
							string message = input_string();
							cout << endl << "Entered message: " << endl << message << endl;
							results = rsa(message, 101, 59);
						}
						cout << "Encrypted message:" << endl << results[0] << endl;
						cout << "Do you want to decrypt this? Please, input 1, if you want: ";
						int is_decr = 0;
						cin >> is_decr;
						if (is_decr == 1)
						{
							cout << "Decrypted message:" << endl << results[1] << endl;
						}
						break;
					}
					case VIGENERE:
					{
						vector<string> results;
						string letter;
						int is_gen = 0;
						cout << "Do you want to input message? Input 1, if you want: ";
						cin >> is_gen;
						if (is_gen == 1)
						{
							string key = "key";
							cout << "Please, input key without ' ': ";
							cin >> key;
							letter = input_mes();
							cout << endl << "Entered message: " << endl << letter << endl;
							results = vigenere(letter, key);
						}
						else
						{
							string message = input_string();
							cout << endl << "Entered message: " << endl << message << endl;
							results = vigenere(message, "key");
						}
						cout << "Encrypted message:" << endl << results[0] << endl;
						cout << "Do you want to decrypt this? Please, input 1, if you want: ";
						int is_decr = 0;
						cin >> is_decr;
						if (is_decr == 1)
						{
							cout << "Decrypted message:" << endl << results[1] << endl;
						}
						break;
					}
					case HILL:
					{
						vector<string> results;
						string letter;
						int is_gen = 0;
						cout << "Do you want to input message? Input 1, if you want: ";
						cin >> is_gen;
						if (is_gen == 1)
						{
							string key = "keys123456";
							cout << "Please, input key without ' ': ";
							cin >> key;
							letter = input_mes();
							cout << endl << "Entered message: " << endl << letter << endl;
							results = hill(letter, key);
						}
						else
						{
							string message = input_string();
							cout << endl << "Entered message: " << endl << message << endl;
							results = hill(message, "keys123456");
						}
						cout << "Encrypted message:" << endl << results[0] << endl;
						cout << "Do you want to decrypt this? Please, input 1, if you want: ";
						int is_decr = 0;
						cin >> is_decr;
						if (is_decr == 1)
						{
							cout << "Decrypted message:" << endl << results[1] << endl;
						}
						break;
					}
					case ALL:
					{
						vector<string> all_crypted, results;
						string encryrp_letter, str_letter;
						//Notebook
						vector<char> letter = input_from_file(1), letter_to_decrypt;
						cout << endl << "-----------------------------------" << endl << "Entered message:" << endl;
						print_vector(letter);
						vector<vector<char>> note_key = notebook_key();
						letter_to_decrypt = notebook_crypt(letter, note_key);
						encryrp_letter = vector_to_string(letter_to_decrypt);
						vector <char> result_decrypt = notebook_decrypt(letter_to_decrypt, note_key);
						cout << endl << "Encrypted message:" << endl << encryrp_letter;
						all_crypted.push_back(encryrp_letter);
						cout << endl << "Decrypted message:" << endl;
						print_vector(result_decrypt);
						// Vernam
						letter = input_from_file(2);
						cout << endl << "-----------------------------------" << endl << "Entered message:" << endl;
						print_vector(letter);
						vector<int> vern_key = vernam_key((static_cast<int> (letter.size())));
						letter_to_decrypt = vernam_crypt(letter, vern_key);
						result_decrypt = vernam_decrypt(letter_to_decrypt, vern_key);
						encryrp_letter = vector_to_string(letter_to_decrypt);
						cout << endl << "Encrypted message:" << endl << encryrp_letter;
						all_crypted.push_back(encryrp_letter);
						cout << endl << "Decrypted message:" << endl;
						print_vector(result_decrypt);
						//Caesar
						letter = input_from_file(3);
						cout << endl << "-----------------------------------" << endl << "Entered message:" << endl;
						print_vector(letter);
						letter_to_decrypt = caesar_crypt(letter);
						result_decrypt = caesar_decrypt(letter_to_decrypt);
						encryrp_letter = vector_to_string(letter_to_decrypt);
						cout << endl << "Encrypted message:" << endl << encryrp_letter << endl;
						all_crypted.push_back(encryrp_letter);
						cout << endl << "Decrypted message:" << endl;
						print_vector(result_decrypt);
						//str
						str_letter = input_string();
						cout << endl << "-----------------------------------" << endl << "Entered message:" << endl << str_letter;
						results = rsa(str_letter, 101, 59);
						cout << endl << "Encrypted message:" << endl << results[0] << endl;
						cout << "Decrypted message:" << endl << results[1] << endl;
						all_crypted.push_back(results[0]);
						str_letter = input_string();
						cout << endl << "-----------------------------------" << endl << "Entered message:" << endl << str_letter;
						results = vigenere(str_letter, "key");
						cout << endl << "Encrypted message:" << endl << results[0] << endl;
						cout << "Decrypted message:" << endl << results[1] << endl;
						all_crypted.push_back(results[0]);
						str_letter = input_string();
						cout << endl << "-----------------------------------" << endl << "Entered message:" << endl << str_letter;
						results = hill(str_letter, "keys123456");
						cout << endl << "Encrypted message:" << endl << results[0] << endl;
						cout << "Decrypted message:" << endl << results[1] << endl;
						all_crypted.push_back(results[0]);
						fstream file("РГР.txt");//создать файл в папке проекта
						ofstream stream_to_txt;
						stream_to_txt.open("РГР.txt");
						stream_to_txt << "All crypted letters:" << endl << "-----------------------------------" << endl;
						for (string crypt : all_crypted)
						{
							stream_to_txt << crypt << endl << "-----------------------------------" << endl;
						}
						stream_to_txt.close();
						system("notepad РГР.txt");//Открыть файл
						break;
					}
					default:
						break;
					}
                }
                else
                    break;
            }
        }
        cout << "Thanks for use our programm!!";
    }
    else
        cout << "That password is incorrect!" << endl;
}


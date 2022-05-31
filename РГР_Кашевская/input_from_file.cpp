#include "input_from_file.h"

vector<char> input_from_file(int number)
{
    setlocale(0, "Ru");
	srand(time(0));
	string file_name;
	int rand_num = rand() % 3;
    if (number == 1) 
    {
		if (rand_num == 0)
		{
			file_name = "eng_letter0.txt";
		}
		else if(rand_num == 1)
		{
			file_name = "eng_letter1.txt";
		}
		else if (rand_num == 2)
		{
			file_name = "eng_letter2.txt";
		}
    }
	else if (number == 2)
	{
		if (rand_num == 0)
		{
			file_name = "any_letter0.txt";
		}
		else if (rand_num == 1)
		{
			file_name = "any_letter1.txt";
		}
		else if (rand_num == 2)
		{
			file_name = "any_letter2.txt";
		}
	}
	else if (number == 3)
	{
		if (rand_num == 0)
		{
			file_name = "cae_letter0.txt";
		}
		else if (rand_num == 1)
		{
			file_name = "cae_letter1.txt";
		}
		else if (rand_num == 2)
		{
			file_name = "cae_letter2.txt";
		}
	}
	ifstream stream_from_txt;
	stream_from_txt.open(file_name);
	vector<char> letter;
	char symbol;
	while (stream_from_txt.get(symbol))//вычитка из файла в вектор
	{
		letter.push_back(symbol);
	}
	stream_from_txt.close();
    return letter;
}

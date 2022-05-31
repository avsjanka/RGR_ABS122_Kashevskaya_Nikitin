#include "input_string_from_file.h"

string input_string()
{
	setlocale(0, "Ru");
	srand(time(0));
	string file_name;
	int rand_num = rand() % 3;
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
	ifstream stream_from_txt;
	stream_from_txt.open(file_name);
	string message_from_txt;
	char symbol;
	while (stream_from_txt.get(symbol))
	{
		message_from_txt.push_back(symbol);
	}
	stream_from_txt.close();
    return message_from_txt;
}

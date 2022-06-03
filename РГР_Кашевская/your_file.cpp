#include "your_file.h"

vector<char> your_file(string& file_name)
{
    setlocale(0, "Ru");
	cout << "Please, input name of your file without ' ': ";
	cin >> file_name;
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

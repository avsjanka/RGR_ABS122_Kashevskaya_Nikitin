#include "vernam_key.h"

vector<int> vernam_key( int size)
{
    mt19937 gen;
    gen.seed(time(0));
    vector<int> rand_vector;
    uniform_int_distribution<int> randomNum(0, 122);
    for (int i = 0; i < size ; i++)
        rand_vector.push_back(randomNum(gen));
    return rand_vector;
}

// 1.3 URLify: Algorithm to replace all spaces in a string with '%20'. String has sufficient space to hold the special characters. True length of string is passed

#include <iostream>
#include <vector>
using namespace std;

void URLify(string, int);

int main(int argc, const char * argv[])
{
    string str = "My John Smith       ";
    int length = 13;
    
    URLify(str, length);
    
    return 0;
}

void URLify(string str, int length)
{
    vector<char> string_to_char;
    int spaceCount = 0, index, i = 0;
    for (i = 0; i < str.size(); i++) string_to_char.push_back(str[i]);
    for (i = 0; i < length; i++)
    {
        if (string_to_char[i] == ' ')
        {
            spaceCount++;
        }
    }
    index = length + spaceCount * 2;
    if (length < string_to_char.size()) string_to_char.push_back('\0');
    
    for (i = length - 1; i >= 0; i--)
    {
        if (string_to_char[i] == ' ')
        {
            string_to_char[index - 1] = '0';
            string_to_char[index - 2] = '2';
            string_to_char[index - 3] = '%';
            index -= 3;
        }
        else
        {
            string_to_char[index - 1] = string_to_char[i];
            index--;
        }
    }
    
    for (i = 0; i < string_to_char.size(); i++) cout << string_to_char[i];
    cout << endl;
}

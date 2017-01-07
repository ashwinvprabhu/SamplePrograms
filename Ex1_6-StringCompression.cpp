//
//  main.cpp
//  CodingInterview
//
//  Created by Ashwin V Prabhu on 1/4/17.
//  Copyright © 2017 Ashwin Venkatesh Prabhu. All rights reserved.
//

// 1.6 A method to perform basic string compression using the counts of repeated characters
// C++ string are mutable and hence no need for StringBuilder

#include <iostream>
using namespace std;

string Compress(string);
int CountCompression(string);

int main(int argc, const char * argv[])
{
    string str = "aaaabbcccedddddffeeeaa";
    string compressed = Compress(str);
    cout << "Compressed string is: " << compressed << endl;
    
    return 0;
}

int CountCompression(string str)
{
    int compressLength = 0;
    int countConsecutive = 0;
    for (int i = 0; i < str.length(); i++)
    {
        countConsecutive++;
        if (i + 1 >= str.length() || str[i] != str[i+1])
        {
            compressLength += 1 + to_string(countConsecutive).length();
            countConsecutive = 0;
        }
    }
    return compressLength;
}

string Compress(string str)
{
    int finalLength = CountCompression(str);
    if (finalLength >= str.length()) return str;
    
    string compressed;
    int countConsecutive = 0;
    for (int i = 0; i < str.length(); i++)
    {
        countConsecutive++;
    
        if (i + 1 >= str.length() || str[i] != str[i + 1])
        {
            compressed.append(str, i, 1);
            compressed.append(to_string(countConsecutive));
            countConsecutive = 0;
        }
    }
    return compressed;
}

//
//  main.cpp
//  CodingInterview
//
//  Created by Ashwin V Prabhu on 1/4/17.
//  Copyright © 2017 Ashwin Venkatesh Prabhu. All rights reserved.
//

// 1.1 Is Unique: Implement an algprithm to determine if a string has all the unique characters. What if you cannot use additional character?
// If we can't usr additional data structures, then, (1) compare each character with every other character of the string. This will take O(n²) time
// (2) If we can modify the string, then sort the string in O(nlogn) time and linearly check for identical neighbouring characters. Sorting takes extra space
// Clarification: character-set is ASCII (128 characters), Extended ASCII (256 characters), and Unicode (2^21 characters). Depending on this the storage space will change

#include <iostream>
#define MAX_CHARACTER_VAL 128
using namespace std;

bool IsUniqueCharacters(string);

int main(int argc, const char * argv[])
{
    string str;
    cout << "Enter the string: ";
    cin >> str;
    
    if (IsUniqueCharacters(str)) cout << "String entered is unique." << endl;
    else cout << "String entered is not unique." << endl;
    
    return 0;
}

bool IsUniqueCharacters(string str)
{
    if (str.length() > MAX_CHARACTER_VAL) return false;
    
    bool *character_set = new bool[MAX_CHARACTER_VAL];
    for (int i = 0; i < str.length(); i++)
    {
        int value = str[i];
        if (character_set[value]) // true means Already found this character
        {
            return false;
        }
        character_set[value] = true;
    }
    return true;
}

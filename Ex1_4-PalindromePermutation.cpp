//
//  main.cpp
//  CodingInterview
//
//  Created by Ashwin V Prabhu on 1/4/17.
//  Copyright © 2017 Ashwin Venkatesh Prabhu. All rights reserved.
//

// 1.4 Palindrome Permutation: Check if the permutation of the string is a palindrome
// Insight into solution: Using a bit vector, we can map each letter present in the string to a bit position in the vector (0-26). Every time a character
// is encountered, the value at the bit position is toggled. The final value of the bit position can have 1 at atmost one position (in case of odd numbered
// string, odd character will be in the middle, and in case of even numbered string, all characters appears in multiples of 2 times).

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool CheckExactlyOneBitSet(int);
int Toggle(int, int);
int CreateBitVector(string);
bool IsPermutationPalindrome(string);
int GetCharNumber(char c);

int main(int argc, const char * argv[])
{
    string str = "Tact Coaa";
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    if (IsPermutationPalindrome(str)) cout << "Permutation of string \"" << str << "\" is a palindrome" << endl;
    else cout << "Permutation of string \"" << str << "\" is not a palindrome" << endl;
    
    return 0;
}

bool CheckExactlyOneBitSet(int bitVector)
{
    return ((bitVector & (bitVector - 1)) == 0);
}

int Toggle(int bitVector, int index)
{
    if (index < 0) return bitVector;
    
    int mask = 1 << index;
    if ((bitVector & mask) == 0) // If the character has already been encountered once or not?
    {
        bitVector |= mask; // If not encountered, then toggle the bit position
    }
    else
    {
        bitVector &= ~mask; // If encountered, then toggle the bit position
    }
    return bitVector;
}

int CreateBitVector(string str)
{
    int bitVector = 0;
    vector<char> string_to_char;
    for (int i = 0; i < str.size(); i++) string_to_char.push_back(str[i]);
    
    for (int j = 0; j < string_to_char.size(); j++)
    {
        int x = GetCharNumber(string_to_char[j]);
        bitVector = Toggle(bitVector, x);
    }
    return bitVector;
}

bool IsPermutationPalindrome(string str)
{
    int bitVector = CreateBitVector(str);
    return (bitVector == 0 || CheckExactlyOneBitSet(bitVector));
}

int GetCharNumber(char c)
{
    int a = 'a';
    int z = 'z';
    int numeric_c = c;
    
    if (a <= numeric_c && numeric_c <= z) return numeric_c - a;
    return -1;
}

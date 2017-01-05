//
//  main.cpp
//  CodingInterview
//
//  Created by Ashwin V Prabhu on 1/4/17.
//  Copyright © 2017 Ashwin Venkatesh Prabhu. All rights reserved.
//

// 1.2 Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.
// Clarification: Does the whitespace matter? Is the string case sensitive (is God and permutation of dog?)

#include <iostream>
#include <vector>
using namespace std;

vector<char> SortStrings(string);
bool CheckPermutation(string, string);

int main(int argc, const char * argv[])
{
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;
    
    if (CheckPermutation(str1, str2)) cout << "First string is a permutation of second string" << endl;
    else cout << "First string is not a permutation of second string" << endl;
    
    return 0;
}

vector<char> SortStrings(string str)
{
    vector<char> string_to_char;
    for (int i = 0; i < str.size(); i++) string_to_char.push_back(str[i]);
    sort(string_to_char.begin(), string_to_char.end());
    return string_to_char;
}

bool CheckPermutation(string str1, string str2)
{
    if (str1.size() != str2.size()) return false;
    vector<char> sorted_str1 = SortStrings(str1);
    vector<char> sorted_str2 = SortStrings(str2);
    return equal(sorted_str1.begin(), sorted_str1.end(), sorted_str2.begin());
}

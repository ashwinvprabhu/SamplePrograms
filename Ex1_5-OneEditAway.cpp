//
//  main.cpp
//  CodingInterview
//
//  Created by Ashwin V Prabhu on 1/4/17.
//  Copyright © 2017 Ashwin Venkatesh Prabhu. All rights reserved.
//

// 1.5 One Away: Given two string, check if they are one or zero edits away
// Implementation: Need to determine how many letters in the two string are string are different.
// In case of insertion and deletion, one string is shorter by one than the other.
// In case of replacement, both strings are of same length, but one or no charater is different

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool OneEditAway(string, string);

int main(int argc, const char * argv[])
{
    string first = "pale", second = "bae";
    
    if (OneEditAway(first, second)) cout << "One edit away" << endl;
    else cout << "Not one edit away" << endl;
    
    return 0;
}

bool OneEditAway(string first, string second)
{
    if (abs((int)(first.length() - second.length())) > 1) return false;
    
    string s1 = first.length() < second.length() ? first : second;
    string s2 = first.length() < second.length() ? second : first;
    
    int index1 = 0, index2 = 0;
    bool foundDifference = false;
    
    while (index1 <= first.length() && index2 <= second.length())
    {
        if (s1[index1] != s2[index2])
        {
            // First difference found
            if (foundDifference) return false;
            foundDifference = true;
            
            if (s1.length() == s2.length()) index1++;
        }
        else
        {
            index1++;
        }
        index2++;
    }
    return true;
}

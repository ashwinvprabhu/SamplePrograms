//
//  main.cpp
//  CodingInterview
//
//  Created by Ashwin V Prabhu on 1/4/17.
//  Copyright © 2017 Ashwin Venkatesh Prabhu. All rights reserved.
//

// 1.8 Algorithm to set a row and column of an element to 0 if the element in the matrix is 0

#include <iostream>
#include <vector>
using namespace std;

void SetZeros(vector<vector<int>>);
vector<vector<int>> NullifyRows(vector<vector<int>>, size_t);
vector<vector<int>> NullifyColumns(vector<vector<int>>, size_t);

int main(int argc, const char * argv[])
{
    vector<vector<int>> m = {{1, 2, 3, 4}, {5, 6, 0, 8}, {1, 0, 1, 1}, {2, 2, 2, 2}};
    SetZeros(m);
    return 0;
}

vector<vector<int>> NullifyRows(vector<vector<int>> m, size_t row)
{
    for (int j = 0; j < m.size(); j++)
    {
        m[row][j] = 0;
    }
    
    return m;
}

vector<vector<int>> NullifyColumns(vector<vector<int>> m, size_t column)
{
    for (int i = 0; i < m[0].size(); i++)
    {
        m[i][column] = 0;
    }
    
    return m;
}

void SetZeros(vector<vector<int>> m)
{
    size_t row = m.size();
    size_t column = m[0].size();
    bool *rows = new bool[row];
    bool *columns = new bool[column];
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (m[i][j] == 0)
            {
                rows[i] = true;
                columns[j] = true;
            }
        }
    }
    
    for (int i = 0; i < row; i++)
    {
        if (rows[i])
        {
            m = NullifyRows(m, i);
        }
    }
    
    for (int j = 0; j < column; j++)
    {
        if (columns[j])
        {
            m = NullifyColumns(m, j);
        }
    }
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

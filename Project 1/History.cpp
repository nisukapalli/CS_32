//
//  History.cpp
//  Project 1
//
//  Created by Nikhil Isukapalli on 1/10/21.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
using namespace std;

#include "History.h"

History::History(int nRows, int nCols) {
    m_rows = nRows;
    m_cols = nCols;
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            m_histArr[i][j] = 0;    //initialize array
        }
    }
    
}

bool History::record(int r, int c) {
    if (r < 1 || c < 1 || r > m_rows || c > m_cols)
        return false;
    if (m_histArr[r-1][c-1] < 26)   //stop incrementing after 26
        m_histArr[r-1][c-1]++;
    return true;
}

void History::display() const {
    
    clearScreen();
    
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            
            int count = m_histArr[i][j];
            if (count == 0)
                cout << (char)(46);     //ASCII value for '.'
            else
                cout << (char)(64+count);   //ASCII values for 'A' to 'Z'
                
        }
        cout << endl;   //new row
    }
    cout << endl;   //new line after array is printed
}

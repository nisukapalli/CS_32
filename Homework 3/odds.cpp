//
//  odds.cpp
//  Homework 3
//
//  Created by Nikhil Isukapalli on 2/28/21.
//
/*
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

  // Remove the odd integers from v.
  // It is acceptable if the order of the remaining even integers is not
  // the same as in the original vector.
void removeOdds(vector<int>& v)
{
    //iterator
    vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        //if element is odd
        if (*it % 2 != 0)
        {
            //erase element
            v.erase(it);
        }
        else
        {
            //go to next element
            it++;
        }
    }
}

void test()
{
    int a[8] = { 2, 8, 5, 6, 7, 3, 4, 1 };
    vector<int> x(a, a+8);  // construct x from the array
    assert(x.size() == 8 && x.front() == 2 && x.back() == 1);
    removeOdds(x);
    assert(x.size() == 4);
    sort(x.begin(), x.end());
    int expect[4] = { 2, 4, 6, 8 };
    for (int k = 0; k < 4; k++)
        assert(x[k] == expect[k]);
}

int main()
{
    test();
    cout << "Passed" << endl;
}
*/

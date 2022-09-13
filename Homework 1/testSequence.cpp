//
//  testSequence.cpp
//  Homework 1
//
//  Created by Nikhil Isukapalli on 1/16/21.
//

#include "Sequence.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

int main()
{
    Sequence s;
    s.insert(0, 1);
    s.insert(1, 2);
    s.insert(2, 3);
    s.insert(3, 2);
    s.insert(4, 5);
    assert(s.remove(2) == 2);
    assert(s.size() == 3);
    ItemType x;
    assert(s.get(0, x)  &&  x == 1);
    assert(s.get(1, x)  &&  x == 3);
    assert(s.get(2, x)  &&  x == 5);
    
    Sequence s1;
    s1.insert(0, 10);
    s1.insert(0, 20);
    Sequence s2;
    s2.insert(0, 30);
    s1.swap(s2);
    assert(s1.size() == 1  &&  s1.find(30) == 0  &&  s2.size() == 2  &&
                s2.find(20) == 0  &&  s2.find(10) == 1);
    
    Sequence s3;
    s3.insert(0, 10);
    s3.insert(0, 20);
    assert(s3.size() == 2);
    ItemType y = 999;
    assert(s3.get(0, y) && y == 20);
    assert(s3.get(1, y) && y == 10);
    
    cout << "Passed all tests" << endl;
}

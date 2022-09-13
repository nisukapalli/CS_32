//
//  testScoreList.cpp
//  Homework 1
//
//  Created by Nikhil Isukapalli on 1/17/21.
//

#include "ScoreList.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;


int main() {
    
    ScoreList s1;
    s1.add(90);
    s1.add(80);
    s1.add(100);
    s1.add(80);
    cout << "size: " << s1.size() << endl;
    cout << "minimum: " << s1.minimum() << endl;
    cout << "maximum: " << s1.maximum() << endl;
    s1.remove(80);
    cout << "size: " << s1.size() << endl;
    cout << "minimum: " << s1.minimum() << endl;
    cout << "maximum: " << s1.maximum() << endl;
    s1.remove(80);
    cout << "size: " << s1.size() << endl;
    cout << "minimum: " << s1.minimum() << endl;
    cout << "maximum: " << s1.maximum() << endl;
    s1.remove(100);
    cout << "size: " << s1.size() << endl;
    cout << "minimum: " << s1.minimum() << endl;
    cout << "maximum: " << s1.maximum() << endl;
    s1.remove(90);
    cout << "size: " << s1.size() << endl;
    cout << "minimum: " << s1.minimum() << endl;
    cout << "maximum: " << s1.maximum() << endl;
    
    cout << "Passed all tests" << endl;
}

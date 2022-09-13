//
//  eval.cpp
//  Homework 2
//
//  Created by Nikhil Isukapalli on 1/30/21.
//

#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cassert>
using namespace std;

int evaluate(string infix, const bool values[], string& postfix, bool& result) {
    
    stack<char> ops;
    postfix = "";
    if (infix.size() == 0) {
        return 1;
    }
    int i = 0;
    while (i < infix.size()) {
        if (infix[i] != ' ') {
            i++;
        }
        else {
            for (int j = i; j < infix.size()-1; j++) {
                infix[j] = infix[j+1];
            }
            infix.resize(infix.size()-1);
        }
    }
    
    if (infix[0] == ')' || infix[0] == '&' || infix[0] == '|') {
        return 1;
    }
    char last = infix[infix.size()-1];
    if (last == '(' || last == '!' || last == '&' || last == '|') {
        return 1;
    }
    
    int numOpen = 0;
    int numClosed = 0;
    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(') {
            numOpen++;   //count open parentheses
            if (i > 0 && isdigit(infix[i-1])) {
                return 1;
            }
            if (i < infix.size()-1 && infix[i+1] == ')') {
                return 1;
            }
            if (i < infix.size()-1 && (infix[i+1] == '&' || infix[i+1] == '|')) {
                return 1;
            }
        }
        if (infix[i] == ')') {
            numClosed++;
            if (i < infix.size()-1 && isdigit(infix[i+1])) {
                return 1;
            }
            if (i < infix.size()-1 && infix[i+1] == '(') {
                return 1;
            }
            if (i > 0 && (infix[i-1] == '&' || infix[i-1] == '|')) {
                return 1;
            }
        }
        if (isdigit(infix[i])) {
            if (i < infix.size()-1 && isdigit(infix[i+1])) {
                return 1;
            }
        }
        if (infix[i] == '&' || infix[i] == '|') {
            if (infix[i-1] == '&' || infix[i+1] == '&') {
                return 1;
            }
            if (infix[i-1] == '|' || infix[i+1] == '|') {
                return 1;
            }
        }
    }
    if (numOpen != numClosed) {
        return 1;
    }
    
    for (int i = 0; i < infix.size(); i++) {
        switch (infix[i]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                postfix += infix[i];
                break;
            case '(':
                ops.push(infix[i]);
                break;
            case ')':
                while(! ops.empty() && ops.top() != '(') {
                    postfix += ops.top();
                    ops.pop();
                }
                if (! ops.empty()) {
                    ops.pop();
                }
                break;
            case '!':
                ops.push(infix[i]);
                break;
            case '&':
            case '|':
                while (! ops.empty() && ops.top() != '(') { //order of precedence
                    if (infix[i] == '!' && (ops.top() == '&' || ops.top() == '|')) {
                        break;
                    }
                    else if (infix[i] == '&' && ops.top() == '|') {
                        break;
                    }
                    else {
                        postfix += ops.top();
                        ops.pop();
                    }
                }
                ops.push(infix[i]);
                break;
            default:
                return 1;
        }
    }
    while(! ops.empty()) {
        postfix += ops.top();
        ops.pop();
    }
    
    stack<bool> vals;
    for (int i = 0; i < postfix.size(); i++) {
        if (isdigit(postfix[i])) {
            vals.push(values[postfix[i]-'0']);
        }
        else if (postfix[i] == '!') {
            bool firstVal = vals.top();
            vals.pop();
            vals.push(!firstVal);
        }
        else if (postfix[i] == '&') {
            bool firstVal = vals.top();
            vals.pop();
            bool secondVal = vals.top();
            vals.pop();
            vals.push(secondVal && firstVal);
        }
        else if (postfix[i] == '|') {
            bool firstVal = vals.top();
            vals.pop();
            bool secondVal = vals.top();
            vals.pop();
            vals.push(secondVal || firstVal);
        }
        else {
            return 1;
        }
    }
    if (! vals.empty()) {
        result = vals.top();
    }
    return 0;
}

int main() {
    bool ba[10] = {
      //  0      1      2      3      4      5      6      7      8      9
        true,  true,  true,  false, false, false, true,  false, true,  false
    };
    string pf;
    bool answer;
    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf == "23|" &&  answer);
    assert(evaluate("8|", ba, pf, answer) == 1);
    assert(evaluate(" &6", ba, pf, answer) == 1);
    assert(evaluate("4 5", ba, pf, answer) == 1);
    assert(evaluate("01", ba, pf, answer) == 1);
    assert(evaluate("()", ba, pf, answer) == 1);
    assert(evaluate("()4", ba, pf, answer) == 1);
    assert(evaluate("2(9|8)", ba, pf, answer) == 1);
    assert(evaluate("2(&8)", ba, pf, answer) == 1);
    assert(evaluate("(6&(7|7)", ba, pf, answer) == 1);
    assert(evaluate("x+5", ba, pf, answer) == 1);
    assert(evaluate("", ba, pf, answer) == 1);
    assert(evaluate("2|3|4", ba, pf, answer) == 0
                           &&  pf == "23|4|"  &&  answer);
    assert(evaluate("2|(3|4)", ba, pf, answer) == 0
                           &&  pf == "234||"  &&  answer);
    assert(evaluate("4  |  !3 & (0&3) ", ba, pf, answer) == 0
                           &&  pf == "43!03&&|"  &&  !answer);
    assert(evaluate(" 9  ", ba, pf, answer) == 0  &&  pf == "9"  &&  !answer);
    ba[2] = false;
    ba[9] = true;
    assert(evaluate("((9))", ba, pf, answer) == 0  &&  pf == "9"  &&  answer);
    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf == "23|" &&  !answer);
    cout << "Passed all tests" << endl;
}

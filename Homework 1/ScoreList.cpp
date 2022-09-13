//
//  ScoreList.cpp
//  Homework 1
//
//  Created by Nikhil Isukapalli on 1/17/21.
//

#include "ScoreList.h"
#include "Sequence.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

ScoreList::ScoreList() {
    init = true;
}

bool ScoreList::add(unsigned long score) {
    if (score > 100) {
        return false;
    }
    return m_list.insert(m_list.size(), score);
}

bool ScoreList::remove(unsigned long score) {
    int pos = m_list.find(score);
    return m_list.erase(pos);
}

int ScoreList::size() const {
    return m_list.size();
}

unsigned long ScoreList::minimum() const {
    if (m_list.size() <= 0) {
        return NO_SCORE;
    }
    unsigned long minScore;
    m_list.get(0, minScore);
    
    unsigned long otherScore;
    for (int i = 0; i < m_list.size(); i++) {
        m_list.get(i, otherScore);
        if (otherScore < minScore) {
            minScore = otherScore;
        }
    }
    return minScore;
}

unsigned long ScoreList::maximum() const {
    if (m_list.size() <= 0) {
        return NO_SCORE;
    }
    unsigned long maxScore;
    m_list.get(0, maxScore);
    
    unsigned long otherScore;
    for (int i = 0; i < m_list.size(); i++) {
        m_list.get(i, otherScore);
        if (otherScore > maxScore) {
            maxScore = otherScore;
        }
    }
    return maxScore;
}

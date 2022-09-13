//
//  ScoreList.h
//  Homework 1
//
//  Created by Nikhil Isukapalli on 1/17/21.
//

#ifndef ScoreList_h
#define ScoreList_h

#include "Sequence.h"
#include <limits>
#include <stdio.h>

const unsigned long NO_SCORE = std::numeric_limits<unsigned long>::max();

class ScoreList
{
  public:
    ScoreList();
    bool add(unsigned long score);
    bool remove(unsigned long score);
    int size() const;
    unsigned long minimum() const;
    unsigned long maximum() const;
  private:
    Sequence m_list;
    bool init;
};

#endif /* ScoreList_h */

//
//  Sequence.h
//  Homework 1
//
//  Created by Nikhil Isukapalli on 1/16/21.
//

#ifndef Sequence_h
#define Sequence_h

#include <stdio.h>
#include <iostream>
#include <string>

typedef unsigned long ItemType;

const int DEFAULT_MAX_ITEMS = 150;

class Sequence
{
  public:
    Sequence();
    bool empty() const;
    int size() const;
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
  private:
    ItemType m_arr[DEFAULT_MAX_ITEMS];
    int m_size;
};

#endif /* Sequence_h */

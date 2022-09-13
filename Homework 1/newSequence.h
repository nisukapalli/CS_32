//
//  newSequence.h
//  Homework 1
//
//  Created by Nikhil Isukapalli on 1/18/21.
//

#ifndef newSequence_h
#define newSequence_h

#include <stdio.h>
#include <iostream>
#include <string>

typedef unsigned long ItemType;

const int DEFAULT_MAX_ITEMS = 150;

class Sequence
{
  public:
    Sequence();     //default constructor
    Sequence(int num);      //overloaded constructor
    Sequence(const Sequence &original);  //copy constructor
    ~Sequence();    //destructor
    Sequence &operator=(const Sequence &src);   //assignment operator
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
    ItemType* m_arr;
    int m_maxSize;
    int m_currentSize;
};

#endif /* newSequence_h */

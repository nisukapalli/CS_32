//
//  newSequence.cpp
//  Homework 1
//
//  Created by Nikhil Isukapalli on 1/18/21.
//

#include "newSequence.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

Sequence::Sequence() {
    m_maxSize = DEFAULT_MAX_ITEMS;
    m_arr = new ItemType[DEFAULT_MAX_ITEMS];
    m_currentSize = 0;
}

Sequence::Sequence(int num) {
    if (num < 0) {
        exit(1);
    }
    m_maxSize = num;
    m_arr = new ItemType[num];
    m_currentSize = 0;
}

Sequence::Sequence(const Sequence &original) {
    m_maxSize = original.m_maxSize;
    m_arr = new ItemType[m_maxSize];
    m_currentSize = original.m_currentSize;
    for (int i = 0; i < m_currentSize; i++) {
        m_arr[i] = original.m_arr[i];
    }
}

Sequence::~Sequence() {
    delete [] m_arr;
}

Sequence& Sequence::operator=(const Sequence &src) {
    if (&src == this) {
        return *this;
    }
    delete [] src.m_arr;
    m_maxSize = src.m_maxSize;
    m_arr = new ItemType[m_maxSize];
    m_currentSize = src.m_currentSize;
    for (int i = 0; i < m_currentSize; i++) {
        m_arr[i] = src.m_arr[i];
    }
    return *this;
}

bool Sequence::empty() const {
    if (m_currentSize == 0) {
        return true;
    }
    return false;
}

int Sequence::size() const {
    return m_currentSize;
}

int Sequence::insert(int pos, const ItemType& value) {
    if (size() >= m_maxSize) {
        return -1;
    }
    if (pos < 0 || pos > size()) {
        return -1;
    }
    
    for (int i = size(); i > pos; i--) {
        m_arr[i] = m_arr[i-1];
    }
    m_arr[pos] = value;
    m_currentSize++;
    return pos;
}

int Sequence::insert(const ItemType& value) {
    if (size() >= m_maxSize) {
        return -1;
    }
    int p = -1;
    for (int i = 0; i < size(); i++) {
        if (value <= m_arr[i]) {
            p = i;
            break;
        }
    }
    if (p < 0) {
        p = size();
    }
    for (int i = size(); i > p; i--) {
        m_arr[i] = m_arr[i-1];
    }
    m_arr[p] = value;
    m_currentSize++;
    return p;
}

bool Sequence::erase(int pos) {
    if (pos < 0 || pos >= size()) {
        return false;
    }
    for (int i = pos; i < size()-1; i++) {
        m_arr[i] = m_arr[i+1];
    }
    m_currentSize--;
    return true;
}

int Sequence::remove(const ItemType& value) {
    int count = 0;
    for (int i = size()-1; i >= 0; i--) {
        if (m_arr[i] == value) {
            this->erase(i);
            count++;
        }
    }
    return count;
}

bool Sequence::get(int pos, ItemType& value) const {
    if (pos < 0 || pos >= m_currentSize) {
        return false;
    }
    value = m_arr[pos];
    return true;
}

bool Sequence::set(int pos, const ItemType& value) {
    if (pos < 0 || pos >= m_currentSize) {
        return false;
    }
    m_arr[pos] = value;
    return true;
}

int Sequence::find(const ItemType& value) const {
    for (int i = 0; i < m_currentSize; i++) {
        if (m_arr[i] == value) {
            return i;
        }
    }
    return -1;
}

void Sequence::swap(Sequence& other) {
    ItemType* tempPtr = nullptr;
    int tempMaxSize;
    int tempCurrentSize;
    
    tempMaxSize = m_maxSize;
    m_maxSize = other.m_maxSize;
    other.m_maxSize = tempMaxSize;
    
    tempCurrentSize = m_currentSize;
    m_currentSize = other.m_currentSize;
    other.m_currentSize = tempCurrentSize;
    
    tempPtr = m_arr;
    m_arr = other.m_arr;
    other.m_arr = tempPtr;
}

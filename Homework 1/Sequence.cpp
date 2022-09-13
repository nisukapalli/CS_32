//
//  Sequence.cpp
//  Homework 1
//
//  Created by Nikhil Isukapalli on 1/16/21.
//

#include "Sequence.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

Sequence::Sequence() {
    m_size = 0;
}

bool Sequence::empty() const {
    if (m_size == 0) {
        return true;
    }
    return false;
}

int Sequence::size() const {
    return m_size;
}

int Sequence::insert(int pos, const ItemType& value) {
    if (size() >= DEFAULT_MAX_ITEMS) {
        return -1;
    }
    if (pos < 0 || pos > size()) {
        return -1;
    }
    
    for (int i = size(); i > pos; i--) {
        m_arr[i] = m_arr[i-1];
    }
    m_arr[pos] = value;
    m_size++;
    return pos;
}

int Sequence::insert(const ItemType& value) {
    if (size() >= DEFAULT_MAX_ITEMS) {
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
    m_size++;
    return p;
}

bool Sequence::erase(int pos) {
    if (pos < 0 || pos >= size()) {
        return false;
    }
    for (int i = pos; i < size()-1; i++) {
        m_arr[i] = m_arr[i+1];
    }
    m_size--;
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
    if (pos < 0 || pos >= size()) {
        return false;
    }
    value = m_arr[pos];
    return true;
}

bool Sequence::set(int pos, const ItemType& value) {
    if (pos < 0 || pos >= size()) {
        return false;
    }
    m_arr[pos] = value;
    return true;
}

int Sequence::find(const ItemType& value) const {
    for (int i = 0; i < size(); i++) {
        if (m_arr[i] == value) {
            return i;
        }
    }
    return -1;
}

void Sequence::swap(Sequence& other) {
    ItemType tempItem;
    int greaterSize;
    int tempSize = this->size();
    if (other.size() > this->size()) {
        greaterSize = other.size();
    }
    else {
        greaterSize = this->size();
    }
    for (int i = 0; i < greaterSize; i++) {
        tempItem = other.m_arr[i];
        other.m_arr[i] = m_arr[i];
        m_arr[i] = tempItem;
    }
    this->m_size = other.size();
    other.m_size = tempSize;
}

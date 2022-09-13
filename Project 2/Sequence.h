//
//  Sequence.h
//  Project 2
//
//  Created by Nikhil Isukapalli on 1/23/21.
//

#ifndef Sequence_h
#define Sequence_h

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>

using ItemType = std::string;

class Sequence
{
  public:
    Sequence();     //constructor
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
    struct Node {
        ItemType value;
        Node* next;
        Node* prev;
    };
    
    ItemType getValue(int pos) const;
    void getHead(Node*& val) const;
    void getTail(Node*& val) const;
    void setValue(int pos, const ItemType& val);
    void addNode(int pos, const ItemType& val);
    void deleteNode(int pos);
    
    Node* m_head;
    Node* m_tail;
    int m_size;
    
};

int subsequence(const Sequence& seq1, const Sequence& seq2);
void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);

#endif /* Sequence_h */

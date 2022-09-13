//
//  Sequence.cpp
//  Project 2
//
//  Created by Nikhil Isukapalli on 1/23/21.
//

#include "Sequence.h"

Sequence::Sequence() : m_size(0) {  //initialize m_size
    m_head = nullptr;
    m_tail = nullptr;
}

Sequence::Sequence(const Sequence &original) : m_size(0) {  //initialize m_size
    
    for (int i = 0; i < original.m_size; i++) {
        ItemType val;
        original.get(i, val);
        insert(i, val); //copy values
    }
    m_size = original.size();
}

Sequence::~Sequence() {
    if (m_head == nullptr) {    //empty list
    }
    else if (m_head->next == nullptr) {  //1 Node in list
        delete m_head;
    }
    else {
        Node* p = m_head->next;
        Node* temp = m_head;
        while (p != nullptr) {  //delete each Node
            delete temp;
            temp = p;
            p = p->next;
        }
        delete temp;
    }
}

Sequence& Sequence::operator=(const Sequence &src) {
    if (&src == this) { //if both lists are equal
        return *this;
    }
    for (int i = 0; i < m_size; i++) {  //clear memory
        erase(i);
    }
    m_size = 0; //reset size
    ItemType temp;  //get values in src
    for (int i = 0; i < src.size(); i++) {
        src.get(i, temp);
        insert(i, temp);    //copy values
    }
    return *this;
}

bool Sequence::empty() const {
    return m_size == 0; //if sequence is empty
}

int Sequence::size() const {
    return m_size;  //return size
}

int Sequence::insert(int pos, const ItemType& value) {
    
    if (pos < 0) {
        return -1;
    }
    if (pos > m_size) {
        return -1;
    }
    addNode(pos, value);    //add Node at position
    m_size++;   //increment size
    return pos;
}

int Sequence::insert(const ItemType& value) {
    int p = 0;
    if (size() == 0) {
        Node* newNode = new Node;   //create new Node at head
        Node* temp = m_head;
        newNode->value = value;   //copy value
        newNode->next = temp;   //redirect pointers
        m_head = newNode;
        newNode->prev = nullptr;
        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        }
        else {
            m_tail = newNode;
        }
    }
    else {
        while (p < m_size && getValue(p) <= value) {    //find position
            p++;
        }
        addNode(p, value);  //add Node
    }
    m_size++;
    return p;
}

bool Sequence::erase(int pos) {
    if (pos < 0) {
        return false;
    }
    if (pos >= m_size) {
        return false;
    }
    deleteNode(pos);    //delete Node
    m_size--;
    return true;
}

int Sequence::remove(const ItemType& value) {
    int num = 0;    //number of Nodes removed
    int i = 0;
    while (i < m_size) {
        if (getValue(i) == value) { //if value matches
            erase(i);   //delete Node
            num++;
        }
        else {
            i++;
        }
    }
    return num;
}

bool Sequence::get(int pos, ItemType& value) const {
    if (pos < 0) {
        return false;
    }
    if (pos >= m_size) {
        return false;
    }
    value = getValue(pos);  //copy value of Node
    return true;
}

bool Sequence::set(int pos, const ItemType& value) {
    if (pos < 0) {
        return false;
    }
    if (pos >= m_size) {
        return false;
    }
    setValue(pos, value);   //update value of Node
    return true;
}

int Sequence::find(const ItemType& value) const {
    int pos = 0;
    for (Node* temp = m_head; temp != nullptr; temp = temp->next) {
        if (temp->value == value) {
            return pos;     //find first occurrence of value
        }
        pos++;
    }
    return -1;
}

void Sequence::swap(Sequence& other) {
    int tempSize = other.size();    //swap sizes
    other.m_size = size();
    m_size = tempSize;
    
    Node* tempThis = nullptr;
    Node* tempOther = nullptr;
    getHead(tempThis);     //swap heads
    other.getHead(tempOther);
    m_head = tempOther;
    other.m_head = tempThis;

    getTail(tempThis);     //swap tails
    other.getTail(tempOther);
    m_tail = tempOther;
    other.m_tail = tempThis;
}

ItemType Sequence::getValue(int pos) const {
    Node* temp = m_head;
    for (int i = 0; i < pos && temp->next != nullptr; i++) {
        temp = temp->next;
    }
    return temp->value;     //return value of Node
}


void Sequence::getHead(Node*& val) const {
    val = m_head;   //return head pointer
}

void Sequence::getTail(Node*& val) const {
    val = m_tail;   //return tail pointer
}

void Sequence::setValue(int pos, const ItemType& val) {
    Node* temp = m_head;
    for (int i = 0; i < pos && temp != nullptr; i++) {
        temp = temp->next;
    }
    temp->value = val;  //update value of Node
}

void Sequence::addNode(int pos, const ItemType& val) {
    
    Node* newNode = new Node;   //create new Node
    newNode->value = val;   //copy value
    
    if (m_head == nullptr) {    //empty list
        newNode->next = nullptr;
        newNode->prev = nullptr;
        m_head = newNode;
        m_tail = newNode;
    }
    else if (pos == 0) {    //first Node in list
        newNode->next = m_head;   //start from head
        newNode->prev = nullptr;
        m_head->prev = newNode;
        m_head = newNode;
    }
    else if (pos == size()) {   //last Node in list
        newNode->prev = m_tail; //start from tail
        newNode->next = nullptr;
        m_tail->next = newNode;
        m_tail = newNode;
    }
    else {  //between 2 Nodes
        Node* temp1 = m_head;    //go to previous Node
        for (int i = 0; i < pos-1 && temp1->next != nullptr; i++) {
            temp1 = temp1->next;
        }
        Node* temp2 = temp1->next;  //next Node
        newNode->next = temp2;
        newNode->prev = temp1;
        temp2->prev = newNode;
        temp1->next = newNode;
    }
}

void Sequence::deleteNode(int pos) {
    if (m_head == nullptr) {  //empty list
        return;
    }
    else if (pos == 0 && size() == 1) {     //only Node in list
        Node* p = m_head;   //Node to be deleted
        m_head = nullptr;
        m_tail = nullptr;
        delete p;
    }
    else if (pos == 0 && size() > 1) {  //first Node in list
        Node* p = m_head;   //Node to be deleted
        m_head = p->next;
        m_head->prev = nullptr;
        delete p;
    }
    else if (pos == size()-1) { //last Node in list
        Node* p = m_tail;   //Node to be deleted
        m_tail = p->prev;
        m_tail->next = nullptr;
        delete p;
    }
    else {      //between 2 Nodes
        Node* p = m_head;    //Node to be deleted
        for (int i = 0; i < pos && p->next != nullptr; i++) {
            p = p->next;
        }
        Node* temp1 = p->prev;  //previous Node
        Node* temp2 = p->next;  //next Node
        if (temp1 != nullptr && temp2 != nullptr) {
            temp1->next = temp2;    //link previous to next
            temp2->prev = temp1;    //link next to previous
            delete p;
        }
    }
}

int subsequence(const Sequence& seq1, const Sequence& seq2) {
    int size1 = seq1.size();
    int size2 = seq2.size();
    int p1;
    int p2 = 0;
    int pos;
    ItemType val1;
    ItemType val2;
    
    if (size1 < size2) {
        return -1;
    }
    if (seq1.empty() == true || seq2.empty() == true) {
        return -1;
    }
    while (true) {
        p1 = 0;
        seq1.get(p1, val1);
        seq2.get(p1, val2);
        while (p1 < size1 && val1 != val2) {    //find where val1 == val2
            p1++;
            seq1.get(p1, val1);
        }
        pos = p1;
        if (p1 >= size1) {  //if val1 never equals val2
            return -1;
        }
        bool check = true;  //if seq2 is contained in seq1
        while (check == true && p1 < size1 && p2 < size2) {
            if (val1 != val2) {
                check = false;
            }
            else {
                p1++;
                seq1.get(p1, val1);
                p2++;
                seq2.get(p2, val2);
            }
        }
        if (p2 == size2) {
            return pos;
        }
        break;
    }
    return -1;
}

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result) {
    Sequence temp;
    ItemType val1;
    ItemType val2;
    int size1 = seq1.size();
    int size2 = seq2.size();
    int p1 = 0;
    int p2 = 0;
    if (seq1.empty() && seq2.empty()) {
        temp = seq1;
        result = temp;  //set result to empty list
    }
    if (seq1.empty()) {
        temp = seq2;
        result = temp;  //set result to seq2
    }
    if (seq2.empty()) {
        temp = seq1;
        result = temp;  //set result to seq1
    }
    int tempPos = 0;
    while (p1 < size1 || p2 < size2) {  //if both lists haven't ended
        if (p1 < size1) {
            seq1.get(p1, val1);
            temp.insert(tempPos, val1); //add value in seq1 to temp
            p1++;
            tempPos++;
        }
        if (p2 < size2) {
            seq2.get(p2, val2);
            temp.insert(tempPos, val2); //add value in seq2 to temp
            p2++;
            tempPos++;
        }
    }
    result = temp;  //copy temp to result
}

/*
* File Name: lookupTable.h
* Assignment: Lab 3 Exercise C
* Lab Section: B01
* Completed by: Abhilash Paul & Seethal Elias
* Submission Date: Oct 2, 2024
*/

#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H

#include <iostream>
#include "customer.h"

using namespace std;

// class LookupTable: GENERAL CONCEPTS
//
//    key/datum pairs are ordered.  The first pair is the pair with
//    the lowest key, the second pair is the pair with the second
//    lowest key, and so on.  This implies that you must be able to
//    compare two keys with the < operator.
//
//    Each LookupTable has an embedded iterator class that allows users
//    of the class to traverse trhough the list and  have acess to each
//    node. 

//    In this version of the LookupTable a new struct type called Pair
//    is introduced which represents a key/data pair.


template <class KeyType, class DatumType>
class LookupTable;

template <typename KeyType, typename DatumType>
struct Pair
{
    Pair(KeyType keyA, DatumType datumA) : key(keyA), datum(datumA){};
    KeyType key;
    DatumType datum;
};


template <typename KeyType, typename DatumType>
class LT_Node {
private:
    Pair<KeyType, DatumType> pairM;
    LT_Node* nextM;
    // This ctor should be convenient in insert and copy operations.
    LT_Node(const Pair<KeyType, DatumType>& pairA, LT_Node *nextA): pairM(pairA), nextM(nextA){};
    friend class LookupTable<KeyType, DatumType>;
};

template <typename KeyType, typename DatumType>
class LookupTable {
public:
  class Iterator {
      LookupTable * LT;
  public:
      Iterator():LT(0){}
      Iterator(LookupTable& x): LT(&x){}
      const DatumType& operator *();
      const DatumType& operator ++();
      const DatumType& operator ++(int);
      int operator !();
      void step_fwd();
  };

    LookupTable(): sizeM(0), headM(0), cursorM(0){};
    
    LookupTable(const LookupTable& source);
    
    ~LookupTable();
    
    LookupTable& operator = (const LookupTable& rhs);

    LookupTable& begin();

    int size() const;
    // PROMISES: Returns number of keys in the table.

    int cursor_ok() const;
    // PROMISES:
    //   Returns 1 if the cursor is attached to a key/datum pair,
    //   and 0 if the cursor is in the off-list state.

    const KeyType& cursor_key() const;
    // REQUIRES: cursor_ok()
    // PROMISES: Returns key of key/datum pair to which cursor is attached.

    const DatumType& cursor_datum() const;
    // REQUIRES: cursor_ok()
    // PROMISES: Returns datum of key/datum pair to which cursor is attached.

    void insert(const Pair<KeyType, DatumType>& pairA);
    // PROMISES:
    //   If keyA matches a key in the table, the datum for that
    //   key is set equal to datumA.
    //   If keyA does not match an existing key, keyA and datumM are
    //   used to create a new key/datum pair in the table.
    //   In either case, the cursor goes to the off-list state.

    void remove(const KeyType& keyA);
    // PROMISES:
    //   If keyA matches a key in the table, the corresponding
    //   key/datum pair is removed from the table.
    //   If keyA does not match an existing key, the table is unchanged.
    //   In either case, the cursor goes to the off-list state.

    void find(const KeyType& keyA);
    // PROMISES:
    //   If keyA matches a key in the table, the cursor is attached
    //   to the corresponding key/datum pair.
    //   If keyA does not match an existing key, the cursor is put in
    //   the off-list state.

    void go_to_first();
    // PROMISES: If size() > 0, cursor is moved to the first key/datum pair
    //   in the table.

    void step_fwd();
    // REQUIRES: cursor_ok()
    // PROMISES: 
    //   If cursor is at the last key/datum pair in the list, cursor
    //   goes to the off-list state.
    //   Otherwise the cursor moves forward from one pair to the next.

    void make_empty();
    // PROMISES: size() == 0.
    
    template <class KType, class DType>
    friend ostream& operator<<(ostream& os, const LookupTable<KType, DType>& lt);
    
    private:
    int sizeM;
    LT_Node<KeyType, DatumType> *headM;
    LT_Node<KeyType, DatumType> *cursorM;

    void destroy();
    // Deallocate all nodes, set headM to zero.
  
    void copy(const LookupTable& source);
    // Establishes *this as a copy of source.  Cursor of *this will
    // point to the twin of whatever the source's cursor points to.
};

template <class KeyType, class DatumType>
const DatumType& LookupTable<KeyType, DatumType>::Iterator::operator *() {
  assert(LT ->cursor_ok());
  return LT->cursor_datum();
}

template <class KeyType, class DatumType>
const DatumType& LookupTable<KeyType, DatumType>::Iterator::operator ++() {
  assert(LT->cursor_ok());
  const DatumType & x = LT->cursor_datum();
  LT->step_fwd();
  return x;
}


template <class KeyType, class DatumType>
const DatumType& LookupTable<KeyType, DatumType>::Iterator::operator ++(int) {
  assert(LT->cursor_ok());
  LT->step_fwd();
  return LT->cursor_datum();
}

template <class KeyType, class DatumType>
int LookupTable<KeyType, DatumType>::Iterator::operator !() {
  return (LT->cursor_ok());
}

template <class KeyType, class DatumType>
void LookupTable<KeyType, DatumType>::Iterator::step_fwd(){
    assert(LT->cursor_ok());
    LT->step_fwd();
}

template <class KeyType, class DatumType>
LookupTable<KeyType, DatumType>::LookupTable(const LookupTable& source){ copy(source);};


template <class KeyType, class DatumType>
LookupTable<KeyType, DatumType>::~LookupTable() { destroy(); };


template <class KeyType, class DatumType>
LookupTable<KeyType, DatumType>& LookupTable<KeyType, DatumType>::operator = (const LookupTable& rhs){
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

template <class KeyType, class DatumType>
LookupTable<KeyType, DatumType>& LookupTable<KeyType, DatumType>::begin(){
    cursorM = headM;
    return *this;
}

template <class KeyType, class DatumType>
int LookupTable<KeyType, DatumType>::size() const {
    return sizeM;
};

template <class KeyType, class DatumType>
const KeyType& LookupTable<KeyType, DatumType>::cursor_key() const {
  assert(cursor_ok());
  return cursorM->pairM.key;
}

template <class KeyType, class DatumType>
const DatumType& LookupTable<KeyType, DatumType>::cursor_datum() const {
  assert(cursor_ok());
  return cursorM->pairM.datum;
}

template <class KeyType, class DatumType>
int LookupTable<KeyType, DatumType>::cursor_ok() const {
  return cursorM != 0;
}

template <class KeyType, class DatumType>
void LookupTable<KeyType, DatumType>::insert(const Pair<KeyType, DatumType>& pairA){
    // Add new node at head?
    if (headM == 0 || pairA.key < headM->pairM.key) {
        headM = new LT_Node(pairA, headM);
        sizeM++;
    }
    // Overwrite datum at head?
    else if (pairA.key == headM->pairM.key)
        headM->pairM.datum = pairA.datum;
    
    // Have to search ...
    
    else {
        LT_Node<KeyType, DatumType>* before= headM;
        LT_Node<KeyType, DatumType>* after=headM->nextM;
        
        while(after!=NULL && (pairA.key > after->pairM.key))
        {
            before=after;
            after=after->nextM;
        }
        
        if(after!=NULL && pairA.key == after->pairM.key)
        {
            after->pairM.datum = pairA.datum;
        }
        else
        {
            before->nextM = new LT_Node (pairA, before->nextM);
            sizeM++;
        }
    }
}

template <class KeyType, class DatumType>
void LookupTable<KeyType, DatumType>::remove(const KeyType& keyA){
  if (headM == 0 || keyA < headM->pairM.key)
    return;

  LT_Node<KeyType, DatumType>* doomed_node = 0;
  if (keyA == headM->pairM.key) {
    doomed_node = headM;
    headM = headM->nextM;
    sizeM--;
  }
  else {
    LT_Node<KeyType, DatumType> *before = headM;
    LT_Node<KeyType, DatumType> *maybe_doomed = headM->nextM;
    while(maybe_doomed != 0 && keyA > maybe_doomed->pairM.key) {
      before = maybe_doomed;
      maybe_doomed = maybe_doomed->nextM;
    }

    if (maybe_doomed != 0 && maybe_doomed->pairM.key == keyA) {
      doomed_node = maybe_doomed;
      before->nextM = maybe_doomed->nextM;
      sizeM--;
    }
  }
  delete doomed_node;           // Does nothing if doomed_node == 0.
}

template <class KeyType, class DatumType>
void LookupTable<KeyType, DatumType>::find(const KeyType& keyA){
  LT_Node<KeyType, DatumType> *ptr=headM;
  while (ptr != NULL && ptr->pairM.key != keyA)
    {
     ptr=ptr->nextM;
    }
   cursorM = ptr;
}

template <class KeyType, class DatumType>
void LookupTable<KeyType, DatumType>::go_to_first(){
  cursorM = headM;
}

template <class KeyType, class DatumType>
void LookupTable<KeyType, DatumType>::step_fwd() {
  assert(cursor_ok());
  cursorM = cursorM->nextM;
}

template <class KeyType, class DatumType>
void LookupTable<KeyType, DatumType>::make_empty(){
    destroy();
    sizeM = 0;
    cursorM = 0;
}

template <class KeyType, class DatumType>
void LookupTable<KeyType, DatumType>::destroy() {
    LT_Node<KeyType, DatumType> *ptr = headM;
    while (ptr!=NULL){
        headM=headM->nextM;
        delete ptr;
        ptr=headM;
    }
    cursorM = NULL;
    sizeM=0;
}

template <class KeyType, class DatumType>
void LookupTable<KeyType, DatumType>::copy(const LookupTable<KeyType, DatumType>& source){
  headM=0;
  cursorM =0;

    if(source.headM ==0) return;
 
    for(LT_Node<KeyType, DatumType> *p = source.headM; p != 0; p=p->nextM){
        insert(Pair (p->pairM.key, p->pairM.datum));
        if(source.cursorM == p)
            find(p->pairM.key);
    }
}

template <class KeyType, class DatumType>
ostream& operator << (ostream& os, const LookupTable<KeyType, DatumType>& lt)
{
  if (lt.cursor_ok())
    os <<lt.cursor_key() << "  " << lt.cursor_datum();
  else
    os<<"Not Found.";

  return os;
}

#endif


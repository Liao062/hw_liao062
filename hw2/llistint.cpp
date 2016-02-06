#include "llistint.h"
#include <cstdlib>
#include <stdexcept>
#include <iostream>
using namespace std;

LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListInt::~LListInt()
{
  clear();
}

bool LListInt::empty() const
{
  return size_ == 0;
}

int LListInt::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListInt::insert(int loc, const int& val)
{
  if(loc < 0 || loc > size_){
    return;
  }

  
  if(loc == 0){
    //cout<<"I am inserting new item and the new value is "<<val<<endl;
    
    if(size_ == 0){         //special case for insserting to a empty list
      head_ = new Item;
      head_->prev = NULL;
      head_->next = NULL;
      head_->val = val;
      tail_=head_;          //CNMLGB  remember to change the tail as well
    }
    else{
      Item *temp = head_;
      head_ = new Item;
      head_->prev = NULL;
      head_->next = temp;
      head_->val = val;
      temp->prev = head_;
    }


  }

  else if(loc == size_){
    Item *temp = tail_;
    tail_ = new Item;
    temp->next = tail_;
    tail_->prev =temp;
    tail_->next =NULL;
    tail_->val = val;
    //cout<<"got here?"<<endl;
    


  }

  else{
    //cout<<"I am insserting in the middle"<<endl;
    Item* newItem = new Item;
    Item* temp1 = getNodeAt(loc-1);
    Item* temp2 = getNodeAt(loc);
    temp1->next = newItem;
    temp2->prev = newItem;
    newItem->prev = temp1;
    newItem->next = temp2;
    newItem->val = val;

  }

  size_++;
}

/**
 * Complete the following function
 */
void LListInt::remove(int loc)
{
  if(empty()){
    return;
  }
  if(loc < 0 || loc >= size_){
    return;
  }
  if(loc==0){
    Item* temp = head_;
    head_ = head_->next;
    delete temp;

    if(head_!=NULL){
      head_->prev = NULL;
    }
    else{
      head_ =NULL;
      tail_ =NULL;
    }
  }
  
  else if(loc == size_ -1){
    Item *temp = tail_;
    tail_ = tail_->prev;
    delete temp; 
    tail_->next = NULL;      // if the size is one, it will only run the first if statement
  }

  else{
    Item* temp1 = getNodeAt(loc-1);
    Item* temp2 = getNodeAt(loc);
    Item* temp3 = getNodeAt(loc+1);
    delete temp2;
    temp1->next = temp3;
    temp3->prev = temp1;
  }

    size_--;
}

void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


/**
 * Complete the following function
 */
LListInt::Item* LListInt::getNodeAt(int loc) const
{ 
  Item *temp = head_;
  for(int i=0; i<loc; i++){
    //cout<<"the current value is "<<temp->val<<endl;
    temp = temp->next;

  }
  //cout<<"after for loop, the final value is "<<temp->val<<endl;


  return temp;


}

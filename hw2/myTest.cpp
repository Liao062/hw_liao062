#include "llistint.h"
#include <iostream>

using namespace std;
int main() {
  LListInt * list = new LListInt();
  list->insert(0, 5);
    //insert an item to the empty list. 

    if (list->size() == 1) {
      cout << "SUCCESS: List has size 1 after one insertion." << endl;
    } 
    else {
      cout << "FAIL: List has size " << list->size() << " after one insertion.";
      cout << endl;
    }

  if (list->get(0) == 5) {
      cout << "SUCCESS: 5 is at the 0th index of the list." << endl;
    } 
    else {
      cout << "FAIL: 5 is not at the 0th index of the list, " << list->get(0);
      cout << " is instead." << endl;
    }

    list->insert(1,7);
    //insert an item at the valid location SIZE
    //the tail will be changed and the size would be changed to 2
    if (list->size() == 2) {
      cout << "SUCCESS: List has size 2 after one insertion." << endl;
    } 
    else {
      cout << "FAIL: List has size " << list->size() << " after one insertion.";
      cout << endl;
    }
    //the second item will have the value 2;
    if (list->get(1) == 7) {
      cout << "SUCCESS: 7 is at the 1st index of the list." << endl;
    } 
    else {
      cout << "FAIL: 7 is not at the 1st index of the list, " << list->get(1);
      cout << " is instead." << endl;
    }

    list->insert(1,-6);
    //add one item at the location between 0 to Size-1
    if(list->size() == 3){
      cout << "SUCCESS: List has size 3 after one insertion." << endl;
    } 
    else {
      cout << "FAIL: List has size " << list->size() << " after one insertion.";
      cout << endl;
    }

    if (list->get(1) == -6) {
      cout << "SUCCESS: -6 is at the 1st index of the list." << endl;
    } 
    else {
      cout << "FAIL: -6 is not at the 1st index of the list, " << list->get(1);
      cout << " is instead." << endl;
    }
    //5 should be the new value of the 1st index
    if (list->get(2) == 7) {
      cout << "SUCCESS: 7 is at the 2nd index of the list." << endl;
    } 
    else {
      cout << "FAIL: 7 is not at the 2nd index of the list, " << list->get(2);
      cout << " is instead." << endl;
    }
    //4 would be pushed to the next position at the 2nd.
  //the substitution is successful.

  list->insert(10,1);
  list->insert(-1,66);
  //insert an item to the array at the location out of valid range
  if(list->size() == 3){
      cout << "SUCCESS: List has size 3 after two insertion." << endl;
    } 
    else {
      cout << "FAIL: List has size " << list->size() << " after one insertion.";
      cout << endl;
    }

  list->remove(1);
  //delete the item in location 1 in the valid range
  if(list->size() == 2){
      cout << "SUCCESS: List has size 2 after one remove." << endl;
    } 
    else {
      cout << "FAIL: List has size " << list->size() << " after one insertion.";
      cout << endl;
    }
    //the size should be 2 now.

  if (list->get(1) == 7) {
      cout << "SUCCESS: 4 is at the 1st index of the list." << endl;
    } 
    else {
      cout << "FAIL: 4 is not at the 1st index of the list, " << list->get(1);
      cout << " is instead." << endl;
    }
    //the item with value 4 will substitute the value at location 1 before

    list->remove(199);
    list->remove(-22);
    //delete the item at the location out of the valid range
    if(list->size() == 2){
      cout << "SUCCESS: List has size 2 after one remove." << endl;
    } 
    else {
      cout << "FAIL: List has size " << list->size() << " after one insertion.";
      cout << endl;
    }
    //the size should keep 2 now.

    list->insert(2,66);
    //insert item with value 5 to the list.
    list->remove(2);
    //remove the last item(boundary)
    if(list->size() == 2){
      cout << "SUCCESS: List has size 2 after one remove." << endl;
    } 
    else {
      cout << "FAIL: List has size " << list->size() << " after one insertion.";
      cout << endl;
    }
    //the last item is removed and the size will become 2
    if (list->get(1) == 7) {
      cout << "SUCCESS: 7 is at the 1st index of the list." << endl;
    } 
    else {
      cout << "FAIL: 7 is not at the 1st index of the list, " << list->get(1);
      cout << " is instead." << endl;
    }

    list->insert(2,12);
    list->remove(0);
    //remove the first boundary item
    //the rest items should move left by one spot
    if(list->size() == 2){
      cout << "SUCCESS: List has size 2 after one remove." << endl;
    } 
    else {
      cout << "FAIL: List has size " << list->size() << " after one insertion.";
      cout << endl;
    }
    //the first item is removed and the size will become 2
    if (list->get(1) == 12) {
      cout << "SUCCESS: 12 is at the 1st index of the list." << endl;
    } 
    else {
      cout << "FAIL: 12 is not at the 1st index of the list, " << list->get(1);
      cout << " is instead." << endl;
    }
    list->clear();
    if(list->size() == 0){
      cout << "SUCCESS: List has size 0 after one clear." << endl;
    } 
    else {
      cout << "FAIL: List has size " << list->size() << " after one insertion.";
      cout << endl;
    }
    delete list;
 
}

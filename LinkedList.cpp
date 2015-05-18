#include <cstdlib>
#include <iostream>

#include "linkedlist.h"
#include "tdalist.h"
#include "object.h"

using namespace std;

LinkedList::linkedlist(){
	head = NULL;
	curr = NULL;
	temp = NULL;
}

bool LinkedList::insert(Object* addData){
	if (pos <  || pos > size){
		return false;
	}
	nodePtr n = new node;
	n->next = NULL;
	n->addData = addData;

	if (head != NULL){
		curr = head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = n;
	}else{
		head = n;
	}
	return true;
}
bool LinkedList::erase(Object* delData){
	if (pos < 0 || pos >= size){
        return false;
	}else{
		nodePtr delPtr = NULL;
		temp = head;
		curr = head;
		while(curr != NULL && curr-> != delData){
			temp = curr;
			curr = curr->next;
		}
		if (curr == NULL){
			cout << delData << "no esta en la lista" << endl;
		}else{
			delPtr = curr;
			curr = curr->next;
			temp->next = curr;
			delete delPtr;
		}
	}
	return true;
}
Object* LinkedList::get(unsigned index)const{
	if (index < 0 || index >= size){
		return NULL;
	}
	curr = head;
	for (int i = 0; i < index; ++i)
	{
		curr = curr->next;
	}
	return curr;

}
Object* LinkedList::first()const{
	if(head != NULL){
		return head->data;
	}
	return NULL;
}
Object* LinkedList::last()const {
    if (head == NULL)
        return NULL;
    curr = head;
    for (int i=0; i < size; i++)
        curr = curr->next;
    return curr->data;
}
int LinkedList::indexOf(Object* other)const {
	curr = head;
	for (int i = 0; i < size; ++i)
	{
		if (curr->data->equals(other))
		{
			return i;
		}
	}
	return -1;

}
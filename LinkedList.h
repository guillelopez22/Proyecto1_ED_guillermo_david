#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "object.h"
#include "tdalist.h"

class LinkedList : public TDAList{
private:
	typedef struct node{
		Object* data;
		node* next;
	}* nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;
  public:
    LinkedList();
    virtual ~LinkedList();
    void AddNode(int);
    void DeleteNode(int);
    virtual bool insert(Object*, int) ;
    virtual int indexOf(Object*)const ;
    virtual Object* get(unsigned)const ;
    virtual bool erase(unsigned) ;
    virtual int prev(int) const ;
    virtual int next(int) const ;
    virtual void reset() ;
    virtual Object* first()const ;
    virtual Object* last()const ;
    virtual void print()const ;
    virtual bool isFull()const ;
    virtual int getCapacity()const;
};


#endif
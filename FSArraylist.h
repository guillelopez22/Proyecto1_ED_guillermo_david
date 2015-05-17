#ifndef FSARRAYLIST_H
#define FSARRAYLIST_H

#include "tdalist.h"
#include "integer.h"

class FSArraylist: public TDAList{
protected:
	unsigned int capacity;
	Object** arraylist;
public:
	FSArraylist(int);
	~FSArraylist();
    virtual bool insert(Object*, int);
    virtual int indexOf(Object*)const;
    virtual Object* get(unsigned)const;
    virtual bool erase(unsigned);
    virtual int prev(int) const;
    virtual int next(int) const;
    virtual void reset();
    virtual Object* first()const;
    virtual Object* last()const;
    virtual void print()const;
    virtual bool isEmpty()const;
    virtual bool isFull()const;
    virtual int getCapacity()const;
};

#endif 

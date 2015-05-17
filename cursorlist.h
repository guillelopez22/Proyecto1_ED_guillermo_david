#ifndef CURSORLIST_H
#define CURSORLIST_H

#include "tdalist.h"
#include "object.h"

class CursorList : public TDAList{
	struct Row{
		int next,prev;
		Object* data;
	};
protected:
	Row* rows;
	int head;
	unsigned int capacity;
public:
	CursorList(int);
	~CursorList();
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
    int getSize() const;
    int avail() const;
};

#endif
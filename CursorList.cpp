#include "cursorlist.h"
#include <stddef.h>
#include <iostream>

using std::cout;
using std::endl;

CursorList::CursorList(int cap){
	capacity = cap;
	rows = new Row[capacity];
	if(!rows)
		throw "No Memory";
	head = -1;
	size = 0;
	for (int i = 0; i < capacity; i++){
		rows[i].data = NULL;
	}
}
CursorList::~CursorList(){
	delete rows;
}
bool CursorList::insert(Object* E, int pos){
	if(pos<0||pos>size)
		return false;
	if(size == capacity)
		return false;
	int neo = avail();
	if(head == -1){
		head = neo;
		rows[head].prev = -1;
		rows[head].next = -1;
		rows[head].data = E;
	}else{
		int tmp = head;
		for (int i = 0; i < pos - 1; i++){
			tmp = rows[tmp].next;
		}
		rows[neo].prev = tmp;
		rows[neo].next = rows[tmp].next;
		rows[tmp].next = neo;
		if(pos < size)
			rows[rows[neo].next].prev = neo;
		rows[neo].data = E;
	}
	size++;
	return true;

}
int CursorList::indexOf(Object* E)const{
	int cont = 0;
	int tmp = head;
	for (int i = 0; i < size; i++){
		if(rows[tmp].data->equals(E))
			return cont;
		cont++;
		tmp = rows[tmp].next;
	}
	return -1;
} 
Object* CursorList::get(unsigned int pos)const{
	int cont = 0;
	int tmp = head;
	for (int i = 0; i < size; i++){
		if(cont == pos)
			return rows[tmp].data;
		tmp = rows[tmp].next;
		cont++;
	}
	return NULL;
}
bool CursorList::erase(unsigned int pos){
	if(pos<0||pos>size)
		return NULL;
		if(pos == 0){
			int tmp = head;
			rows[tmp].data = NULL; 
			head = rows[tmp].next;
			rows[head].prev = -1;
			rows[tmp].next = -1;
		}else{
			int tmp = head;
			for (int i = 0; i < pos - 1; i++){
				tmp = rows[tmp].next;
			}
			rows[tmp].data = NULL;
			rows[rows[tmp].prev].next = rows[tmp].next;
			if(pos!=size){
				rows[rows[tmp].next].prev = rows[tmp].prev;
				rows[tmp].next = -1;
			}
			rows[tmp].prev = -1;
			size--;
		}
	return true;	
}
int CursorList::prev(int pos) const{
	return pos - 1;
}
int CursorList::next(int pos) const{
	return pos + 1;
}
void CursorList::reset(){
	rows = NULL;
	capacity = 0;
	size = 0;
}
Object* CursorList::first()const{
	if(size==0)
		throw "List is empty!";
	for (int i = 0; i < size; i++){
		if(rows[i].prev==-1 && rows[i].data != NULL)
			return rows[i].data;
	}
}
Object* CursorList::last()const{
	if(size==0)
		throw "List is empty!";
	for (int i = 0; i < size; i++){
		if(rows[i].next==-1 && rows[i].data != NULL)
			return rows[i].data;
	}
}
void CursorList::print()const{
	int tmp = head;
	for (int i = 0; i < size; i++){
		cout<<rows[tmp].prev<<endl;
		rows[tmp].data->print();
		cout<<rows[tmp].next<<endl;
		tmp = rows[tmp].next; 
	}
}

bool CursorList::isEmpty()const{
	if(size==0)
		return true;
	return false;
}
bool CursorList::isFull()const{
	if(size==capacity)
		return true;
	return false;
}
int CursorList::getCapacity()const{
	return capacity;
}
int CursorList::getSize()const{
	return size;
} 
int CursorList::avail() const{
	for (int i = 0; i < capacity; i++){
		if(rows[i].data == NULL)
			return i;
	}
	return -1;
}
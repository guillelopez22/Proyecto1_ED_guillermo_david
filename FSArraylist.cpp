#include "FSArraylist.h"
#include <iostream>

using std::cout;

FSArraylist::FSArraylist(int cap){
	capacity = cap;
	arraylist = new Object*[capacity]; 
}
FSArraylist::~FSArraylist(){
	for (int i = 0; i < capacity; i++){
		delete arraylist[i];
	}
}
bool FSArraylist::insert(Object* E, int pos){
	if(size==capacity)
		return false;
	if(pos<0||pos>size)
		return false;
	if(pos==size){
		arraylist[size] = E;
	}else{
		for (int i = size; i >pos; i--){
			arraylist[i] = arraylist[i-1];
		}
		arraylist[pos] = E;
	}
	size++;
	return true;

}
int FSArraylist::indexOf(Object* E)const{
	for (int i = 0; i < size; ++i){
		if(arraylist[i]->equals(E))
			return i;
	}
	return -1;
}
Object* FSArraylist::get(unsigned int pos)const{
	return arraylist[pos];
}
bool FSArraylist::erase(unsigned int pos){
	if(pos<0||pos>size)
		return false;
	Object* tmp = arraylist[pos];
	for (int i = pos; i <= size;i++){
		arraylist[i] = arraylist[i+1];
	}
	delete tmp;
	size--;
	return true;
}
int FSArraylist::prev(int pos) const{
	return pos - 1;
}
int FSArraylist::next(int pos) const{
	return pos + 1;
}

void FSArraylist::reset(){
	for (int i = 0; i < capacity; i++){
		delete arraylist[i];
	}
	size = 0;
	capacity = 0;
	arraylist = NULL;
}

Object* FSArraylist::first()const{
	return arraylist[0];
}
Object* FSArraylist::last()const{
	return arraylist[size];
}
void FSArraylist::print()const{
	for (int i = 0; i < size; ++i){
		arraylist[i]->print();
	}
}
bool FSArraylist::isEmpty()const{
	if(size==0)
		return true;
	return false;
}
bool FSArraylist::isFull()const{
	if(size==capacity)
		return true;
	return false;
}
int FSArraylist::getCapacity()const{
	return capacity;
}
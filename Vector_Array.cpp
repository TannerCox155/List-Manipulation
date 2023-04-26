/*
Tanner Cox
CS255
P02: Classes
Description: Using a class to create a list with functions used to manipulate it.
			 Vector_Array.cpp will populate functions for use.
*/
#include "Vector_Array.h"
#include <iostream>
using namespace std;

Vector::Vector() {
	capacity = 2; //capacity of array is default 2
	currentSize = 0; //start array at index 0
	items = new int[capacity]; //items int array default capacity of 2
}

Vector::Vector(int size)
{
    items = new int[size]; //set array to user defined size
	capacity = size; //capacity is now user defined
	currentSize = 0; //current size still 0, indices not populated
}


Vector::~Vector()
{
	delete items; //remove array
}

void Vector::print()
{
	for (int i = 0; i < currentSize; ++i) {//Print items by index
		cout << items[i] << " ";
	}
}

int Vector::getSize()
{
	return currentSize; //return total indices occupied
}

int Vector::getCapacity()
{
	return capacity; //return total capacity array can hold
}

int Vector::getItem(int location)
{
	int size = currentSize;
//  if (location is less than 1 return 0, our array is 1 based || location greater than size + 1, the location does not exist, return 0)
	if (location < 1 || location > size + 1) {
		return 0;
	}
	return items[location - 1];

}

bool Vector::addVector(int item, int location)
{
	int size = currentSize; //local variable given currentSize value
	if (location < 1 || location > size + 1) { //if location desired is less than 1 or greater than the amount of available indices, return false
		return 0; 
	}
	int maxSize = capacity; //local variable tasked with holding the total size of array
	if (size == maxSize) {
		ResizeVector();//if the user enters a new integer to store in array, automatically increase its total capacity.
	}
	int* values = items; //a pointer to an integer is used to create a local copy of items
	for (int i = size; i >= location; i--) { //opening for data point by making a hole between indices
		values[i] = values[i - 1]; //copy backwards in reverse and open hole
	}//loop runs backwards to specified location, start at end and copy to next location.
	//ex: 1 2 4 5 5, 1 2 4 4 5, 1 2 3 4 5, first 4 is overwritten
	values[location - 1] = item;
	currentSize++;//item added to list, increment the index or currentSize
	return true; // if correct return true
}

bool Vector::removeVector(int location)
{
	int size = currentSize; //check for valid index
	if (location < 1 || location > size + 1) {
		return 0;
	}
	int* values = items;
	for (int i = location; i < size; i++) {
		values[i - 1] = values[i]; 
	}
	currentSize--;
	return true; 
}

bool Vector::setVector(int item, int location)
{
	int size = currentSize; //check for valid index
	if (location < 1 || location > size + 1) {
		return 0;
	}
	items[location - 1] = item;
}

bool Vector::addVector(int item)
{
	int size = currentSize + 1;
	return addVector(item, size);
}

bool Vector::removeVector()
{
	int size = currentSize; 
	return removeVector(size);
}

void Vector::ResizeVector()
{
	int size = currentSize;
	int* newArray = new int[size * 2];
	int* oldArray = items;
	for (int i = 0; i < size; i++) {
		newArray[i] = oldArray[i];
	}
	delete[] items;
	capacity = size * 2; 
	items = newArray;
}
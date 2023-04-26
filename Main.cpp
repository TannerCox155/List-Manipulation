/*
Tanner Cox
CS255
P02: Classes
Description: Using a class to create a list with functions used to manipulate it.
Main.cpp is the driver used to test functions.
*/
#include <iostream>
#include "Vector_Array.h";
#include <vector>

using namespace std;

int main() {
	Vector* newVctr = new Vector(6);
	newVctr->addVector(2,1);
	newVctr->addVector(4);
	newVctr->addVector(6);
	newVctr->addVector(9);
	newVctr->addVector(10);
	newVctr->addVector(12);
	
	newVctr->ResizeVector(); //vector should now be of size 12
	
	cout << "*** P02: Classes ***" << endl;
	cout << endl;
	cout << "Vector currently contains integers: ";
	newVctr->print();
	cout << endl;
	cout << "The Vector currently stores " << newVctr->getSize() << " values" <<endl;
	cout << "The Vector can currently hold " << newVctr->getCapacity() << " values" << endl;
	cout << "The value at location 4 is: " << newVctr->getItem(4) << endl;
	newVctr->addVector(8, 4);
	cout << "The value at location 4 is now: " << newVctr->getItem(4) << endl;
	cout << "The Vector is now: ";
	newVctr->print();
	cout << endl;
	cout << "We want increments of two between our integers, let's throw out the 9." << endl;
	newVctr->removeVector(5);
	cout << "Vector is now: ";
	newVctr->print();
	cout << endl;
	cout << "Vector is now full: ";
	newVctr->addVector(1);
	newVctr->addVector(3);
	newVctr->addVector(5);
	newVctr->addVector(7);
	newVctr->addVector(9);
	newVctr->addVector(11);
	newVctr->print();
	cout << endl;
	cout << "Current capacity: " << newVctr->getCapacity() << endl;
	cout << "When adding another integer to our full Vector, it should automatically resize. Current size * 2.\nShould be 24." << endl;
	newVctr->addVector(13);
	cout <<"Capacity is now: " << newVctr->getCapacity() << endl;
	
	return 0;
}
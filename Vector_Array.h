/*
Tanner Cox
CS255
P02: Classes
Description: Using a class to create a list with functions used to manipulate it. 
			 Vector_Array.h will declare a class with private datatypes and functions for our list modification
*/
#if !defined VECTOR_ARRAY_H
#define VECTOR_ARRAY_H

class Vector {

public:
	//Standard Functions
	
	//Preconditions: Default constructor
	Vector();
	//Postconditions: Instantiation of defined object vector

	//Precondtions: Vector object is defined with initial default values, user passes integer to define their own capacity of the vector
	Vector(int size);
	//Postconditions: Object vector is now of a user defined capacity

	//Preconditions: Object vector is called and the user initializes its capacity, with or without items
	~Vector();
	//Postconditions: Object vector is deleted from dynamic/HEAP memory

	//Preconditons: Vector* newVctr = new Vector(user int); in main program points to vector object constructor,
	//indicies are populated with values, addVector() does this.
	void print();
	//Postconditons: Each populated index will be printed

	//Helper Functions

	//Preconditions: Vector has a current size/ is populated
	int getSize();
	//Postconditons: The amount of non-null indices is returned

	//Preconditions: Vector object has a default size of 2, function will return 2 else the programmer increases the capacity via passing an int to constructor
	int getCapacity();
	//Postconditions: Total indices occupied or not is returned to user 

	//Preconditions: Programmer calls function getItem and passes an int of the desired index/item they want to return
	int getItem(int location);
	//Postconditions: The item at the specified location is returned

	//Preconditons: Object vector is created via constructor so addVector is able to validate the desired index the programmer wants to store an item
	bool addVector(int item, int location);
	//Postconditions: Item is added to user defined location

	//Preconditions: Object vector is constructed and populated so removeVector can validate the desired index the programmer wants to remove an item from the array
	bool removeVector(int location); //Remove an item from a specific location, not removed but copied.
	//Postconditons: Item defined by user is removed from array

	//Preconditions: Object vector is defined and populated so that a specific item at an index may be overwritten
	bool setVector(int item, int location); //Overwrites an item at a specific location
	//Postconditons: Once location is validated item is overwritten
	
	//Convenience Functions

	//Preconditions:Object vector is populated with values so that a new item may be appended to it
	bool addVector(int item);//Add item to the end of the Array
	//Postconditions: A new item is appended to the end of the list by adding +1 to size of vector

	//Preconditions: Object vector is populated in order to remove item from end of the array
	bool removeVector();//Remove item from the end of Array
	//Postconditions: Last value of array is removed by returning actual size of vector
	
	//Preconditions: Object vector is initialized and populated with values
	void ResizeVector();//Old array values are copied to new array, size of new array is old array capacity *2
	//Postconditons: New array is created and old array is deleted, capacity of vector now 2* larger than original

private:
	int* items; //type of data being stored
	int capacity; //array total capacity, total indices available for use in array
	int currentSize; //array index, show how many of our indices are populated
};
#endif
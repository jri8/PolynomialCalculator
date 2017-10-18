#include "Stack.h"
#include "LList.h"
#include "Term.h"


//using namespace std;


stack::stack() //default constructor
{
	sent.insert(0, 0); //inserting an empty node into the sent list
	sent.next = &sent; //setting the sentinal to point to itself
	sent.prev = &sent; //setting sentinal  to point to itself
}


stack::~stack()
{
	LList* current = sent.next;
	this->head = NULL;
	while (!(empty())) //while the stack is not empty
	{
		this->pop(); //pop until empty
	}

	current = NULL; //setting current to null so no dangling pointers
}

void stack::insertFront(LList& list)
{



	
	//This code is to insert a new node to the front of a list
	//it is used in this case as a push method for a stack

	LList* temp = new LList(list); 
	LList * current = &sent; 
	//rearranging pointers 
	temp->next = current->next; 
	temp->prev = current->next->prev;
	current->next->prev = temp;
	current->next = temp;



	current = NULL;
	temp = NULL;
	





}



void stack::deleteFront()
{

	//Deletes object from the front of the list
	//in this case it is used as a pop method for the stack


	LList *current = sent.next; //setting current to point to first object instack

	if (empty())
	{
		cout << "List already empty!" << endl;
	}
	else
	{
		//moving pointers around the node to be deleted
		current->next->prev = current->prev;
		current->prev->next = current->next;


		current->next = NULL;
		current->prev = NULL;

		current->~LList(); //calling destructor for List (polynomial object)
	}
}



LList stack::top()
{
	//returns the top object in the stack


	LList first; //will hold first value in list
	if (!(this->empty()))
	{
		first = *(sent.next); //if the list is not empty, set first to be the first object
	}
	else
	{
		//if list is empty do nothing
	}

	return first; //return the first object 
	//if list is empty, first will have default values
}






bool stack::empty()
{
	bool empty;

	if (sent.next == &sent) //if sentinal head is pointing to itself
		empty = true;
	else
		empty = false;

	return empty; //returns if the list is empty

}



#pragma once
#include "LList.h"
#include "Term.h"




class stack
{




private:
	
	LList* head;



public:

	LList sent;

	stack(); //constructor
	~stack(); //destructor

	void push(LList& list) { this->insertFront(list); } //pushing list onto stack (wrapper for insert front)
	void pop() { deleteFront(); } //pops the top value off the stack (wrapper for delete front)
	LList top(); //returns top value in list


	bool empty(); //returns true if stack is empty
	void insertFront(LList& list); //inserts value at front of list implementation of stack (called by push)
	void deleteFront(); //deletes value at front of list implementation of stack (called by pop)







};
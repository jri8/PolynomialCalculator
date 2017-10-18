


#pragma once

#include <iostream>
#include <string>
#include "Term.h"

using namespace std;



class LList
{
	friend ostream& operator<<(ostream &os, const LList &rhsObj); //outputs all terms in polynomial
private:
	Term sent; //sentinal head for polynomial
	int size; //holds size of polynomial

	

public:
	
	LList(); //default constructor 
	LList(const LList &rhsobj); //convert constructor
	~LList(); // destructor (deletes all nodes in the list)


	LList *next; //next pointer for use in stack
	LList *prev; //previous pointer to use in stack
	//Pointers will also be included in sentinal node for stack

	//used in overloaded equals operator and copy constructor
	// sets the list calling the fuction equal to the list being passed
	void setList(const LList &l);

	//removes term from front of list
	void removeFront();
	//deletes the term being passed from the lsit
	void deleteThis(Term*);
	//deletes all terms from list
	void clearList();
	//inserts a new node into list in order by power of the term
	void insert(int c, int p);
	//combines terms with like powers together
	void simplify();

	
	LList operator+(const LList &rhsobj);//adds two polynomials together
	LList operator-(const LList &rhsobj);//subtracts two polynomials
	LList operator*(const LList &rhsobj); //multiplies two polynomials
	LList operator=(const LList &rhsobj); //sets one list equal to another
	
};






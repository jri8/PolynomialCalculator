#pragma once
#include <ostream>

using namespace std;



class Term
{
	friend ostream& operator<<(ostream &os, const Term &rhsObj);
private:


public:
	Term() { coef = 0; pow = 0; next = NULL; prev = NULL; } //default constructor
	Term(int c, int pw, Term *pr, Term *n) { coef = c; pow = pw; prev = pr; next = n; } //overloaded constructor where pointers are passed
	Term(int c, int pw) { coef = c; pow = pw; next = NULL; prev = NULL; } //overloaded constructor where pointers are not passed (set to null)
	Term *next; //points to next object in list
	Term *prev; //points to previous object in list
	//will be included in list sentinal node



	int coef; //holds coefficient of term
	int pow; //holds power of term

	bool operator>(const Term &rhsobj); //compares powers
	bool operator<(const Term &rhsobj); //compares powers
	bool operator==(const Term &rhsobj); //compares powers
	Term operator=(const Term &rhsobj); //sets one term equal to another

};
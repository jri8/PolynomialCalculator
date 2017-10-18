


#include <string>
#include "LList.h"

using namespace std;



ostream& operator<<(ostream &os, const LList &rhsobj)
{
	Term *current = rhsobj.sent.next;
	
	//loop to stop at second to last number
	while (current != rhsobj.sent.prev)
	{
		os << current->coef << "x^" << current->pow << " + ";
		current = current->next;
	}

	//keeping last object from being printed without '+'
	os << current->coef << "x^" << current->pow << " ";
	
	current = NULL;
	return os;
}

LList::LList() //default constructor
{
	//setting sentinel to point towards itself
	sent.prev = &sent;
	sent.next = &sent;

	//setting next and previous pointers for stack
	//to point to itself
	this->next = this;
	this->prev = this;

	size = 0;
}

LList::~LList()
{
	//destructor clears the list
	this->clearList();
}





LList::LList(const LList &rhsobj) //copy constructor
{
	//setting sentinel node to point to itself
	sent.prev = &sent;
	sent.next = &sent;
	next = NULL;
	prev = NULL;


	size = 0;

	//calling setList function to copy list
	this->setList(rhsobj);
}


LList LList::operator=(const LList &rhsobj) //overloaded equals operator
{
	//making sure no self assignment
	if (this != &rhsobj)
	{
		//calling set list to copy list
		this->setList(rhsobj);
	}
	//returning list that was copied
	return rhsobj;
}

void LList::setList(const LList &l) //setList
{
	Term *current = l.sent.next; //pointer to first node
	this->clearList(); //clearing list

	while (current != &l.sent)
	{
		//inserting nodes into new list
		this->insert(current->coef, current->pow);
		current = current->next;
	}

	current = NULL;
}






void LList::insert(int c, int p) //inserts node in order of power
{
	Term* temp = new Term(c, p);
	Term* current = &sent;
	//getting current pointer to correct poisition for insert
	while (current->next->pow > temp->pow)
	{
		current = current->next;
	}

	//rearranging pointers to insert the new node
	temp->next = current->next;
	temp->prev = current->next->prev;
	current->next->prev = temp;
	current->next = temp;


	//incrementing size
	size = size + 1;


	current = NULL;
	temp = NULL;

}







void LList::simplify() //simplifies a list who has multiple terms with same power
{
	//list must be sorted
	
	Term* current = this->sent.next;

	while (current != &sent)
	{
		if (current->pow == current->next->pow) //if the power of one node is the same as the one next to it
		{
			//add the coefficients and delete the next node
			current->coef = current->coef + current->next->coef;
			this->deleteThis(current->next);
		}
		else
		{
			//if no addition preformed, increment
			current = current->next;
		}
	}

	current = NULL;

}


void LList::removeFront() //removes from front of list
{
	Term *current = sent.next;
	current->next->prev = current->prev;
	current->prev->next = current->next;
	delete current;

	current = NULL;


	//decrement size
	size = size - 1;

}


void LList::deleteThis(Term* current) //deletes a node passed to function
{
	//rearranging pointers
	current->next->prev = current->prev;
	current->prev->next = current->next;

	current->next = NULL;
	current->prev = NULL;

	//deleting current
	delete current;

	//decrement size
	size = size - 1;
}

void LList::clearList()
{
//	cout << size << endl;
	Term *current = this->sent.next;

	while (current != &sent)
	{
		this->deleteThis(current);
		current = this->sent.next;

		//cout << size << endl;

	}

	current = NULL;

}


LList LList::operator+(const LList &rhsobj) //overloaded addition operator
{

	//pointer to this list
	Term *a = this->sent.next;
	//pointer to other list
	Term *b = rhsobj.sent.next;
	//current pointer
	Term *current;


	while (a != &this->sent)
	{
		//reseting b to equal the first node in the passed in list
		b = rhsobj.sent.next;

		while (b != &rhsobj.sent)
		{

			if (a->pow == b->pow)
			{
				//adding the coefficient of b to a
				a->coef = a->coef + b->coef;
				//setting current = b
				current = b;
				//incrementing b
				b = b->next;
				//deleting current
				this->deleteThis(current);

			}
			else
			{
				//	increment b
				b = b->next;
			}

		}
		//increment a

		a = a->next;


	}



	//this loop adds everything from the passed list
	//that was not added into the a list


	b = rhsobj.sent.next;
	while (b != &rhsobj.sent)
	{
		//insert sorts by power
		this->insert(b->coef, b->pow);
		b = b->next;
	}
	
	b = NULL;
	a = NULL;
	
	//returning this list
	return *this;

}


LList LList::operator-(const LList &rhsobj)  
{
	Term *a = this->sent.next;
	Term *b = rhsobj.sent.next;
	Term *current;

	//exact same as 


	while (a != &this->sent)
	{
		b = rhsobj.sent.next;
		while (b != &rhsobj.sent)
		{
			if (a->pow == b->pow)
			{
				a->coef = a->coef - b->coef;
				current = b;
				b = b->next;

				this->deleteThis(current);

			}
			else
			{
				//increment b
				b = b->next;
			}

		}
		//increment a
		a = a->next;
	}
	b = rhsobj.sent.next;
	while (b != &rhsobj.sent)
	{
		this->insert((b->coef)*-1, b->pow);
		b = b->next;
	}
	b = NULL;
	a = NULL;
	
	return *this;
}

LList LList::operator*(const LList &rhsobj)
{
	//two pointers, one assigned to each list
	Term *a = this->sent.next;
	Term *b = rhsobj.sent.next;

	//holds new coefficient and 
	//power variables
	int c = 0;
	int p = 0;

	//new list to hold the result
	LList result;

	
	//Mulitiplying each term by every other term in the other list
	while (a != &this->sent)
	{
		b = rhsobj.sent.next;
		while (b != &rhsobj.sent)
		{
			c = 0;
			p = 0;
			//multiplying coefficients
			c = a->coef * b->coef;
			//adding powers
			p = a->pow + b->pow;
			//inserting new term into list
			result.insert(c, p);
			//incrementing second list
			b = b->next;
		}
		//incrementing first list
		a = a->next;
	}

	a = NULL;
	b = NULL;
	//combines like terms
	result.simplify();

	return result;
}









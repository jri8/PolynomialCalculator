

#include "Term.h"
#include "LList.h"



ostream& operator<<(ostream &os, const Term &rhsObj) //overloaded ostream operator
{
	os << rhsObj.coef << "x^" << rhsObj.pow;
	return os;
}


Term Term::operator=(const Term &rhsobj) //overloaded assignment operator
{
	this->coef = rhsobj.coef;
	this->pow = rhsobj.pow;


	return *this;
}

bool Term::operator>(const Term &rhsobj)  //overloaded > operator
{
	if (this->pow > rhsobj.pow)
		return true;
	else
		return false;
}
bool Term::operator<(const Term &rhsobj) //overloade < operator
{
	if (this->pow < rhsobj.pow)
		return true;
	
		return false;

}
bool Term::operator==(const Term &rhsobj) //overloaded == operator
{
	if (this->pow == rhsobj.pow)
		return true;
	else
		return false;
}



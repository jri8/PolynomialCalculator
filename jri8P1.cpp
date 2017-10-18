




#include <fstream>
#include <string>
#include <sstream>
#include "LList.h"
#include "Stack.h"
#include "Term.h"



using namespace std;

//void uploadFile(string fname, LList &list);


int main(int argc, const char * argv[])
{
	string fname = argv[1];  //getting file name from command line
 	string info;  //holds a line of data from the file
	stringstream ss; //if the data is not a + - * then insert onto string stream
	fstream inFileStream; //contains file
	int x, y; //numbers used for inputs (inserted onto list)
	inFileStream.open(fname); //opening file

	
	LList list; //list that takes input terms and pushes onto stack
	LList list2; //list used in operations (when two polynomials are popped)
	LList result;  // holds list that results from operation

	stack s; //stack that holds lists (polynomials)


	if (!inFileStream) //checking if file opened
	{
		cout << "The input file failed to open. ";
		cout << "Check to ensure the file:\n" << fname << "\nis valid." << endl;
	}

	else //if file opened
	{
		while (!inFileStream.eof()) //read to end of file
		{

			getline(inFileStream, info); //get line and store in info


			if (info == "+" || info == "-" || info == "*") //if it is an operator
			{
				list = s.top(); //get top value in stack and store in list
			// flag  	cout << "number 1:" << list << endl; 


				s.pop(); //pop top of stack
				list2 = s.top(); //get top value in stack and store in list2

			//flag  	cout << "number 2: " << list2 << endl;

				s.pop(); //pop top of stack

				if (info == "+") //if addition operator
					result = list + list2; //preform addition and store in result

				else if (info == "-") //if subtraction operator
					result = list2 - list; //prefrom subtraction and store in result

				else //if multiplication operator
					result = list * list2; //preform multiplication and store in result

			//flag  	cout << "result of operation: "; 
			//flag  	cout << result << endl; 
				s.push(result); //push result back onto stack




				result.clearList(); //clear result
				list.clearList(); //clear list
				list2.clearList(); //clear list2

			}

			else //if input is not an operator
			{

				ss << info; //pass info to stringstream object

				while (ss >> x >> y) //read string stream until empty
				{
					list.insert(x, y); //insert read in values to a term (node) in the list
					
				}

				s.push(list); //push list onto stack

				ss.clear(); //clear stringstream
				list.clearList(); //clear list
			}
		}
		cout << s.top() << endl; //outputting top of list after loops finish (final result)
	}

//	cin.get(); //holds output window open in visual studio
	return 0;

}















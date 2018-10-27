//LinkedList.cpp
//Brandon Steege
//Project One
//10/26/18

/*
This is a heavily modified version of the file that was used for lab 2.
I did not write all of this code, I have indicated which code has been created
for this lab and which code has been reused from lab 2. 
DESCRIPTION: This file holds all of the functions for the linked list class. 
*/

#include "LinkedList.h"
#include <utility>
#include <cmath>

using std::stof; //used for converting string to float
using std::abs; //used for determining absolute value

List weekOne; //initializing list to hold all values from week one
List weekTwo; //initializing list to hold all values from week two

int weekOneArray[7]; //initializing array to hold all sizes for each day in week one
int weekTwoArray[7]; //initializing array to hold all sizes for each day in week one
int dayCount(0); //counter that counts number of days
int between(0); // int that determines which days the delta is inbetween


/*
This function is used to insert the data for each day into each day's own linked list
bloodSugar is the initial input of the user
*/
void List::insertData(string bloodSugar)
{

	int validCount(0); //counter for all valid float inputs

	while ((bloodSugar.compare("N") != 0 ) && (bloodSugar.compare("Next") != 0))//While loop that continues to run until "Next" or "N" is inputted
	{
		if (bloodSugar == "D") //Determines if bloodSugar equals D, then prints out the statement below for the day summary
		{
			cout << "		\nDaily Summary\n" << "Daily Blood Sugar Readings Sum: " << sum() << endl << "Daily Max: " << max() << endl
				<< "Daily Min: " << min() << endl << "Valid Count: " << validCount << endl;
			cin >> bloodSugar;
		}
		if (bloodSugar == "Day") //Determines if bloodSugar equals D, then prints out the statement below for the day summary
		{
			cout << "		\nDaily Summary\n" << "Daily Blood Sugar Readings Sum: " << sum() << endl << "Daily Max: " << max() << endl
				<< "Daily Min: " << min() << endl << "Valid Count: " << validCount << endl;
			cin >> bloodSugar;
		}
		else if (bloodSugar == "W" ) //Determines if bloodSugar equals W, then prints out the statement below for the week summary
		{
			if (dayCount <= 7) //This is used to print the week one summary
			{
				cout << "		Week One Summary\n" << "Weekly Blood Sugar Readings Sum: " << weekOne.sum() << endl << "Weekly Max: " << weekOne.max() << endl
					<< "Weekly Min: " << weekOne.min() << endl << "Valid Count: " << weekOne.size() << endl << "Greatest Delta Value: " << delta(weekOneArray) <<
					" between days " << between << " and " << between + 1 << endl;
				cin >> bloodSugar; //input next value
			}
			else //Prints out the week two summary
			{
				cout << "		Week Two Summary\n" << "Weekly Blood Sugar Readings Sum: " << weekTwo.sum() << endl << "Weekly Max: " << weekTwo.max() << endl
					<< "Weekly Min: " << weekTwo.min() << endl << "Valid Count: " << weekTwo.size() << endl << "Greatest Delta Value: " << delta(weekTwoArray) <<
					" between days " << between << " and " << between + 1 << endl;
				cin >> bloodSugar;// input next value
			}

		}
		else if (bloodSugar == "Week") //Determines if bloodSugar equals W, then prints out the statement below for the week summary
		{
			if (dayCount <= 7) //This is used to print the week one summary
			{
				cout << "		Week One Summary\n" << "Weekly Blood Sugar Readings Sum: " << weekOne.sum() << endl << "Weekly Max: " << weekOne.max() << endl
					<< "Weekly Min: " << weekOne.min() << endl << "Valid Count: " << weekOne.size() << endl << "Greatest Delta Value: " << delta(weekOneArray) <<
					" between days " << between << " and " << between + 1 << endl;
				cin >> bloodSugar; //input next value
			}
			else //Prints out the week two summary
			{
				cout << "		Week Two Summary\n" << "Weekly Blood Sugar Readings Sum: " << weekTwo.sum() << endl << "Weekly Max: " << weekTwo.max() << endl
					<< "Weekly Min: " << weekTwo.min() << endl << "Valid Count: " << weekTwo.size() << endl << "Greatest Delta Value: " << delta(weekTwoArray) <<
					" between days " << between << " and " << between + 1 << endl;
				cin >> bloodSugar;// input next value
			}

		}
		else //Any other value is then ran through the following code
		{
			float bloodSugarFloat = stof((bloodSugar).c_str(), 0); //converts bloodSugar to a float
			if (bloodSugarFloat > 0) //makes sure the float is greater than zero
			{
				if (dayCount <= 7) //determines which week list to add to, in this case weekOne
				{
					insertAsFirst(bloodSugarFloat); // inserts bloodSugar as a float to the current day
					weekOne.insertAsFirst(bloodSugarFloat); // inserts bloodSugar to current week
					weekOneArray[dayCount] = size(); //adjusts the size of the week one array that is used for delta calculation
					cin >> bloodSugar; // input next value
					validCount++; // increment valid count
				}
				else//adds to weekTwo
				{
					insertAsFirst(bloodSugarFloat); //inserts bloodSugar as a float to the current day
					weekTwo.insertAsFirst(bloodSugarFloat); //inserts bloodSugar a a float to the current week
					weekTwoArray[dayCount] = size(); //adjusts the size of the week two array that is used for delta calculation
					cin >> bloodSugar; // input next value
					validCount++; // increment valid count
				}

			}
			else //for anything less than zero
			{
				cin >> bloodSugar; //enter a new value
			}
		}
	}
	dayCount++; // increment dayCount
}


/*
The min() function is used to determine the minimum value of a given list
*/
float List::min() const
{
	Node * ptr = first_; //sets the pointer to the initial value in a list
	float min = ptr->entry_; //sets min equal to the loation of the pointer
	float current(0); //initializes current to 0

	if (!empty()) //while loop continues to run if the list isn't empty
	{

		while (ptr != NULL)//ensures that the pointer is at a node with values in it
		{
			current = ptr->entry_; // sets current to location if the pointer 
			ptr = ptr->next_; //pointer moves to next location
			if (min <= current) // if min values is less than current value
			{
				current = min; //sets current to min
				min = current; //sets min to current
			}
			else
			{
				min = current; //min is set to current
			}
		}
	}
	else // if list is empty, min is set to zero
	{
		min = 0;
	}
	return min; // returns min
}

/*
Max determins the maximum value of a given list
*/
float List::max() const
{
	Node * ptr = first_; //sets the pointer to the initial value in a list
	float max = ptr->entry_; //sets max equal to the loation of the pointer
	float current(0); //initializes current to 0

	if (!empty()) //while loop continues to run if the list isn't empty
	{

		while (ptr != NULL) //ensures that the pointer is at a node with values in it
		{
			current = ptr->entry_; // sets current to location if the pointer 
			ptr = ptr->next_; //pointer moves to next location
			if (max >= current) // if max values is less than current value
			{
				current = max; //sets current to max
				max = current; //sets max to current
			}
			else
			{
				max = current;//max is set to current
			}
		}
	}
	else // if list is empty, max is set to zero
	{
		max = 0;
	}
	return max; // returns max
}

/*
Determines the delta of the array. Delta = |count[x] - count[x -1] |
*/
int List::delta(int array[]) const //returns int and takes an int array for parameters
{
	int delta(0); //initializes delta to 0
	int count(1); //initializes count to 1
	int dayDif; //initializes dayDif
	if (dayCount == 0) //if the day count is equal to zero, then dayDif will be returned as zero
	{
		dayDif = 0;
	}

	else 
	{
		while (count <= (dayCount + 1)) //ensures that all values are iterated through
		{
			dayDif = abs((array[count]) - (array[count - 1])); //uses inital equation, abs is used to determine the absolute value
			if (dayDif >= delta) // if dayDif is greater than delta
			{
				delta = dayDif; //delta is set equal to dayDif
				dayDif = delta; //dayDif is set equal to delts
			}
			else 
			{
				dayDif = delta;
			}
			count++; //increment the local count
		}

	}

	between = dayCount + 1; //sets between to day count + 1 to display in a way that will make sense to the user eg. day 0 now equals day 1.
	return dayDif; //returns dayDif
}


///////////////////////////////////////////////////////// *ALL OF THE CODE BELOW IS UNALTERED FROM LAB 2* \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

List::List()
	: first_(NULL)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}

const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}

	return *this;
}

bool List::empty() const
{
	return first_ == NULL;
}


void List::insertAsFirst(double x)
{
	first_ = new Node(x, first_);
}

double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;
}

void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}

float List::sum() const
{
	Node * ptr = first_;
	float sum(0);

	if (!empty())
	{
		while (ptr != NULL)
		{
			sum += ptr->entry_;
			ptr = ptr->next_;
		}
	}
	return sum;
}

int List::size() const
{
	int count(0);

	if (!empty())
	{
		count = 1;
		Node * ptr = first_;
		while (ptr->next_ != NULL)
		{
			ptr = ptr->next_;
			count++;
		}
	}
	else
	{
		count = 0;
	}
	return count;
}


// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}

////////////////////////////////////////////////////////////////////// *END OF CODE* \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\





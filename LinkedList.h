//LinkedList.h
//Brandon Steege
//Project One
//10/26/18

/*
This is a heavily modified version of the file that was used for lab 2.
I did not write all of this code, I have indicated which code has been created
for this lab and which code has been reused from lab 2.
DESCRIPTION: This file holds all of the function definitions for the linked list class.
*/

// A List stores and manages a sequence of doubles.

// This version uses a pointer to the first Node of a
//   singly linked list of Nodes.


#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <iostream>
using std::ostream;
#include <string>
using std::string;
using std::cin;
#include "Node.h"

#define ulong unsigned long


class List
{
public:
	//*** Standard functions ***

	// Default constructor
	// post: this List is empty.
	List();

	// Copy constructor
	// post: this List now stores a copy of the sequence stored
	//         in other
	List(const List & other);

	// Destructor
	// post: all the Nodes of this List have been destroyed.
	~List();

	// Assignment operator
	// post: this List now stores a copy of the sequence stored
	//         in other
	const List & operator=(const List & other);

	// post: true has been returned just if this List is
	//         empty.
	bool empty() const;

	// post: x has been added as the first double in this
	//         List.
	void insertAsFirst(double x);

	// pre:  this List is not empty.
	// post: the first double in this List has been removed
	//         from this List and has been returned.

	double removeFirst();

	// post: the doubles in this List have been written to
	//         outfile.
	void print(ostream & outfile) const;

	///////////////////////////////////////////////////// * ALL CODE BELOW HAS BEEN WRITEN FOR THIS LAB, EXCEPT FOR PRIVATE SECTION \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	float sum() const;

	float min() const;

	float max() const;

	int delta(int array[] ) const;

	int size() const;

	void insertData(string bloodSugar);

/////////////////////////////// *NOT WRITTEN BY ME, REUSED FROM LAB 2\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

private:
	//*** Inaccessible standard functions ***


	//*** Helper functions ***
	// process part of the linked structure

	// post: a pointer to a copy of the linked structure
	//         targeted by ptr has been returned.
	static Node * clone(Node * ptr);


private:
	Node * first_;

};


//*** Auxiliary functions ***

// post: the doubles in list have been written to outfile
ostream & operator<<(ostream & outfile, const List & list);

#endif

// CSCI 2530
// Assignment: 06	
// Author:     ****
// File:       pqueue.h
// Tab stops:  none

// ** This is a header file for priority queue **

// type for queue items
#include "event.h"

typedef Event* ItemType;

// type for queue priority

typedef double PriorityType;

// function ItemPrinter will print the item of the linked list

typedef void(*ItemPrinter)(ItemType);

// function PriorityPrinter will print the priority of the linked list

typedef void(*PriorityPrinter)(PriorityType);

// PQCell is type of elements of linked list


struct PQCell
{
	ItemType item;
	PriorityType priority;
	struct PQCell* next;
};

// PriorityQueue implements priority queue as 
// linked list of non-decreasing priorities
// 'list' holds a pointer to a linked list of PQCells

typedef struct PriorityQueue
{
	struct PQCell* list;
	PriorityQueue() { list = NULL; }

} PriorityQueue;

// Function isEmpty(q) returns true if 'q' is an empty priority queue
// returns false, if 'q' is not empty

bool isEmpty(const PriorityQueue& q);

// insert(q, x, p) inserts new item 'x' with 
// priority 'p' into priority queue 'q'

void insert(PriorityQueue& q, ItemType x, PriorityType p);

// Function prints all elements of priority queue 'q' (each element in one line)
// Function (pi) is used for printing item. 
// Function (pp) is used for printing priority.

void printPriorityQueue(const PriorityQueue& q,
	ItemPrinter pi, PriorityPrinter pp);

// remove(q, x, p) removes from the priority 
// queue 'q' the item that has the smallest priority. 
// Stores the item that is removed into variable 'x'
// and stores 'x's priority into 'p'.
// If 'q' is empty, then remove(q, x, p) writes a message on the standard 
// output and stops the program

void remove(PriorityQueue& q, ItemType& x, PriorityType& p);
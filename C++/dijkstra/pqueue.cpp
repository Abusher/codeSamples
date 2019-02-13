// CSCI 2530
// Assignment: 06	
// Author:     ***
// File:       pqueue.cpp
// Tab stops:  none

// ** This is an implementation file for priority queue **

#include <cstdlib>
#include <cstdio>
#include "pqueue.h"


// Function isEmpty(q) returns true if 'q' is an empty priority queue
// returns false, if 'q' is not empty

bool isEmpty(const PriorityQueue& q)
{
	return q.list == NULL;
}

// insertCell(L, x, p) inserts item 'x' with priority 'p' into linked list 'L'

void insertCell(PQCell*& L, ItemType x, PriorityType p)
{
	PQCell* next_pqcell;

	if (L == NULL)
	{
		L = new PQCell;
		L->item = x;
		L->priority = p;
		L->next = NULL;
	}
	else if (L->priority > p)
	{
		next_pqcell = L;
		L = new PQCell;
		L->item = x;
		L->priority = p;
		L->next = next_pqcell;
	}
	else
	{
		insertCell(L->next, x, p);
	}
}

// insert(q, x, p) inserts new item 'x' 
// with priority 'p' into priority queue 'q'

void insert(PriorityQueue& q, ItemType x, PriorityType p)
{
	insertCell(q.list, x, p);
}

// Function prints all elements of priority queue 'q' (each element in one line)
// Function (pi) is used for printing item. 
// Function (pp) is used for printing priority.

void printPriorityQueue(const PriorityQueue& q,
	ItemPrinter pi, PriorityPrinter pp)

{
	PQCell *pcell;
	pcell = q.list;

	while (pcell != NULL)
	{
		pi(pcell->item);
		printf(" ");
		pp(pcell->priority);
		printf("\n");

		pcell = pcell->next;
	}
}

// remove(q, x, p) removes from the priority queue 'q' the 
// item that has the smallest priority. 
// Stores the item that is removed into variable 'x' and 
// stores 'x's priority into 'p'.
// If 'q' is empty, then remove(q, x, p) writes a message on the standard 
// output and stops the program

void remove(PriorityQueue& q, ItemType& x, PriorityType& p)
{
	PQCell *oldItem;

	if (isEmpty(q))
	{
		printf("\nUnable to remove an item. Queue is empty.\n");
		printf("\n");
		exit(1);
	}

	oldItem = q.list;
	x = oldItem->item;
	p = oldItem->priority;
	q.list = oldItem->next;

	delete oldItem->item;
	delete oldItem;
}
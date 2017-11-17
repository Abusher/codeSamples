// CSCI 2530
// Assignment: ***
// Author:     ***
// File:       ***
// Tab stops:  ***

// Program reads Graph from standard input and stores it in Graph object, 
// then finds the shortest path from vertex s to vertex e by using of Dijkstra's 
// algorithm, and output on standard output the shortest path and its distance
// Example:
// Input graph:
//  5
//  1 2  9.0
//  1 3 12.0
//  2 4 18.0
//  2 3  6.0
//  2 5 20.0
//  3 5 15.0
//  0
//  1 5
//There are 5 vertices and 6 edges.
//The edges are as follows.
//
//(1, 3) weight 12.000
//(1, 2) weight 9.000
//(2, 5) weight 20.000
//(2, 3) weight 6.000
//(2, 4) weight 18.000
//(3, 5) weight 15.000
//
//The shortest path from 1 to 5 has length 27.000 and is
//1 -> 3 -> 5



#include <stdio.h>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "pqueue.h"

using namespace std;

// structures

struct LinkedList
{
	int to;
	double weight;
	LinkedList* next;
	
	LinkedList(int v, double w); //constructor
};

struct Vertex
{
	LinkedList* adjList;
	LinkedList* headList;
	double dist;
	int from;

	Vertex(); //constructor
	~Vertex()
	{
		while (headList)
		{
			LinkedList* cur = headList;
			headList = headList->next;
			delete cur;
		}		
	}
};

struct Edge
{
	int v1, v2;   // vertices of edge
    double weight;   // weight of edge
	Edge* next;

	Edge();
	Edge(int u, int v, double w, Edge* _next); // constructor 

};

const int maxVertices = 100; // maximal possible number of edges in graph

struct Graph
{
	int nVertex, nEdges; // numbers of Vertices and Edges
	Vertex Vertices[maxVertices]; // array of Edge objects

	Graph(int nv);       // constructor
};

//constructor initializes linked list node with number passed as argument
LinkedList::LinkedList(int v, double w)
{
	to = v;
	weight = w;
}

// constructor initializes two values with -1 and third with nullptr
Vertex::Vertex():
	adjList(nullptr),
	headList(nullptr),
	dist(-1.0),
	from(-1)
{}


// constructor initializes all values with 0  

Edge::Edge()
{
	v1 = v2;
	weight = 0.0;
	next = nullptr;
}

// constructor initializes values with function arguments

Edge::Edge(int u, int v, double w, Edge* _next)
{
	v1 = u;
	v2 = v;
	weight = w;
	next = _next;
}

// constructor initializes values

Graph::Graph(int nv)
{
	nVertex = nv;
	nEdges = 0;
}

// insertEdge(u, v, w, g) inserts an edge of weight w between vertices
// u and v into graph g.
//

void insertEdge(int u, int v, double w, Graph& G)
{
	//create edge (u,v)
	if (G.Vertices[u].adjList == nullptr)
	{
		G.Vertices[u].adjList = new LinkedList(v,w);
		G.Vertices[u].headList = G.Vertices[u].adjList;
	}
	else
	{
		G.Vertices[u].adjList->next = new LinkedList(v,w);
		G.Vertices[u].adjList = G.Vertices[u].adjList->next;
	}

	//create edge (v,u)
	if (G.Vertices[v].adjList == nullptr)
	{
		G.Vertices[v].adjList = new LinkedList(u,w);
		G.Vertices[v].headList = G.Vertices[v].adjList;
	}
	else
	{
		G.Vertices[v].adjList->next = new LinkedList(u,w);
		G.Vertices[v].adjList = G.Vertices[v].adjList->next ;
	}

	G.Vertices[u].adjList->next = nullptr;
	G.Vertices[v].adjList->next = nullptr;
	++G.nEdges;
}

// Reads Graph G from the standart input and
// stores vertices values into {u, v,} and weight 
// value into {w} these make up graph G.

void readGraph(Graph& G)
{
	int nV = 0;
	scanf("%d", &nV);
	G.nVertex = nV;

	while (G.nVertex != 0)
	{
		int u, v;
		double w;
		scanf("%d", &u);
		if (u == 0) break;
		scanf("%d%lf", &v, &w);
		insertEdge(u, v, w, G);
	}
}

// Writes Graph G on the standard output
// with given vertices and weights.

void writeGraph(Graph& G)
{
	printf("%s%d%s%d%s", "\nThere are ", G.nVertex,
		" vertices and ", G.nEdges, " edges.\n");

	printf("The edges are as follows.\n\n");
	for (int i = 1; i <= G.nVertex; ++i)
	{
		LinkedList* head = G.Vertices[i].headList;
		while (head)
		{
			if (i < head->to)
			{
				printf("(%d,%d) weight %.3lf\n", i, head->to,head->weight);
			}

			head = head->next;
		}
	}

	printf("\n");
}

void sendSignal(int from, int to, double time, PriorityQueue& queue)
{
	Event* event = new Event(from, to, time);
	insert(queue, event, time);
}

void propagateSignal(Graph& G, int v, PriorityQueue& queue)
{
	LinkedList *head = G.Vertices[v].headList;
	for (;head;head=head->next)
	{
		Vertex& toV = G.Vertices[head->to];
		if (toV.dist == -1)
		{
			sendSignal(v, head->to, head->weight, queue);
		}
	}
}

void processEvent(Graph& G, PriorityQueue& queue, Event* e)
{
	Vertex& fromV = G.Vertices[e->receiver];
	if (fromV.dist == -1 || fromV.dist > e->time)
	{
		fromV.dist = e->time;
		fromV.from = e->sender;

		LinkedList *head = fromV.headList;
		for (; head; head = head->next)
		{
			Vertex& toV = G.Vertices[head->to];
			if (toV.dist == -1|| toV.dist > head->weight + e->time)
			{
				sendSignal(e->receiver, head->to, head->weight + e->time, queue);
			}
		}
	}
}

void dijkstra(Graph& G, int s, int e, PriorityQueue& queue)
{
	sendSignal(0, s, 0, queue);

	while (isEmpty(queue)==false)
	{
		Event* event = queue.list->item;
		processEvent(G, queue, event);
		remove(queue, event, event->time);
	}
}

vector<int> getPath(int from, int to, Graph& G)
{
	vector<int>path;
	while (true)
	{
		path.push_back(to);
		if (to == from)
		{
			break;
		}
		else
		{
			to = G.Vertices[to].from;
		}
	}

	return path;
}

int main()
{
	Graph G(0);
	printf("%s", "\nPlease input Graph : \n");
	readGraph(G);
	int s, e;
	scanf("%d%d", &s, &e);

	writeGraph(G);

	PriorityQueue pqueue;
	dijkstra(G, s, e, pqueue);

	printf("The shortest path from %d to %d has length %.3lf and is\n", s,e,G.Vertices[e].dist);

	vector<int>path = getPath(s,e,G);
	printf("%d", path.back());
	for (int i = path.size() - 2; i >= 0; --i)
	{
		printf("->%d", path[i]);
	}

	printf("\n");
	return 0;
}
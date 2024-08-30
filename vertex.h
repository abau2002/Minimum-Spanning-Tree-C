// FILE: vertex.h
// Armando Bautista
// OS, Fall 2023
// 
//	Interface for vertex.c
//

#include <limits.h>
#include <stdbool.h>

#ifndef VERTEX_H
#define VERTEX_H

#define GRAPH_MAX 1000
#define VERTEX_MAX CHAR_MAX

typedef char Vertex[VERTEX_MAX];

typedef struct{
	Vertex child;
	Vertex parent;
	float key;
	bool processed;
} Child;

typedef struct {
    Child vertices[GRAPH_MAX];
    int vertexCount;
} Children;

// takes in a vertex and the vertexCount of the vertices in children and returns true if vertex is found in children
bool inVertices(Children* children,Vertex vertex,int vertexCount);

// takes in children and the root and initializes them
void initializeChildren(Children* children,Vertex root);

// takes a vertex and children and returns the key of the vertex
// if vertex not found, returns -1
float getKey(Vertex vertex,Children* children);

// takes in a vertex in children and updates its key to be weight and its parent to be the vertex at minIndex in children
void updateChild(Vertex vertex,int minIndex,float weight,Children* children);

// takes in children and returns true if all children have been processed
bool allProcessed(Children* children);

// takes in children and returns the index of the vertex with the minimum key
int extractMin(Children* children);

// makes a root into a rootVertex
void setRoot(char* root,Vertex rootVertex);

#endif // VERTEX_H
// FILE: edge.h
// Armando Bautista
// OS, Fall 2023
// 
//	Interface for edge.c
//

#include <stdbool.h>
#include "vertex.h"

#ifndef EDGE_H
#define EDGE_H

typedef struct{
	Vertex vertex1;
	Vertex vertex2;
	float weight;
} Edge;

// returns true if vertex is in the edge
bool inEdge(Edge* edge, Vertex vertex);


#endif // EDGE_H

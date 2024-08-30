// FILE: utilities.h
// Armando Bautista
// OS, Fall 2023
// 
//	Interface for utilities.c
//

#ifndef UTILITIES_H
#define UTILITIES_H

#include "graph.h"
#include "vertex.h"

// returns true if weight is less than key
bool weightLessKey(float weight,float key);

// finds all vertices connected to vertex within graph and loads them into connections
int findConnections(Child* vertex,Graph* graph,Vertex* connections);

// takes in a graph and children and updates children to have the final keys and parents for the MST
void MST(Children* children,Graph* graph);


#endif // UTILITIES_H
// FILE: edge.c
// Armando Bautista
// OS, Fall 2023
// 
//	Contains all functions that operate directly on Edge
//

#include "edge.h"
#include "vertex.h"
#include <string.h>
#include <stdbool.h>

bool inEdge(Edge* edge, Vertex vertex){
	if(!strcmp(edge->vertex1,vertex) || !strcmp(edge->vertex2,vertex)) return true;
	return false;
}
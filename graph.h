// FILE: graph.h
// Armando Bautista
// OS, Fall 2023
// 
//	Interface for graph.c
//

#include "vertex.h"
#include "edge.h"

#ifndef GRAPH_H
#define GRAPH_H

typedef struct {
    Edge edges[GRAPH_MAX];
    int edgeCount;
} Graph;

// takes in a graph and loads the vertices into children
void getVertices(Graph* graph,Children* children);

// takes in a graph and two vertices and returns the weight of their edge
// if edge not found, returns -1
float getWeight(Graph* graph,Vertex vertex1,Vertex vertex2);

// takes in a file name and root and loads the edges into graph
void loadGraph(char* fileName,Vertex root,Graph* graph);

#endif // GRAPH_H

// FILE: utilities.c
// Armando Bautista
// OS, Fall 2023
// 
//	Contains all functions that do not easily fit into other implementation files
//

#include "graph.h"
#include "vertex.h"
#include "utilities.h"
#include <string.h>

bool weightLessKey(float weight ,float key){
	if(weight < key) return true;
	return false;
}

int findConnections(Child* vertex,Graph* graph,Vertex* connections){
	int connectCount = 0;
	for(int i=0;i<graph->edgeCount;i++){
		if(!strcmp(vertex->child, graph->edges[i].vertex1)){
			strcpy(connections[connectCount++],graph->edges[i].vertex2);
		}
		else if(!strcmp(vertex->child, graph->edges[i].vertex2)){
			strcpy(connections[connectCount++],graph->edges[i].vertex1);
		}
	}
	return connectCount;
}

void MST(Children* children,Graph* graph){
	Vertex connections[GRAPH_MAX];
	int minIndex,connectCount;
	float weight,key;

	while(!allProcessed(children)){
		minIndex = extractMin(children);

		connectCount = findConnections(&children->vertices[minIndex],graph,connections);
		for(int i=0;i<connectCount;i++){
			weight = getWeight(graph,children->vertices[minIndex].child,connections[i]);
			key = getKey(connections[i],children);
			if(inVertices(children,connections[i],children->vertexCount) && weightLessKey(weight,key)){
				updateChild(connections[i],minIndex,weight,children);
			}
		}
	}
}

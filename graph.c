// FILE: graph.c
// Armando Bautista
// OS, Fall 2023
// 
//	Contains all functions that are needed to interact on the Graph data type
//

#include "edge.h"
#include "graph.h"
#include "vertex.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void getVertices(Graph* graph, Children* children){
	int vertexCount = 0;
	for(int i=0;i<graph->edgeCount;i++){
		if(!inVertices(children, graph->edges[i].vertex1,vertexCount)){
			strcpy(children->vertices[vertexCount++].child,graph->edges[i].vertex1);
		}
		if(!inVertices(children, graph->edges[i].vertex2,vertexCount)){
			strcpy(children->vertices[vertexCount++].child,graph->edges[i].vertex2);
		}
	}
	children->vertexCount = vertexCount;
}

float getWeight(Graph* graph,Vertex vertex1,Vertex vertex2){
	for(int i=0;i<graph->edgeCount;i++){
		if(inEdge(&graph->edges[i],vertex1) && inEdge(&graph->edges[i],vertex2)){
			return graph->edges[i].weight;
		}
	}
	return -1;
}

void loadGraph(char* fileName,Vertex root,Graph* graph){
	Edge currentEdge;
	int edgeCount=0,scanInput;
	FILE* inputFile = fopen(fileName,"r");
	bool validRoot = false;

	if(inputFile == NULL){
		printf("\tERROR: File not found\n");
		exit(1);
	}

	scanInput = fscanf(inputFile,"%s",currentEdge.vertex1);
	while(scanInput != EOF){
		fscanf(inputFile,"%s %f",currentEdge.vertex2,&currentEdge.weight);

		if(currentEdge.weight<0){
			printf("\tERROR: Weights should be non-negative numbers\n");
			exit(1);
		}

		// if root is found in vertices then set validRoot to true
		if(!strcmp(currentEdge.vertex1,root) || !strcmp(currentEdge.vertex2,root)) validRoot = true;

		graph->edges[edgeCount++] = currentEdge;

		scanInput = fscanf(inputFile,"%s",currentEdge.vertex1);
	}
	fclose(inputFile);

	if(!validRoot){
		printf("\tERROR: Root %s not found in %s\n",root,fileName);
		exit(1);
	}

	graph->edgeCount = edgeCount;
}
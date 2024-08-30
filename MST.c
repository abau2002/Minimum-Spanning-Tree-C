// FILE: MST.c
// Armando Bautista
// OS, Fall 2023
// 
//	Driver for MST, takes in a root and a graph file and prints out a MST
//
// https://www.educative.io/answers/what-is-infinity-in-c 10-24-2023
//

#include "graph.h"
#include "vertex.h"
#include "utilities.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char** argv){
	Graph graph;
	Children children;
	Vertex root;

	if(argc != 3){
		printf("\tERROR: Please only give 2 arguments (graph file and a root)\n");
		exit(1);
	}

	setRoot(argv[2],root);

	loadGraph(argv[1],root,&graph);

	getVertices(&graph,&children);

	initializeChildren(&children,root);

	MST(&children,&graph);

	printMST(root,&children);
	return 0;
}

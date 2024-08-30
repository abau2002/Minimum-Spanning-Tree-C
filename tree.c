// FILE: tree.c
// Armando Bautista
// OS, Fall 2023
// 
//	Contains all functions needed to print out a tree and its weight
//

#include "vertex.h"
#include "tree.h"
#include <string.h>
#include <stdio.h>

void printTree(Children* children, Vertex root) {
    for (int i = 0; i < children->vertexCount; i++) {
    	// only encloses a vertex in parantheses if its parent is the current root
        if (!strcmp(children->vertices[i].parent, root)) {
            printf(" (%s", children->vertices[i].child);
            printTree(children,children->vertices[i].child);
            printf(")");
        }
    }
}

float calcTreeWeight(Children* children){
	float totalWeight=0;
	for(int i=0;i<children->vertexCount;i++) totalWeight += children->vertices[i].key;
	return totalWeight;
}

void printMST(Vertex root,Children* children){
	printf("\tTree: (%s",root);
    printTree(children, root);
    printf(")\n\tTotal Weight: %f\n",calcTreeWeight(children));
}
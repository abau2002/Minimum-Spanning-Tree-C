// FILE: vertex.c
// Armando Bautista
// OS, Fall 2023
// 
//	Contains all functions needed to interact with Vertex, Children, and Child
//

#include "vertex.h"
#include <math.h>
#include <string.h>
#include <stdbool.h>

bool inVertices(Children* children, Vertex vertex, int vertexCount){
	// return true if vertex is in children and has not been processed
	for(int i=0;i<vertexCount;i++) if(!strcmp(children->vertices[i].child,vertex) && !children->vertices[i].processed) return true;
	return false;
}

void initializeChildren(Children* children,Vertex root){
	for(int i=0;i<children->vertexCount;i++){
		if(!strcmp(children->vertices[i].child,root)){
			children->vertices[i].key = 0;
		}
		else{
			children->vertices[i].key = INFINITY;
		}
		children->vertices[i].processed = false;
		strcpy(children->vertices[i].parent,"");
	}
}

float getKey(Vertex vertex,Children* children){
	for(int i=0;i<children->vertexCount;i++){
		if(!strcmp(children->vertices[i].child,vertex)){
			return children->vertices[i].key;
		}
	}
	return -1;
}

void updateChild(Vertex vertex,int minIndex,float weight,Children* children){
	for(int i=0;i<children->vertexCount;i++){
		if(!strcmp(children->vertices[i].child,vertex)){
			strcpy(children->vertices[i].parent,children->vertices[minIndex].child);
			children->vertices[i].key = weight;
		}
	}
}

bool allProcessed(Children* children){
	for(int i=0;i<children->vertexCount;i++) if(!children->vertices[i].processed) return false;
	return true; 
}

int extractMin(Children* children){
	float minKey = INFINITY;
	int minIndex;

	for(int i=0;i<children->vertexCount;i++){
		if(!children->vertices[i].processed && children->vertices[i].key<minKey){
			minKey = children->vertices[i].key;
			minIndex=i;
		}
	}
	children->vertices[minIndex].processed = true;
	return minIndex;
}

void setRoot(char* root,Vertex rootVertex){
	strcpy(rootVertex,root);
}
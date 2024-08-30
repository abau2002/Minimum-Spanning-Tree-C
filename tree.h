// FILE: tree.h
// Armando Bautista
// OS, Fall 2023
// 
//	Interface for tree.c
//

#include "vertex.h"

#ifndef TREE_H
#define TREE_H

// takes in children and the root and prints out a tree
void printTree(Children* children, Vertex root);

// takes in children and return the total weight of them
float calcTreeWeight(Children* children);

// takes in children and the root and prints out the MST with its weight
void printMST(Vertex root, Children* children);

#endif // TREE_H
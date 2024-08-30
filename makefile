# FILE: makefile
# Armando Bautista, Transy U
# OS, Fall 2023
# 
#	makefile for C MST
#

MST: MST.o graph.o edge.o utilities.o vertex.o tree.o
	gcc MST.o graph.o edge.o utilities.o vertex.o tree.o -o MST

MST.o: MST.c graph.h utilities.h vertex.h tree.h
	gcc -c MST.c

graph.o: graph.c graph.h edge.h vertex.h
	gcc -c graph.c

edge.o: edge.c edge.h vertex.h
	gcc -c edge.c

utilities.o: utilities.c utilities.h graph.h vertex.h
	gcc -c utilities.c

vertex.o: vertex.c vertex.h
	gcc -c vertex.c

tree.o: tree.c tree.h vertex.h
	gcc -c tree.c
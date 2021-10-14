#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"


int main()
{
	Graph G;
	scanf("%d", &G.V);
	init_graph(&G);
	add_edge(&G);
	printf("\n printing graph G \n");
	print_graph(&G);
	printf("\n finished printing graph G \n");
	printf("\n printing graph F \n");
	prims_mst(&G);
	printf("\n finished printing graph F \n");
	getch();
}

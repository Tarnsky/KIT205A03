#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"


int main()
{
	Graph G;
	scanf("%d", &G.V);
	init_graph(&G);
	//add_edge
	for (int i = 0; i < G.V; i++) {
		int temp;
		scanf("%d", &temp);

		for (int j = 0; j < temp; j++) {
			Edge new_node;
			scanf("%d,%d", &new_node.to_vertex, &new_node.weight);
			printf("\n At city %d \n", i);
			printf("\n first node link weight to %d \n", new_node.weight);
			printf("\n first node link to_vertex to %d \n", new_node.to_vertex);
			int current_node = new_node.to_vertex;
			insert_at_front(&G.edges[i], new_node);
			int in_degree = malloc(sizeof(G.V));
			//create link between Cities
			int from_node = i;
			printf("\n from node %d \n", from_node);
			Edge new_node_link;
			new_node_link.to_vertex = i;
			printf("\n link node link to %d \n", i);
			new_node_link.weight = new_node.weight;
			printf("\n link node link weight to %d", new_node_link.weight);

			insert_at_front(&G.edges[current_node], new_node_link);
		}
	}
	//printf("\n printing graph G \n");
	//print_graph(&G);
	//printf("\n finished printing graph G \n");
	//printf("\n printing in_degree for G \n");
	//in_degree(&G);
	//printf("\n finished printing in_degree graph G \n");
	printf("\n printing graph F \n");
	prims_mst(&G);
	printf("\n finished printing graph F \n");
	getch();
}

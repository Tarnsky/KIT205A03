#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

//5
void init_graph(Graph* self)
{
	self->edges = malloc(sizeof(EdgeList) * self->V);
	for (int i = 0; i < self->V; i++) {
		self->edges[i].head = NULL;
	}

}

void insert_at_front(EdgeList* self, Edge data) {
	EdgeNodePtr new_node = malloc(sizeof * new_node);
	printf("\n Adding edge to %d \n", data.to_vertex);
	new_node->edge = data;
	new_node->next = self->head;
	self->head = new_node;
}
//6
void print_graph(Graph* self) {
	for (int i = 0; i < self->V; i++)
	{
		printf("City %d \n", i);
		EdgeNodePtr current = self->edges[i].head;
		//7
		while (current != NULL) {
			printf("\n connects to city %d with a ticket cost of %d \n", current->edge.to_vertex, current->edge.weight);
			current = current->next;
		}
		printf("\n");
	}
}
void in_deegree(Graph* G) {
	int* in_deegree = malloc(G->V);
	for (int i = 0; i < G->V; i++) {
		in_deegree[i] = 0;
	}
	for (int i = 0; i < G->V; i++) {
		in_deegree[G->V]++;
		printf("\n in-deegrees for City %d", i);
		EdgeNodePtr current = G->edges[i].head;
		while (current != NULL) {
			printf("\n current total connections %d", in_deegree[current->edge.to_vertex]);
			in_deegree[current->edge.to_vertex]++;
			printf("\n in-deegrees edge.to city %d with ticket cost %d", current->edge.to_vertex, current->edge.weight);
			current = current->next;
		}
	}
	for (int i = 0; i < G->V; i++) {
		printf(" City %d has %d in-deegrees \n ", i, in_deegree[i]);
	}
}

Graph prims_mst(Graph* self) {
	int* min_cost_to_v = malloc(self->V);
	int* vistied = malloc(self->V);
	int cost = 0;
	int Qtotal = 0;
	for (int i = 0; i < self->V; i++)
	{
		min_cost_to_v[i] = 100;
		vistied[i] = 666;
	}
	Graph F;
	scanf("%d", &F.V);
	init_graph(&F);
	int* Q = malloc(self->V);
	for (int i = 0; i < 1; i++)
	{
		//loop though edges starting with root node to get first city/cities visited 
		EdgeNodePtr current = self->edges[i].head;
		while (current != NULL) {
			if (vistied[i] == 666) {
				Q[i] = current->edge.to_vertex;
				Qtotal++;
				vistied[current->edge.to_vertex] = 1;
				printf("\n%d", Q[i]);
				printf("\n%d", Qtotal);

			}
			current = current->next;
		}
	}

	// Loop though cities visted to connect with unconnected city
	for (int i = 0; i < self->V; i++)
	{
		//loop though edges
		EdgeNodePtr current = self->edges[i].head;
		//if there are still edges check if they have been visted 
		while (current != NULL) {
			if (vistied[i] != 666) {
				//set the min cost to the weigh of the edge 
				min_cost_to_v[i] = current->edge.weight;
				//add the node to graph F
				Edge new_node;
				printf("\n At city %d \n", i);
				new_node.weight = min_cost_to_v[i];
				new_node.to_vertex = current->edge.to_vertex;
				//set node to visited 
				vistied[current->edge.to_vertex] = 1;
				insert_at_front(&F.edges[i], new_node);
				//calculate total cost of MST
				cost = cost + min_cost_to_v[i];
			}
			current = current->next;
		}
	}
	print_graph(&F);
	printf("\n total cost %d ", cost);
	return F;
}

//void destroy_graph(Graph* G) {
//
//	for (int v = 0; v < G->V; v++) {
//		EdgeNodePtr current = G->edges[v].head;
//
//		while (current != NULL) {
//			EdgeNodePtr to_free = current;
//			current = current->next;
//			free(to_free);
//		}
//	}
//
//	free(G->edges);
//}
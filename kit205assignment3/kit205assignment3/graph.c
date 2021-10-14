#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

/*
* Initialize Graph with empty edges
* @param Graph 
*/
void init_graph(Graph* self)
{
	self->edges = malloc(sizeof(EdgeList) * self->V);
	for (int i = 0; i < self->V; i++) {
		self->edges[i].head = NULL;
	}

}
/*
* Input edges data from input.txt for Graph
* @param Graph
*/
void add_edge(Graph* self) {
//Scan data from input.txt
	for (int i = 0; i < self->V; i++) {
		int temp;
		scanf("%d", &temp);

		for (int j = 0; j < temp; j++) {
//Creates new node and scans in to_vertex and weight from input.txt
			Edge new_node;
			scanf("%d,%d", &new_node.to_vertex, &new_node.weight);
			//printf("\n At city %d \n", i);
			//printf("\n first node link weight to %d \n", new_node.weight);
			//printf("\n first node link to_vertex to %d \n", new_node.to_vertex);
			int current_node = new_node.to_vertex;
			insert_at_front(&self->edges[i], new_node);
			int in_degree = malloc(sizeof(self->V));
//Create link between Cities because the graph is undirected so edges go both ways.
			int from_node = i;
			//printf("\n from node %d \n", from_node);
			Edge new_node_link;
			new_node_link.to_vertex = i;
			//printf("\n link node link to %d \n", i);
			new_node_link.weight = new_node.weight;
			//printf("\n link node link weight to %d", new_node_link.weight);
//insert data to head of list
			insert_at_front(&self->edges[current_node], new_node_link);
		}
	}
}
/*
* inserts node data to the head of the EdgeList
* @param EdgeList
* @param node
*/
void insert_at_front(EdgeList* self, Edge data) {
	EdgeNodePtr new_node = malloc(sizeof * new_node);
	//printf("\n Adding edge to %d \n", data.to_vertex);
	new_node->edge = data;
	new_node->next = self->head;
	self->head = new_node;
}
/*
* Print Graph showing the city then listing all edges and cost(weight)
* @param Graph
*/
void print_graph(Graph* self) {
	for (int i = 0; i < self->V; i++)
	{
		printf("City %d \n", i);
		EdgeNodePtr current = self->edges[i].head;

		while (current != NULL) {
			printf("\n connects to city %d with a ticket cost of %d \n", current->edge.to_vertex, current->edge.weight);
			current = current->next;
		}
		printf("\n");
	}
}
/*
* Calculates the "in degrees" for a graph. Loops through though graph adding 1 for every edge that points to a City
* @param Graph
*/
void in_degree(Graph* self) {
	int* in_degree = malloc(self->V);
	for (int i = 0; i < self->V; i++) {
		in_degree[i] = 0;
	}
	for (int i = 0; i < self->V; i++) {
		in_degree[self->V]++;
		//printf("\n in-degrees for City %d", i);
		EdgeNodePtr current = self->edges[i].head;
		while (current != NULL) {
			//printf("\n current total connections %d", in_degree[current->edge.to_vertex]);
			in_degree[current->edge.to_vertex]++;
			//printf("\n in-degrees edge.to city %d with ticket cost %d", current->edge.to_vertex, current->edge.weight);
			current = current->next;
		}
	}
	for (int i = 0; i < self->V; i++) {
		printf(" City %d has %d in-degrees \n ", i, in_degree[i]);
	}
}

/*
* Free all used by Graph
* @param Graph
*/
void destroy_graph(Graph* self) {
	for (int i = 0; i < self->V; i++) {
		EdgeNodePtr current = self->edges[i].head;

		while (current != NULL) {
			EdgeNodePtr to_free = current;
			current = current->next;
			free(to_free);
		}
	}

	free(self->edges);
}
/*
* returns a MST from Graph using prims algorithm 
* @param Graph
* @return newly-created Graph(F) to represent the MST
*/
Graph prims_mst(Graph* self) {
	int* min_cost_to_v = malloc(self->V);
	int* visited = malloc(self->V);
	int cost = 0;
//Inisitlises all min_cost and visted
	for (int i = 0; i < self->V; i++)
	{
		min_cost_to_v[i] = 100;
		visited[i] = 666;
	}
//Create new Graph "F" which will be the MST
	Graph F;
//Set the number of cities equal to the number of cities for param Graph
	F.V = self->V;
//Inistlise empty edges for graph
	init_graph(&F);
	int* Q = malloc(self->V);
//Set the root city to visted 
	visited[0] = 1;
//Loop though untill all cities have been checked for connections 
	for (int i = 0; i < self->V; i++)
	{
//Check each city to see if it has been visted
		for (int i = 0; i < self->V; i++)
		{
//Check to see if the city has been visited. If so check edges to see if a new connection can be made
			if (visited[i] == 1)
			{
				EdgeNodePtr current = self->edges[i].head;
				while (current != NULL) {
					if (visited[current->edge.to_vertex] == 666) {
//Set the min cost to the weigh of the edge 
						min_cost_to_v[i] = current->edge.weight;
//Add the node to graph F
						Edge new_node;
						//printf("\n At city %d \n", i);
						new_node.weight = current->edge.weight;
						new_node.to_vertex = current->edge.to_vertex;
//Set node to flag as visited 
						visited[current->edge.to_vertex] = 1;
						insert_at_front(&F.edges[i], new_node);
//Calculate total cost of MST
						cost = cost + min_cost_to_v[i];
					}
					current = current->next;
				}
			}
		}
	}
	print_graph(&F);
	printf("\n total cost %d ", cost);
	return F;
}

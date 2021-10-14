
/*
* Represents an edge in a graph
*/
typedef struct edge {
    int to_vertex;
    int weight;
} Edge;

/*
* Represents a linked list node containing a graph
*/
typedef struct edgeNode {
    Edge edge;
    struct edgeNode* next;
} *EdgeNodePtr;

/*
* Represents a linked list of edges 
*/
typedef struct edgeList {
    EdgeNodePtr head;
} EdgeList;

/*
* Represents an graph with vertices and edges
*/
typedef struct graph {
    int V;
    EdgeList* edges;
} Graph;

/*
* Initialize Graph with empty edges
* @param Graph
*/
void init_graph(Graph* self);

/*
* Input edges data from input.txt for Graph
* @param Graph
*/
void add_edge(Graph* self);

/*
* inserts node data to the head of the EdgeList
* @param EdgeList
* @param node
*/
void insert_at_front(EdgeList* self, Edge data);

/*
* Print Graph showing the city then listing all edges and cost(weight)
* @param Graph
*/
void print_graph(Graph* self);

/*
* Calculates the "in degrees" for a graph. Loops through though graph adding 1 for every edge that points to a City
* @param Graph
*/
void in_degree(Graph* self);

/*
* Free all used by Graph
* @param Graph
*/
void destroy_graph(Graph* G);

/*
* returns a MST from Graph using prims algorithm
* @param Graph
* @return newly-created Graph(F) to represent the MST
*/
Graph prims_mst(Graph* self);

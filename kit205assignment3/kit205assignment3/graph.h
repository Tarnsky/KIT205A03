typedef struct edge {
    int to_vertex;
    int weight;
} Edge;

typedef struct edgeNode {
    Edge edge;
    struct edgeNode* next;
} *EdgeNodePtr;

typedef struct edgeList {
    EdgeNodePtr head;
} EdgeList;

typedef struct graph {
    int V;
    EdgeList* edges;
} Graph;

void init_graph(Graph* self);
void insert_at_front(EdgeList* self, Edge data);
void print_graph(Graph* self);
void in_degree(Graph* self);
//void destroy_graph(Graph* G);
Graph prims_mst(Graph* self);

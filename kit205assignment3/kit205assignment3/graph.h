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

void init_graph(Graph* G);
void insert_at_front(EdgeList* self, Edge data);
void print_graph(Graph* G);
void in_deegree(Graph* G);
//void destroy_graph(Graph* G);
Graph prims_mst(Graph* self);

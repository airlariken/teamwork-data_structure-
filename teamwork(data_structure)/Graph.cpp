#include "Graph.h"
#include "hash.cpp"

void Graph::Initiate()
{
    Vertex_table = new Vertex[Vertex_num];
    edge_table = new Edge[Edge_num];
    
}

int Graph::vertexCount()
{
    return -1;
}

int Graph::edgeCount()
{
    return -1;
}

void Graph::addVertex(const int &x, const int &y)
{
    Vertex_table[Vertex_count].x = x;
    Vertex_table[Vertex_count].y = y;
     
}

void Graph::removeVertex(const int &n)
{
    
}
void addEdge(const int &n, const int &m)
{
    int pos = hash1(n, m);
    
    
}

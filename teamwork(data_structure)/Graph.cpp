
#include "Graph.h"
void Graph::Initiate()
{
    Vertex_table = new Vertex[Vertex_num];
    edge_table = new Edge*[Edge_num]();
    
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
    Vertex_count++;
}

void Graph::removeVertex(const int &n)
{
    Vertex_count--;
    return;//remove 干啥
}

int hash1(int n, int v);//声明hash.cpp里的函数
void Graph::addEdge(const int &n, const int &m)
{
    Edge *n_edge1 = new Edge(n,m);
    Edge *n_edge2 = new Edge(m,n);
    
    //插入邻接表 两条相同的边分别插入两个顶点
    Edge *temp = Vertex_table[n].link->next;//头插法
    Vertex_table[n].link->next = n_edge1;
    n_edge1->next = temp;
    n_edge1->pre = Vertex_table[n].link;
    if(temp != nullptr)
        temp->pre = n_edge1;
    
    temp = Vertex_table[m].link->next;
    Vertex_table[m].link->next = n_edge2;
    n_edge2->next = temp;
    n_edge2->pre = Vertex_table[m].link;
    if(temp != nullptr)
        temp->pre = n_edge2;
    
    n_edge1->partner = n_edge2;     n_edge2->partner = n_edge1;//伙伴指针
    //插入hash表
    int pos = hash1(n, m);
    
    if(edge_table[pos] == nullptr || edge_table[pos]->my_vertex == -1)//空的
        edge_table[pos] = n_edge1;
    else
        //hash2而且到另一个表
        
        
        
        return;
    Edge_count++;
}
void Graph::removeEdge(const int &n, const int &m)//没写完
{
    int pos = hash1(n, m);
    if(edge_table[pos]->my_vertex == n)
        //remove
        ;
        
        
    Edge_count--;
    return;
}

int Graph::weight(const int &n, const int &m)//没写完
{
    int pos = hash1(n, m);
    if(edge_table[pos]->my_vertex == n)
        return edge_table[pos]->weight;
    else
        //hash2
        
        return -1;
}


void Graph::printf()
{
    for (int i = 0 ; i < Vertex_count; ++i) {
        Edge *cur = Vertex_table[i].link->next;
        while (cur != NULL) {
            cout<<cur->my_vertex<<"<->"<<cur->next_vertex<<'\t';
            cur = cur->next;
        }
        cout<<endl;
    }
    

}

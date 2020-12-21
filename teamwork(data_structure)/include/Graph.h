
//
//  hashtable.h
//  teamwork_graph
//
//  Created by 陈梓玮 on 2020/12/10.
//

#ifndef Graph_h
#define Graph_h
#include "Header.h"

#define Vertex_num 88000
#define Edge_num 13000
struct Vertex
{
    int x = -1;//有用吗？和数组下标一致算了
    int y = -1;
    Vertex *link = nullptr;
    Vertex(const int &a,const int &b):x(a),y(b){}
    Vertex() = default;
    
};

struct Edge {
    int my_vertex = -1;
    int next_vertex = -1;
    Edge *next = nullptr;
    Edge *pre = nullptr;
    Edge *partner = nullptr;
};

class Graph {
//private:
public:
    Vertex *Vertex_table = nullptr;
    Edge *edge_table = nullptr;
    int Vertex_count = 0;
    int Edge_count = 0;
    
    
public:
    void Initiate();//初始化
    int vertexCount();
    int edgeCount();
    void addVertex(const int &x, const int &y);//下标一一对应顶点
    void removeVertex(const int &n);
    void addEdge(const int &n, const int &m);
    
};


#endif

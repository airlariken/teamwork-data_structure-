
//
//  hashtable.h
//  teamwork_graph
//
//  Created by 陈梓玮 on 2020/12/10.
//

#ifndef Graph_h
#define Graph_h
#include "Header.h"

#define Vertex_num 87575
#define Edge_num 121961
#define hash_table_num 999553
#define hash_table2_num 999553
struct Edge {
    int my_vertex = -1;
    int next_vertex = -1;
    int weight = -1;
    Edge *next = nullptr;
    Edge *pre = nullptr;
    Edge *partner = nullptr;
    Edge() = default;
    Edge(const int& x1, const int& x2):my_vertex(x1),next_vertex(x2){weight = pow(x1*x1+x2*x2,0.5);
    }
};

struct Vertex
{
    int x = -1;//有用吗？和数组下标一致算了
    int y = -1;
    Edge *link = nullptr;
    Vertex(const int &a,const int &b):x(a),y(b){}
    Vertex(){link = new Edge(0,0);};
    
};



class Graph {
//private:
public:
    //hashtable
    Vertex *Vertex_table = nullptr;
    Edge **edge_table = nullptr;
    Edge **edge_table2 = nullptr;
    //按文件读取顺序存边的指针
    Edge **m_edge = nullptr;
    int Vertex_count = 0;
    int Edge_count = 0;
    
    int dsu_pre[Edge_num];
public:
    Graph(){Initiate();m_edge = new Edge*[Edge_num];}
    ~Graph(){delete []edge_table;   delete []Vertex_table; delete [] m_edge;}
    void Initiate();//初始化
    int vertexCount();
    int edgeCount();
    void addVertex(const int &x, const int &y);//下标一一对应顶点
    void removeVertex(const int &n);
    void addEdge(const int &n, const int &m);
    bool isVertex(const int n){     //输入x,y坐标，得出是否在该图中
        if (Vertex_table[n].x == -1)
            return false;
        return true;
    }
    void removeEdge(const int &n, const int &m);
//    bool isEdge(const int &n, const int &m)
    int weight(const int &n, const int &m);
    
    
    //算法部分
    void Kruskal();
    void Dijkstra();
    int DSU_Find(const int &x);
    void DSU_Join(const int &x,const int &y);
    
    void readFile();
    
    
    //调试区域
    void printf();
    bool hashCollision[hash_table_num];
    int hashCollision2[hash_table2_num];
    

};


#endif

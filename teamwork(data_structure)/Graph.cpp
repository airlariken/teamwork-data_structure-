
#include "Graph.h"
void Graph::Initiate()
{
    Vertex_table = new Vertex[Vertex_num];
    edge_table = new Edge*[Edge_num]();
    for (int i = 0; i < hash_table_num; ++i)
        hashCollision[i] = 0;
    
    for (int i = 0; i < hash_table2_num; ++i) {
        hashCollision2[i] = 0;
    }

    for (int i = 0; i < Edge_num; ++i)
        dsu_pre[i] = -1;
    
    
}


//并查集部分
int Graph::DSU_Find(const int &x)
{
    
    int cur = x;
    while (dsu_pre[cur] != -1) {
        cur = dsu_pre[cur];     //一直追溯到根节点
    }
    
    int root = cur, temp;
    cur = x;//cur回到x处
    while (cur != root) {
        temp = dsu_pre[cur];        //暂存cur的上级
        dsu_pre[cur] = root;        //直接将cur放到根节点下级
        cur = temp;             //向上查找
    }
    return root;
}

void Graph::DSU_Join(const int &x, const int &y)
{
    int fx = DSU_Find(x);
    int fy = DSU_Find(y);
    if (fx == fy&& fx != -1)
        return;
    else if (fy == -1&& fx == -1)
        dsu_pre[x] = y;
    else if (fy == -1)
        dsu_pre[fx] = fy;
    else if (fx == -1)
        dsu_pre[x] = fy;
    else
        dsu_pre[fx] = fy;
    return;
}


//算法部分
bool comp1(Edge* obj1, Edge* obj2)
{
    return (obj1->weight>obj2->weight);
}
void Graph::Kruskal()
{
//    m_edge//需要排序O(elge)
    sort(m_edge, m_edge+Edge_num, comp1);
    cout<<"sort succeess!"<<endl;
    
}
void Graph::Dijkstra()
{
    
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
    //插入m_edge数组中，便于kruskal算法排序
    m_edge[Edge_count] = n_edge1;
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
    int pos = hash1(n, m);//第一个hash
    if(hashCollision[pos]==false)   hashCollision[pos]=true;
    
    else {               //第二个hash
        int x1 = n%397;
        int x2 = m%293;
        pos %= 197;
        pos = abs(x1*x1+x2*x2-n-m+(long long int)pos*x1*x2)%hash_table2_num;
        hashCollision2[pos]++;
        long long int a;
        if (pos<0)
            a =(n+m+(x1+x2)*(x1-x2));
        cout<<' ';
    }


//    if(edge_table[pos] == nullptr || edge_table[pos]->my_vertex == -1)//空的
//        edge_table[pos] = n_edge1;
//    else
//        //hash2而且到另一个表
//        return;
    
    
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

void Graph::readFile()
{
    ifstream fin("usa.txt");
    if(!fin.is_open())
        exit(1);
    string s;
    getline(fin,s);
    int a,b;
    for (int i = 0; i < 87575; ++i) {
        fin>>a;//把序号扔掉
        fin>>a>>b;
        addVertex(a, b);
    }
//查边
    for (int i = 0; i < 121961; ++i) {
        fin>>a>>b;
        addEdge(a, b);
    }
}

void Graph::printf()
{
//    for (int i = 0 ; i < Vertex_count; ++i) {
//        Edge *cur = Vertex_table[i].link->next;
//        while (cur != NULL) {
//            cout<<cur->my_vertex<<"<->"<<cur->next_vertex<<'\t';
//            cur = cur->next;
//        }
//        cout<<endl;
//    }
    ofstream fout("hash result.txt",ios::trunc);
    for (int i = 0 ; i <hash_table2_num; ++i) {
        fout<<hashCollision2[i]<<endl;
    }
  

}

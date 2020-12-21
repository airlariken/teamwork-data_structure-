//
//  main.cpp
//  teamwork(data_structure)
//
//  Created by 陈梓玮 on 2020/12/21.
//

#include <iostream>
#include "Graph.h"

int main(int argc, const char * argv[]) {

    Graph m_graph;
    m_graph.addVertex(100, 100);
    m_graph.addVertex(200, 200);
    m_graph.addVertex(300, 300);
    m_graph.addVertex(400, 400);
    m_graph.addVertex(500, 500);
    m_graph.addVertex(600, 600);
    m_graph.addEdge(0, 1);
    m_graph.addEdge(0, 3);
    m_graph.addEdge(1, 2);
    m_graph.addEdge(1, 3);
    m_graph.addEdge(2, 4);
    m_graph.addEdge(3, 4);

    
//    m_graph.printf();
    return 0;
}

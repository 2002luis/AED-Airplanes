//
// Created by luism on 25/12/2022.
//

#ifndef AED_AIRPLANE_GRAPH_H
#define AED_AIRPLANE_GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

class Graph {
private:
    struct Edge {
        std::string dest;   // Destination node
        int weight; // An integer weight
    };

    struct Node {
        std::list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir = true;        // false: undirected; true: directed
    std::vector<Node> nodes; // The list of nodes being represented

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);


};


#endif //AED_AIRPLANE_GRAPH_H

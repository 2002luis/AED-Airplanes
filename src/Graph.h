//
// Created by luism on 25/12/2022.
//

#ifndef AED_AIRPLANE_GRAPH_H
#define AED_AIRPLANE_GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include "Airport.h"

class Graph {
private:
    struct Edge {
        std::string dest;   // Destination node
        std::string company;
        int weight; // An integer weight
    };

    struct Node {
        std::list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // Has the node been visited on a search?
    };

    int n = 0;              // Graph size
    bool hasDir = true;        // false: undirected; true: directed
    std::unordered_map<std::string,Node> nodes; // The list of nodes being represented

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph();
    int addAirport(Airport a);
    bool addFlight(std::string source, std::string dest, std::string company);

};


#endif //AED_AIRPLANE_GRAPH_H

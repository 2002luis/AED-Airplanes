//
// Created by tomas on 30/12/2022.
//

#ifndef AED_AIRPLANE_GRAPHC_H
#define AED_AIRPLANE_GRAPHC_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include "Airport.h"

class GraphC {
private:
    struct Edge {
        std::string sourcecity;//apagar
        std::string cityname; // para onde vai
        std::string destairport;// Destination node
        std::string originairport;
        std::string company;
        double weight; // An integer weight
    };

    struct Node {
        std::vector<std::string> airports;
        std::list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // Has the node been visited on a search?
    };

    int n = 0;              // Graph size
    bool hasDir = true;        // false: undirected; true: directed
    std::unordered_map<std::string,Node> nodes; // The list of nodes being represented

public:
    // Constructor: nr nodes and direction (default: undirected)
    GraphC();
    int addCity(Airport a);
    bool addFlight(std::string destinationcity,std::string source, std::string sourcecity,std::string dest, std::string company, double weight);
    void removeVisited();
    std::unordered_map<std::string,Node> getNodes(){
        return this->nodes;
    }
    std::list<std::string> bfs(std::string in, std::string out);
    std::pair<std::list<std::string>,double> djikstra(std::string in, std::string out);
};



class mycomparison
{
    bool reverse;
public:
    mycomparison(const bool& revparam=false)
    {reverse=revparam;}
    bool operator() (std::pair<std::list<std::string>,double> p1, std::pair<std::list<std::string>,double> p2) const
    {
        if (!reverse) return (p1.second>p2.second);
        else return (p1.second<p2.second);
    }
};

#endif //AED_AIRPLANE_GRAPHC_H
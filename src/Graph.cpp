//
// Created by luism on 25/12/2022.
//

#include "Graph.h"
#include <iostream>

Graph::Graph(){
    this->n=0;
    this->hasDir=true;
}

int Graph::addAirport(Airport a) {
    if(this->nodes.find(a.getCode())==this->nodes.end()) this->nodes.insert(std::pair<std::string,Node>(a.getCode(),{}));
    return this->nodes.size();
}

bool Graph::addFlight(std::string source, std::string dest, std::string company) {
    if(this->nodes.find(source) == this->nodes.end() || this->nodes.find(dest) == this->nodes.end()) return false;

    Edge e;
    e.dest = dest;
    e.company = company;
    e.weight = 1;

    this->nodes.find(source)->second.adj.push_back(e);
    return true;
}
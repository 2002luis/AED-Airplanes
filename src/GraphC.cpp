//
// Created by tomas on 30/12/2022.
//

#include "GraphC.h"
#include <iostream>
#include <queue>

GraphC::GraphC(){
    this->n=0;
    this->hasDir=true;
}

int GraphC::addCity(Airport a) {
    if(this->nodes.find(a.getCity())==this->nodes.end()) this->nodes.insert(std::pair<std::string,Node>(a.getCity(),{}));
    this->nodes.find(a.getCity())->second.airports.push_back(a.getName());
    return this->nodes.size();
}


bool GraphC::addFlight(std::string destinationcity,std::string source, std::string sourcecity,std::string dest, std::string company, double weight) {
    if(this->nodes.find(sourcecity) == this->nodes.end() || this->nodes.find(destinationcity) == this->nodes.end()) return false;

    Edge e;
    e.sourcecity = sourcecity;
    e.cityname =destinationcity;
    e.destairport = dest;
    e.originairport = source;
    e.company = company;
    e.weight = weight;

    this->nodes.find(source)->second.adj.push_back(e);
    this->n++;
    return true;
}

void GraphC::removeVisited() {
    for(auto &i : this->nodes){
        i.second.visited = false;
    }
}

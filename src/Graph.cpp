//
// Created by luism on 25/12/2022.
//

#include "Graph.h"
#include <iostream>
#include <queue>

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
    this->n++;
    return true;
}

std::list<std::string> Graph::bfs(std::string in, std::string out){
    std::list<std::string> ans;

    if(in == out){
        ans.push_back(out);
        return ans;
    }

    std::list<std::string> temp;

    this->nodes.find(in)->second.visited=true;

    std::queue<std::string> toSearch;

    for(auto i : this->nodes.find(in)->second.adj){
        if(!this->nodes.find(i.dest)->second.visited){
            toSearch.push(i.dest);
        }
    }

    while(!toSearch.empty()){
        temp = this->bfs(toSearch.front(),out);
        if(ans.empty() || ans.size()>temp.size()) ans = temp;
        toSearch.pop();
    }

    ans.push_front(in);

    return ans;
}
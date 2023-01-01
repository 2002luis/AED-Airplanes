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
    return this->addFlight(source,dest,company,1);
}

bool Graph::addFlight(std::string source, std::string dest, std::string company, double weight) {
    if(this->nodes.find(source) == this->nodes.end() || this->nodes.find(dest) == this->nodes.end()) return false;

    Edge e;
    e.dest = dest;
    e.company = company;
    e.weight = weight;

    this->nodes.find(source)->second.adj.push_back(e);
    this->n++;
    return true;
}

void Graph::removeVisited() {
    for(auto &i : this->nodes){
        i.second.visited = false;
    }
}

std::list<std::string> Graph::bfs(std::string in, std::string out){

    this->removeVisited();

    std::list<std::string> ans;

    this->nodes.find(in)->second.visited=true;
    if(in == out){
        ans.push_back(out);
        return ans;
    }

    std::queue<std::list<std::string>> toSearch;
    for(auto i : this->nodes.find(in)->second.adj){
        toSearch.push({in,i.dest});
        if (i.dest == out) return toSearch.back();

    }

    while(!toSearch.empty()){
        std::string cur = toSearch.front().back();
        this->nodes.find(cur)->second.visited = true;
        if(cur == out) return toSearch.front();

        for(auto i : this->nodes.find(cur)->second.adj) {
            if (!this->nodes.find(i.dest)->second.visited) {
                std::list<std::string> temp = toSearch.front();
                temp.push_back(i.dest);
                toSearch.push(temp);
            }
        }
        toSearch.pop();
    }


    std::list<std::string> empty;
    return empty;
}

std::pair<std::list<std::string>,double> Graph::djikstra(std::string in, std::string out){

    this->removeVisited();
    std::pair<std::list<std::string>,double> ans = {{},0};

    this->nodes.find(in)->second.visited=true;
    if(in == out){
        ans.first.push_back(out);
        return ans;
    }

    std::priority_queue<std::pair<std::list<std::string>,double>, std::vector<std::pair<std::list<std::string>,double>>,mycomparison> toSearch;
    for(auto i : this->nodes.find(in)->second.adj){
        std::list<std::string> lst;
        std::pair<std::list<std::string>,double> tmp({in,i.dest},i.weight);
        toSearch.push(tmp);
    }

    while(!toSearch.empty()){
        std::string cur = toSearch.top().first.back();
        this->nodes.find(cur)->second.visited=true;
        if(cur == out) return toSearch.top();

        for(auto i : this->nodes.find(cur)->second.adj) {
            if (!this->nodes.find(i.dest)->second.visited) {
                std::list<std::string> temp = toSearch.top().first;
                temp.push_back(i.dest);
                //if (i.dest == out) return {temp,toSearch.top().second+i.weight};
                toSearch.push({temp,toSearch.top().second+i.weight});
            }
        }
        toSearch.pop();
    }


    std::list<std::string> empty;
    return {empty,0};
}
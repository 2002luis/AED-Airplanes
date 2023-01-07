#include "GraphC.h"
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include "triple.h"

GraphC::GraphC(){
    this->n=0;
    this->hasDir=true;
}

int GraphC::addAirport(Airport a) {
    if(this->nodes.find(a.getCity())==this->nodes.end()){
        this->nodes.insert({a.getCity(),{}});
        this->n++;
    }
    this->nodes.find(a.getCity())->second.airports.push_back(a.getCode());
    return this->n;
}

bool GraphC::addFlight(std::string source, std::string sourcecity, std::string dest, std::string destcity, std::string company) {
    return this->addFlight(source,sourcecity,dest,destcity,company,1);
}

bool GraphC::addFlight(std::string source, std::string sourcecity, std::string dest, std::string destcity, std::string company, double weight) {
    if(this->nodes.find(sourcecity) == this->nodes.end() || this->nodes.find(destcity) == this->nodes.end()) return false;

    Edge e;
    e.originAirport = source;
    e.destAirport = dest;
    e.dest = destcity;
    e.company = company;
    e.weight = weight;

    this->nodes.find(sourcecity)->second.adj.push_back(e);
    return true;
}

void GraphC::removeVisited() {
    for(auto &i : this->nodes){
        i.second.visited = false;
    }
}

std::list<std::string> GraphC::bfs(std::string in, std::string out){

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
        if(cur == out)
        {
            /*
            std::vector<std::string> temp2;
            for(auto i : toSearch.front()){
                if(std::find(temp2.begin(),temp2.end(),i)==temp2.end()) temp2.push_back(i);
            }
            std::list<std::string> end;
            for(auto i : temp2){
                end.push_back(i);
            }
            return end;
             */
            return toSearch.front();
        }
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

std::pair<std::list<std::string>,double> GraphC::djikstra(std::string in, std::string out){

    this->removeVisited();
    std::pair<std::list<std::string>,double> ans = {{},0};

    this->nodes.find(in)->second.visited=true;
    if(in == out){
        ans.first.push_back(out);
        return ans;
    }

    std::priority_queue<std::pair<std::list<std::string>,double>, std::vector<std::pair<std::list<std::string>,double>>,mycomparison2> toSearch;
    for(auto i : this->nodes.find(in)->second.adj){
        std::list<std::string> lst;
        std::pair<std::list<std::string>,double> tmp({in,i.dest},i.weight);
        toSearch.push(tmp);
    }

    while(!toSearch.empty()){
        auto cur = toSearch.top();
        this->nodes.find(cur.first.back())->second.visited=true;
        if(cur.first.back() == out) return toSearch.top();
        toSearch.pop();

        for(auto i : this->nodes.find(cur.first.back())->second.adj) {
            if (!this->nodes.find(i.dest)->second.visited) {
                std::list<std::string> temp = cur.first;
                temp.push_back(i.dest);
                toSearch.push({temp,cur.second+i.weight});
            }
        }
    }


    std::list<std::string> empty;
    return {empty,0};
}

std::list<triple<std::string,std::string,std::string>> GraphC::citiesToAirports(std::list<std::string> in){
    std::list<triple<std::string,std::string,std::string>> out;
    std::string last = in.front();
    in.pop_front();
    for(auto i : in){
        triple<std::string,std::string,std::string> airports = this->findEdge(last,i);
        out.push_back(airports);
        last = i;
        //out.push_back()
    }
    return out;
}

triple<std::string,std::string,std::string> GraphC::findEdge(std::string in, std::string out) {
    for(auto i : this->nodes.find(in)->second.adj){
        if(i.dest == out){
            return {i.originAirport,i.destAirport,i.company};
        }
    }
    return {"","",""};
}
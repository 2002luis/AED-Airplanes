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

std::list<std::string> GraphC::bfs(std::string in, std::string out, std::unordered_set<std::string> comp){

    this->removeVisited();

    std::list<std::string> ans;

    this->nodes.find(in)->second.visited=true;
    if(in == out){
        ans.push_back(out);
        return ans;
    }

    std::queue<std::list<std::string>> toSearch;
    for(auto i : this->nodes.find(in)->second.adj){
        if(comp.find(i.company)!=comp.end()) {
            toSearch.push({in, i.dest});
            if (i.dest == out) return toSearch.back();
        }
    }

    while(!toSearch.empty()){
        std::string cur = toSearch.front().back();
        this->nodes.find(cur)->second.visited = true;
        if(cur == out)
        {
            return toSearch.front();
        }
        for(auto i : this->nodes.find(cur)->second.adj) {
            if (!this->nodes.find(i.dest)->second.visited && comp.find(i.company)!=comp.end()) {
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

std::pair<std::list<std::string>,double> GraphC::djikstra(std::string in, std::string out, std::unordered_set<std::string> comp){
    this->removeVisited();
    std::pair<std::list<std::string>,double> ans = {{},0};

    this->nodes.find(in)->second.visited=true;
    if(in == out){
        ans.first.push_back(out);
        return ans;
    }

    std::priority_queue<std::pair<std::list<std::string>,double>, std::vector<std::pair<std::list<std::string>,double>>,mycomparison2> toSearch;
    for(auto i : this->nodes.find(in)->second.adj){
        if(comp.find(i.company)!=comp.end()) {
            std::list<std::string> lst;
            std::pair<std::list<std::string>, double> tmp({in, i.dest}, i.weight);
            toSearch.push(tmp);
        }
    }

    while(!toSearch.empty()){
        auto cur = toSearch.top();
        this->nodes.find(cur.first.back())->second.visited=true;
        if(cur.first.back() == out) return toSearch.top();
        toSearch.pop();

        for(auto i : this->nodes.find(cur.first.back())->second.adj) {
            if (!this->nodes.find(i.dest)->second.visited && comp.find(i.company)!=comp.end()) {
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

std::list<triple<std::string,std::string,std::string>> GraphC::citiesToAirports(std::list<std::string> in, std::unordered_set<std::string> comp){
    std::list<triple<std::string,std::string,std::string>> out;
    std::string last = in.front();
    in.pop_front();
    for(auto i : in){
        triple<std::string,std::string,std::string> airports = this->findEdge(last,i,comp);
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

triple<std::string,std::string,std::string> GraphC::findEdge(std::string in, std::string out, std::unordered_set<std::string> comp){
    for(auto i : this->nodes.find(in)->second.adj){
        if(i.dest == out && comp.find(i.company)!=comp.end()){
            return {i.originAirport,i.destAirport,i.company};
        }
    }
    return {"","",""};
}

template <class T>
bool inList(std::list<std::pair<std::string,T>> l1, std::string s){
    for(auto i : l1){
        if(i.first==s) return true;
    }
    return false;
}

std::list<std::pair<std::string,int>> GraphC::airportsBfs(std::string in, int limit){
    this->removeVisited();

    std::list<std::pair<std::string,int>> ans;

    this->nodes.find(in)->second.visited=true;
    ans.push_back({in,0});

    std::queue<std::list<std::string>> toSearch;
    for(auto i : this->nodes.find(in)->second.adj){
        toSearch.push({in,i.dest});
    }

    while(!toSearch.empty() && toSearch.front().size()<=(limit+1)){
        std::string cur = toSearch.front().back();
        if(!this->nodes.find(cur)->second.visited && !inList(ans,cur)) ans.push_back({cur,toSearch.front().size()-1});
        this->nodes.find(cur)->second.visited = true;
        for(auto i : this->nodes.find(cur)->second.adj) {
            if (!this->nodes.find(i.dest)->second.visited) {
                std::list<std::string> temp = toSearch.front();
                temp.push_back(i.dest);
                toSearch.push(temp);
            }
        }
        toSearch.pop();
    }


    return ans;
}

std::list<std::pair<std::string,int>> GraphC::airportsBfs(std::string in, int limit, std::unordered_set<std::string> comp){
    this->removeVisited();

    std::list<std::pair<std::string,int>> ans;

    this->nodes.find(in)->second.visited=true;
    ans.push_back({in,0});

    std::queue<std::list<std::string>> toSearch;
    for(auto i : this->nodes.find(in)->second.adj){
        if(comp.find(i.company)!=comp.end()) toSearch.push({in,i.dest});
    }

    while(!toSearch.empty() && toSearch.front().size()<=(limit+1)){
        std::string cur = toSearch.front().back();
        if(!this->nodes.find(cur)->second.visited && !inList(ans,cur)) ans.push_back({cur,toSearch.front().size()-1});
        this->nodes.find(cur)->second.visited = true;
        for(auto i : this->nodes.find(cur)->second.adj) {
            if (!this->nodes.find(i.dest)->second.visited && comp.find(i.company)!=comp.end()) {
                std::list<std::string> temp = toSearch.front();
                temp.push_back(i.dest);
                toSearch.push(temp);
            }
        }
        toSearch.pop();
    }


    return ans;
}

std::list<std::pair<std::string,double>> GraphC::airportsDijkstra(std::string in, double limit){
    this->removeVisited();
    std::list<std::pair<std::string,double>> ans;

    this->nodes.find(in)->second.visited=true;
    ans.push_back({in,0});

    std::priority_queue<std::pair<std::list<std::string>,double>, std::vector<std::pair<std::list<std::string>,double>>,mycomparison2> toSearch;
    for(auto i : this->nodes.find(in)->second.adj){
        std::list<std::string> lst;
        std::pair<std::list<std::string>,double> tmp({in,i.dest},i.weight);
        toSearch.push(tmp);
    }

    while(!toSearch.empty() && toSearch.top().second<=limit){
        auto cur = toSearch.top();
        if(this->nodes.find(cur.first.back())->second.visited && !inList(ans,cur.first.back())) ans.push_back({cur.first.back(),cur.second});
        this->nodes.find(cur.first.back())->second.visited=true;
        toSearch.pop();

        for(auto i : this->nodes.find(cur.first.back())->second.adj) {
            if (!this->nodes.find(i.dest)->second.visited) {
                std::list<std::string> temp = cur.first;
                temp.push_back(i.dest);
                toSearch.push({temp,cur.second+i.weight});
            }
        }
    }

    return ans;
}

std::list<std::pair<std::string,double>> GraphC::airportsDijkstra(std::string in, double limit, std::unordered_set<std::string> comp){
    this->removeVisited();
    std::list<std::pair<std::string,double>> ans;

    this->nodes.find(in)->second.visited=true;
    ans.push_back({in,0});

    std::priority_queue<std::pair<std::list<std::string>,double>, std::vector<std::pair<std::list<std::string>,double>>,mycomparison2> toSearch;
    for(auto i : this->nodes.find(in)->second.adj){
        if(comp.find(i.company)!=comp.end()) {
            std::list<std::string> lst;
            std::pair<std::list<std::string>, double> tmp({in, i.dest}, i.weight);
            toSearch.push(tmp);
        }
    }

    while(!toSearch.empty() && toSearch.top().second<=limit){
        auto cur = toSearch.top();
        if(this->nodes.find(cur.first.back())->second.visited && !inList(ans,cur.first.back())) ans.push_back({cur.first.back(),cur.second});
        this->nodes.find(cur.first.back())->second.visited=true;
        toSearch.pop();

        for(auto i : this->nodes.find(cur.first.back())->second.adj) {
            if (!this->nodes.find(i.dest)->second.visited && comp.find(i.company)!=comp.end()) {
                std::list<std::string> temp = cur.first;
                temp.push_back(i.dest);
                toSearch.push({temp,cur.second+i.weight});
            }
        }
    }

    return ans;
}
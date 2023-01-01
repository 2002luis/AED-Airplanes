//
// Created by luism on 25/12/2022.
//

#ifndef AED_AIRPLANE_OVERLOADS_H
#define AED_AIRPLANE_OVERLOADS_H

#include <iostream>
#include "Airport.h"
#include "Airlines.h"
#include "Graph.h"
#include "GraphC.h"

std::ostream& operator<<(std::ostream& os, Airport a);
std::ostream& operator<<(std::ostream& os, Airlines a);
std::ostream& operator<<(std::ostream& os, Graph a);
std::ostream& operator<<(std::ostream& os, GraphC a);

template<class T>
std::ostream& operator<<(std::ostream& os, std::list<T> a){
    os << std::endl;
    for(auto i: a){
        os << i << ' ';
    }
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os, std::list<std::pair<T,T>> a){
    os << std::endl;
    for(auto i: a){
        if(i.first!="" && i.second!="") os << i.first << "->" << i.second << " ";
    }
    return os;
}

#endif //AED_AIRPLANE_OVERLOADS_H

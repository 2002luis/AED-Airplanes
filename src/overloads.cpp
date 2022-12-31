//
// Created by luism on 25/12/2022.
//

#ifndef AED_AIRPLANE_OVERLOADS_CPP
#define AED_AIRPLANE_OVERLOADS_CPP

#include <iostream>
#include <string.h>
#include "Airport.h"
#include "Airlines.h"
#include "Graph.h"

std::ostream& operator<<(std::ostream& os, Airport a){
    os << std::endl;
    os << a.getCode() << ' ' << a.getName() << ' ' << a.getCountry() << ' ' << a.getCity() << ' ' << a.getLatitude() << "Lat " << a.getLongitude() << "Lon";
    return os;
}

std::ostream& operator<<(std::ostream& os, Airlines a){
    os << std::endl;
    os << a.getCode() << ' ' << a.getName() << ' ' << a.getCallsign() << ' ' << a.getCountry();
    return os;
}

std::ostream& operator<<(std::ostream& os, Graph a){
    os << std::endl;
    for(auto i: a.getNodes()){
        os << i.first << " liga a: ";
        for(auto j: i.second.adj){
            os << j.dest << " (" << j.company << ' ' << j.weight << ") \t";
        }
        os << std::endl << std::endl;
    }
    return os;
}

/*template <class T>
std::ostream& operator<<(std::ostream& os, std::list<T> a){
    os << std::endl;
    for(auto i: a){
        os << i << ' ';
    }
    return os;
}*/

#endif
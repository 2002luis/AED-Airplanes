//
// Created by luism on 25/12/2022.
//

#include <iostream>
#include <string.h>
#include "Airport.h"
#include "Airlines.h"
#include "Graph.h"

std::ostream& operator<<(std::ostream& os, Airport a){
    os << std::endl;
    os << a.getCode() << ' ' << a.getName() << ' ' << a.getCountry() << ' ' << a.getLatitude() << "Lat " << a.getLongitude() << "Lon";
}

std::ostream& operator<<(std::ostream& os, Airlines a){
    os << std::endl;
    os << a.getCode() << ' ' << a.getName() << ' ' << a.getCallsign() << ' ' << a.getCountry();
}
//
// Created by luism on 25/12/2022.
//

#ifndef AED_AIRPLANE_DATA_H
#define AED_AIRPLANE_DATA_H

#include <iostream>
#include <string.h>
#include <unordered_map>
#include "Airport.h"
#include "Airlines.h"

class Data {
private:
    std::unordered_map<std::string,Airport> airports;
    std::unordered_map<std::string,Airlines> airlines;
    int readAirports();
    int readAirlines();
    int buildFlights();
    Data();
public:
    Airport getAirport(std::string);
    Airlines getAirline(std::string);
};


#endif //AED_AIRPLANE_DATA_H

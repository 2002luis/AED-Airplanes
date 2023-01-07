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
#include "Graph.h"
#include "GraphC.h"

class Data {

private:
    Graph graph;
    GraphC graphC;
    std::unordered_map<std::string,Airport> airports;
    std::unordered_map<std::string,Airlines> airlines;
    std::unordered_map<std::string,std::string> cities; //GIVE AIRPORT GET CITY
    std::unordered_map<std::string,std::list<std::string>> countries; // GIVE COUNTRY GET AIRPORTS
    std::unordered_map<std::string,std::string> citiesInCountries; //GIVE CITY GET COUNTRY
    std::unordered_set<std::string> cityList;
    int readAirports();
    int readAirlines();
    int buildFlights();
    std::string removeComma(std::string in);
    double haversine(std::string source, std::string destination);
public:
    Data();
    Airport getAirport(std::string in);
    Airlines getAirline(std::string in);
    std::string getAirportFromCity(std::string in);
    std::list<std::string> getAirportsInCountry(std::string in);
    std::string getCountry(std::string in);

    Graph getGraph();
    GraphC getCityGraph();
};


#endif //AED_AIRPLANE_DATA_H

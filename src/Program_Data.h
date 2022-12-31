//
// Created by tomas on 26/12/2022.
//

#ifndef AED_AIRPLANE_PROGRAM_DATA_H
#define AED_AIRPLANE_PROGRAM_DATA_H
#include <unordered_map>
#include <unordered_set>
#include <wsman.h>
#include "Airlines.h"
#include "Airport.h"
#include "Graph.h"
#include "GraphC.h"

class Program_Data {

private:
    Graph graph;
    GraphC graphC;

    std::unordered_map<std::string ,Airlines*> airlines;
    std::unordered_map<std::string,Airport*> airports;
    std::unordered_map<std::string,std::list<Airport>> cities; // lista com os aeorportos
    std::unordered_map<std::string ,std::string> airportscities;
public:

    Program_Data();

    void addAirport(Airport airport);

    void addFlight(std::string source, std::string dest, std::string company);

    void addCity(std::string City);

    void addAirlines(Airlines airlines);

    void addFlight(std::string source, std::string dest, std::string company,double weight);

    void addFlight(std::string destinationcity,std::string source, std::string sourcecity,std::string dest, std::string company, double weight);

    double haversine(std::string source, std::string destination);




};


#endif //AED_AIRPLANE_PROGRAM_DATA_H

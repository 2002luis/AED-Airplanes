//
// Created by tomas on 26/12/2022.
//

#include "Program_Data.h"
#include "Graph.h"
#include <math.h>



 Program_Data:: Program_Data() {

    this->graph = Graph();
    this->graphC = GraphC();

}

void Program_Data::addAirport(Airport a) {

    graph.addAirport(a);
    graphC.addCity(a);




    std::pair<std::string,Airport*> b = {a.getName(),&a};
    std::pair<std::string ,std::string> d = {a.getName(),a.getCity()};

    airports.insert(b);
    airportscities.insert(d);


    if(cities.find(a.getCity()) == cities.end()) {

        std::list<Airport> lista = {a};

        std::pair<std::string,std::list<Airport>> pairr = {a.getCity(),lista};

        this->cities.insert(pairr);
    }

    else {

        cities.find(a.getCity())->second.push_back(a);
    }}


void Program_Data::addFlight(std::string source, std::string dest, std::string company){

    double distance = haversine(source,dest);
    graph.addFlight(source,dest,company,distance);

    std::string sourcecity = (airports.find(source)->second)->getCity();
    std::string destinationcity = (airports.find(dest)->second)->getCity();

    addFlight(destinationcity,source,sourcecity,dest,company,distance);
}

void Program_Data::addFlight(std::string destinationcity,std::string source, std::string sourcecity,std::string dest, std::string company, double weight)
{

    graphC.addFlight(destinationcity,source,sourcecity,dest,company,weight);

}


void Program_Data::addAirlines(Airlines a){

    std::pair<std::string,Airlines*> par  = {a.getName(),&a};

    this->airlines.insert(par);}


double Program_Data::haversine(std::string source, std::string destination)
{
    Airport Apsource = *(airports.find(source)->second);
    Airport Apdestination = *(airports.find(source)->second);

    double lat1 = Apsource.getLatitude();
    double lat2 = Apdestination.getLatitude();
    double lon1 = Apsource.getLongitude();
    double lon2 = Apdestination.getLongitude();
    // distance between latitudes
    // and longitudes
    double dLat = (lat2 - lat1) *
                  M_PI / 180.0;
    double dLon = (lon2 - lon1) *
                  M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;






}


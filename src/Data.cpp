//
// Created by luism on 25/12/2022.
//

#include "Data.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

Data::Data(){
    this->readAirports();
    this->readAirlines();
    this->buildFlights();
}

Airport Data::getAirport(std::string in){
    return(this->airports.find(in)->second);
}

Airlines Data::getAirline(std::string in){
    return(this->airlines.find(in)->second);
}

std::string Data::getAirportFromCity(std::string in) {
    return(this->cities.find(in)->second);
}

Graph Data::getGraph() {
    return (this->graph);
}

GraphC Data::getCityGraph() {
    return (this->graphC);
}

std::list<std::string> Data::getAirportsInCountry(std::string in){
    return this->countries.find(in)->second;
}

std::string Data::getCountry(std::string in){
    return (this->citiesInCountries.find(in)->second);
}

std::string Data::removeComma(std::string in){
    std::string out = in;
    while(out.find(' ')!=std::string::npos) out[out.find(' ')]='_';
    while(out.find(',')!=std::string::npos) out[out.find(',')]=' ';
    return(out);
}

std::string Data::removeUnderscore(std::string in){
    if(in=="_") return(in);
    std::string out = in;
    while(out.find('_')!=std::string::npos) out[out.find('_')] = ' ';
    return(out);
}

int Data::readAirports() {
    int out = 0;
    std::ifstream ifs("../airports.csv");
    std::string line;
    std::getline(ifs,line);

    while(std::getline(ifs,line)){

        line = removeComma(line);
        std::istringstream iss(line);

        std::string code,name,city,country;
        double latitude,longitude;

        iss >> code >> name >> city >> country >> latitude >> longitude;

        name=this->removeUnderscore(name);
        city=this->removeUnderscore(city);
        country=this->removeUnderscore(country);
        Airport a(code,name,city,country,latitude,longitude);

        this->airports.insert({code,a});
        this->graph.addAirport(a);
        this->graphC.addAirport(a);
        this->cities.insert({a.getCode(),a.getCity()});

        if(this->countries.find(country)==this->countries.end()) this->countries.insert({country,{}});
        this->countries.find(country)->second.push_back(code);

        if(this->citiesInCountries.find(city)==this->citiesInCountries.end()) this->citiesInCountries.insert({city,country});

        if(this->cityList.find(city)==this->cityList.end()) this->cityList.insert(city);

        out++;
    }
    return out;
}

int Data::readAirlines() {
    int out = 0;
    std::ifstream ifs("../airlines.csv");
    std::string line;
    std::getline(ifs,line);

    while(std::getline(ifs,line)){

        line = removeComma(line);
        std::istringstream iss(line);

        std::string code,name,callsign,country;

        iss >> code >> name >> callsign >> country;

        this->airlines.insert({code,Airlines(code,name,callsign,country)});
        out++;
    }
    return out;
}

int Data::buildFlights() {
    int out = 0;
    std::ifstream ifs("../flights.csv");
    std::string line;
    std::getline(ifs,line);

    while(std::getline(ifs,line)){

        line = removeComma(line);
        std::istringstream iss(line);

        std::string src,oregano,company;

        iss >> src >> oregano >> company;

        Airport a1 = this->getAirport(src), a2 = this->getAirport(oregano);

        std::string srcCountry = a1.getCity() + " (" + a1.getCountry() + ')',
        oreganoCountry = a2.getCity() + " (" + a2.getCountry() + ')';

        double dist = this->haversine(src,oregano);
        this->graph.addFlight(src,oregano,company,dist);
        this->graphC.addFlight(src,srcCountry,oregano,oreganoCountry,company,dist);

        out++;
    }
    return out;
}

double Data::haversine(std::string source, std::string destination)
{
    Airport Apsource = (airports.find(source)->second);
    Airport Apdestination = (airports.find(destination)->second);

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
    double out = rad * c;
    return out;
}
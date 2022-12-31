//
// Created by tomas on 26/12/2022.
//

#include <string>
#include <fstream>
#include <sstream>
#include "Filereader.h"
#include "Graph.h"
#include "Airlines.h"


void Filereader::airportReader(Program_Data& v){
    char comma;
    std::string line;

    std::ifstream ifs("../airpoirts.csv");
    std::getline(ifs,line);

    while(std::getline(ifs,line)){

        std::istringstream iss (line);

        std::string Code,Name, City, Country;
        double Latitude, Longitude;

        iss >> Code >> comma >> Name >> comma >> City >> comma >> Country >> comma  >> Latitude >> comma >> Longitude;

        Airport airport = Airport(Code,Name,City,Country,Latitude,Longitude);

        v.addAirport(airport);



    }
}

void Filereader:: airlinesReader(Program_Data& v) {

    char comma;
    std::string line;

    std::ifstream ifs("../airlines.csv");
    std::getline(ifs,line);

    while(std::getline(ifs,line)){

        std::istringstream iss (line);

        std::string Code,Name, City, Callsign, Country;

        iss >> Code >> comma >> Name >> comma >> Callsign >> comma >> Country;

        Airlines airlines = Airlines(Code,Name,Callsign,Country);

        v.addAirlines(airlines);

    }
}


void Filereader:: flightsReader(Program_Data& v) {

    char comma;
    std::string line;

    std::ifstream ifs("../flights.csv");
    std::getline(ifs,line);

    while(std::getline(ifs,line)){

        std::istringstream iss (line);

        std::string Source, Target, Airline;

        iss >> Source >> comma >> Target >> comma >> Airline;

        v.addFlight(Source,Target,Airline);


    }



    // distance calcuation : function(teta) = function(lat1 - lat2 ) + cos(lat1) * cos(lat2) * function(long2-long1)
}      // where function = sin^2 (teta/2)

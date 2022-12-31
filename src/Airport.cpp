//
// Created by luism on 25/12/2022.
//

#include "Airport.h"
#include <iostream>
#include <string.h>

Airport::Airport(std::string code, std::string name, std::string city, std::string country, double latitude, double longitude){
    this->code=code;
    this->name=name;
    this->city=city;
    this->country=country;
    this->latitude=latitude;
    this->longitude=longitude;
}

std::string Airport::getCode() {return this->code;}
std::string Airport::getName() {return this->name;}
std::string Airport::getCountry() {return this->country;}
std::string Airport::getCity() {return this->city;}
double Airport::getLatitude() {return this->latitude;}
double Airport::getLongitude() {return this->longitude;}
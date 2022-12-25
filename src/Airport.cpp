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
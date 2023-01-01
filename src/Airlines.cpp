//
// Created by luism on 25/12/2022.
//

#include "Airlines.h"
#include <iostream>
#include <string.h>

Airlines::Airlines(std::string code, std::string name, std::string callsign, std::string country){
    this->code=code;
    this->name=name;
    this->callsign=callsign;
    this->country=country;
}

std::string Airlines::getCode() {return this->code;}
std::string Airlines::getCountry() {return this->country;}
std::string Airlines::getCallsign() {return this->callsign;}
std::string Airlines::getName() {return this->name;}
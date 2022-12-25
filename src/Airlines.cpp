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
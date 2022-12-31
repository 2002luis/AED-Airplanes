//
// Created by luism on 25/12/2022.
//

#ifndef AED_AIRPLANE_AIRLINES_H
#define AED_AIRPLANE_AIRLINES_H

#include <iostream>
#include <string.h>

class Airlines {
private:
    std::string code, name, callsign, country;
public:
    Airlines(std::string code, std::string name, std::string callsign, std::string country);
    std::string getCode();
    std::string getName();
    std::string getCallsign();
    std::string getCountry();
};


#endif //AED_AIRPLANE_AIRLINES_H

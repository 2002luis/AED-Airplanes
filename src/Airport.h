//
// Created by luism on 25/12/2022.
//

#ifndef AED_AIRPLANE_AIRPORT_H
#define AED_AIRPLANE_AIRPORT_H

#include <iostream>
#include <string.h>

class Airport {
private:
    std::string code, name, city, country;
    double latitude, longitude;
public:
    Airport(std::string code, std::string name, std::string city, std::string country, double latitude, double longitude);
    std::string getCode();
    std::string getName();
    std::string getCity();
    std::string getCountry();
    double getLatitude();
    double getLongitude();
};


#endif //AED_AIRPLANE_AIRPORT_H

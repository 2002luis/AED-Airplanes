//
// Created by tomas on 26/12/2022.
//

#ifndef AED_AIRPLANE_FILEREADER_H
#define AED_AIRPLANE_FILEREADER_H


#include "Program_Data.h"

class Filereader {

public:
    static void airportReader(Program_Data & v);

    static void flightsReader(Program_Data & v);

    static void airlinesReader(Program_Data & v);
};


#endif //AED_AIRPLANE_FILEREADER_H

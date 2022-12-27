//
// Created by luism on 25/12/2022.
//

#ifndef AED_AIRPLANE_OVERLOADS_H
#define AED_AIRPLANE_OVERLOADS_H

#include <iostream>
#include "Airport.h"
#include "Airlines.h"
#include "Graph.h"

std::ostream& operator<<(std::ostream& os, Airport a);
std::ostream& operator<<(std::ostream& os, Airlines a);
std::ostream& operator<<(std::ostream& os, Graph a);
template<class T>
std::ostream& operator<<(std::ostream& os, std::list<T> a);

#endif //AED_AIRPLANE_OVERLOADS_H

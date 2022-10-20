//
// Created by feld on 20-10-2022.
//

#ifndef OVERLOADS
#define OVERLOADS

#include <ostream>
#include "Timetable.h"

//A FUNCAO DE PRINT CURSED


std::ostream& operator<<(std::ostream& os, const Timetable& a)
{

    std::vector<std::string> horas;
    horas.push_back("08:00");
    horas.push_back("08:30");
    horas.push_back("09:00");
    horas.push_back("09:30");
    horas.push_back("10:00");
    horas.push_back("10:30");
    horas.push_back("11:00");
    horas.push_back("11:30");
    horas.push_back("12:00");
    horas.push_back("12:30");
    horas.push_back("13:00");
    horas.push_back("13:30");
    horas.push_back("14:00");
    horas.push_back("14:30");
    horas.push_back("15:00");
    horas.push_back("15:30");
    horas.push_back("16:00");
    horas.push_back("16:30");
    horas.push_back("17:00");
    horas.push_back("17:30");
    horas.push_back("18:00");
    horas.push_back("18:30");
    horas.push_back("19:00");
    horas.push_back("19:30");
    horas.push_back("20:00");
    horas.push_back("20:30");

    os << "\t\t2a feira\t3a feira\t4a feira\t5a feira\t6a feira\t\n";
    for(unsigned long int i = 0; i < horas.size(); i++) os << horas[i] << '\t' << a.horario[0][i] << '\t' << a.horario[1][i] << '\t' << a.horario[2][i] << '\t' << a.horario[3][i] << '\t' << a.horario[4][i] << std::endl;

    return os;
}



#endif
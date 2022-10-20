//
// Created by feld on 20-10-2022.
//

#include "timetable.h"
#include <vector>
#include <string>
#include <iostream>

Timetable::Timetable(Lecture lecture){

    std::vector<std::string> temp(30,"");
    
    for(int i = 0; i < 5; i++) this->horario.push_back(temp);
    
    for(float i = lecture.duration; i > 0; i-=0.5){
        this->horario[lecture.day][(lecture.startTime+i)*2-8] = lecture.toString();
    }
}

Timetable::Timetable(Class turma){
    for(unsigned long int i = 0; i < turma.lectures.size(); i++){
        this->add(Timetable(*turma.lectures[i]));
    }
}

Timetable::Timetable(Student student){
    for(unsigned long int i = 0; i < student.classes.size(); i++){
        this->add(Timetable(*student.classes[i]));
    }
}

bool Timetable::add(Timetable a){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 30; j++){
            if(a.horario[i][j]!="" && this->horario[i][j]!="") return(false);
            a.horario[i][j]+=this->horario[i][j];
        }
    }
    this->horario = a.horario;
    return(true);
}

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

    os << "\t2a feira\t3a feira\t4a feira\t5a feira\t6a feira\t\n";  
    for(unsigned long int i = 0; i < horas.size(); i++) os << horas[i] << '\t' << a.horario[0][i] << '\t' << a.horario[1][i] << '\t' << a.horario[2][i] << '\t' << a.horario[3][i] << '\t' << a.horario[4][i];

    return os;
}
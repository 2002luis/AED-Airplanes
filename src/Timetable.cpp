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
        this->horario[lecture.day][(lecture.startTime+i)*2-16] = lecture.toString();
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


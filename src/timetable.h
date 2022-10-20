//
// Created by feld on 20-10-2022.
//

#ifndef AED_TIMETABLE_H
#define AED_TIMETABLE_H

#include <vector>
#include "student.h"
#include "class.h"
#include "lecture.h"

class Timetable {
    public:
        std::vector<std::vector<std::string>> horario;
        Timetable(Lecture lecture);
        Timetable(Class turma); //class é uma palavra reservada
        Timetable(Student student);
        bool add(const Timetable a);
};


#endif AED_TIMETABLE_H


//
// Created by feld on 20-10-2022.
//

#ifndef AED_TIMETABLE_H
#define AED_TIMETABLE_H

#include <vector>
#include "Student.h"
#include "Class_Hour.h"
#include "Lecture.h"

class Timetable {
    public:
        std::vector<std::vector<std::string>> horario;
        Timetable(Lecture lecture);
        Timetable(Class_Hour turma); //class é uma palavra reservada
        Timetable(Student student);
        bool add(const Timetable a);
};


#endif


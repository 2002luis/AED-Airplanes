//
// Created by feld on 20-10-2022.
//

#ifndef AED_CLASS_H
#define AED_CLASS_H

#include <string>
#include <vector>
#include "Lecture.h"
#include "Student.h"
#include "Uc.h"

class Class {
public:
    std::vector<Lecture*> lectures;
    std::vector<Student*> students;
    std::string name;
    UC* cadeira;
    Class(std::string name);
};


#endif AED_CLASS_H

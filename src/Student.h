//
// Created by luism on 18/10/2022.
//

#ifndef PROJC_STUDENT_H
#define PROJC_STUDENT_H

#include <string>
#include <vector>

#include "Class_Hour.h"

class Student{
    public:
        std::string name;
        unsigned long int num;
        std::vector<Class_Hour*> classes;
        Student(std::string name, unsigned long int num);
    
};
#endif

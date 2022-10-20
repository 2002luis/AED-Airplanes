//
// Created by luism on 18/10/2022.
//

#ifndef PROJC_CLASS_H
#define PROJC_CLASS_H

#include <string>
#include <student.h>


class Lecture{
    public:
        std::string classCode;
        int day;
        float startTime, duration;
        std::string classType;
        Lecture(std::string classCode, std::string day, float startTime, float duration, std::string classType);
        std::string toString();
};

#endif PROJC_CLASS_H

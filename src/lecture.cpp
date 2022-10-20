//
// Created by luism on 18/10/2022.
//

#include <string>
#include <lecture.h>

Lecture::Lecture(std::string classCode, std::string day, float startTime, float duration, std::string classType){
    this->classCode = classCode;
    if(day=="Monday") this->day = 0;
    else if(day=="Tuesday") this->day = 1;
    else if(day=="Wednesday") this->day = 2;
    else if(day=="Thursday") this->day = 3;
    else this->day = 4;
    this->startTime = startTime;
    this->duration = duration;
    this->classType = classType;
}

std::string Lecture::toString(){
    return(this->classCode);
}

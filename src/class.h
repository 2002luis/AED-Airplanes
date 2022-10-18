//
// Created by luism on 18/10/2022.
//

#ifndef PROJC_CLASS_H
#define PROJC_CLASS_H
#include <string.h>

class Class{
    public string classCode;
    public int day;
    public float startTime, duration;
    public string classType;
    Class(string classCode, string day, float startTime, float duration, string classType);
    public string toString();
};
#endif PROJC_CLASS_H

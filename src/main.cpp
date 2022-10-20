//
// Created by feld on 20-10-2022.
//

#include "Lecture.h"
#include "Class_Hour.h"
#include "Student.h"
#include "Timetable.h"
#include "Uc.h"
#include "overloads.h"
#include <iostream>










int main(){
    Lecture teste1("Teste","Monday",8,2,"Gay");
    std::cout << Timetable(teste1) << std::endl;
}
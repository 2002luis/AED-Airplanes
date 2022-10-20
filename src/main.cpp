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
#include <vector>









int main(){
    Lecture teste1("Teste","Monday",8,2,"Gay"), teste2("Teste", "Thursday",14.5,1,"Gay");
    Class_Hour testClass("Gay");
    testClass.lectures.push_back(teste1);
    testClass.lectures.push_back(teste2);
    std::cout << Timetable(testClass) << std::endl;
}
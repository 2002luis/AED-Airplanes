#include "Filereader.h"
#include "Uc.h"
#include "Class_Hour.h"
#include "Lecture.h"
#include <iostream>
#include <vector>
#include <map>      // podemos usar sets
#include <set>
#include <fstream>
/*
Filereader:: Filereader(){

    ifstream students_classesfile("../students_classes.csv"), classes_per_ucfile("../classes_per_uc.cvs"),classesfile("../classes.csv");

    //students_classesfile.open("../students_classes.csv");

    string student;
    struct st {
        unsigned long code;
        string name, Lecture;
        vector<string> UCS;
    };
    // usar função para adicionar alunos com variavel fora do while();
    st a;
    while(getline(students_classesfile,student)){

        char comma;
        string uc;
        istringstream line (student);
        line >> a.code >> comma >> a.name >> uc >> a.Lecture;
        a.UCS.push_back(uc);

        struct classes_per_uc{
            string cadeira;
            vector<string> turma;
        };

        classes_per_uc b;
        while(getline(classes_per_ucfile,student)){

            string cadeira;
            string turma;

            istringstream line (student);

            line >> b.cadeira >> turma;

            b.turma.push_back(turma);







        }



















    }
};
 */

std::string Filereader::removeComma(std::string in){
    std::string out = "";
    for(unsigned long int i = 0; i < in.size(); i++){
        if(in[i]!=',') out+=in[i];
        else out+=' ';
    }
    return(out);
}

map<std::string,UC> Filereader::readUcs() {
    map<std::string,UC> out;
    std::string line;
    std::ifstream ifs("../classes_per_uc.csv");
    std::getline(ifs,line);
    while(std::getline(ifs,line)){
        line = removeComma(line);
        std::istringstream iss(line);
        std::string ucName, className;
        iss >> ucName >> className;
        if(out.find(ucName)==out.end()) out.insert(pair<std::string ,UC>(ucName,UC(ucName)));
        out.at(ucName).classes.insert(pair<std::string,Class_Hour>(className,Class_Hour(className)));
    }
    return(out);
}

map<std::string, UC> Filereader::readClasses(map<std::string, UC> in) {
    map<std::string,UC> out = in;
    std::string line;
    std::ifstream ifs("../classes.csv");
    std::getline(ifs,line);
    while(std::getline(ifs,line)){
        line = removeComma(line);
        std::istringstream iss(line);
        std::string classCode, ucCode, day, classType;
        float startHour, duration;
        iss >> classCode >> ucCode >> day >> startHour >> duration >> classType;
        if(out.find(ucCode)!=out.end() && out.at(ucCode).classes.find(classCode)!=out.at(ucCode).classes.end()) out.at(ucCode).classes.at(classCode).lectures.push_back(Lecture(classCode,day,startHour,duration,classType));
    }
    return out;
}
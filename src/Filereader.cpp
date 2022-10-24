#include "Filereader.h"
#include "uc.h"
#include <iostream>
#include <vector>
#include <map>      // podemos usar sets

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
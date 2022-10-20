//
// Created by up202005832 on 17/10/2022.
//

#ifndef MRDS_UC_H
#define MRDS_UC_H

#include <string.h>
#include <vector>
#include "Class.h"

class UC{
    public:
        UC(int code);
        std::vector<Class*> classes;
        int code;
        std::string toString();
};



#endif MRDS_UC_H

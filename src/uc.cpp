//
// Created by luism on 18/10/2022.
//
#include <string>

UC::UC(int code){
    this->code = code;
}

std::string UC::toString(){
    std::string out = "" + code;
    while(out.size()<3) out = '0'+out;
    return("L.EIC"+out);
}
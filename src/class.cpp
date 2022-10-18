//
// Created by luism on 18/10/2022.
//

Class::Class(string classCode, string day, float startTime, float duration, string classType){
    this.classCode = classCode;
    if(day=="Monday") this.day = 0;
    else if(day=="Tuesday") this.day = 1;
    else if(day=="Wednesday") this.day = 2;
    else if(day=="Thursday") this.day = 3;
    else this.day = 4;
    this.startTime = startTime;
    this.duration = duration;
    this.classType = classType;
}

string Class::toString(){
    return(this.classCode);
}

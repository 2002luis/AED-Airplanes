//
// Created by luism on 07/01/2023.
//

#ifndef AED_AIRPLANE_TRIPLE_H
#define AED_AIRPLANE_TRIPLE_H

template<class T1, class T2, class T3>
class triple {
public:
    T1 first;
    T2 second;
    T3 third;
    triple(T1 t1, T2 t2, T3 t3){
        this->first=t1;
        this->second=t2;
        this->third=t3;
    }
};


#endif //AED_AIRPLANE_TRIPLE_H

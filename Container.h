//
// Created by Admin on 03.01.2021.
//

#ifndef CONTAINER_H
#define CONTAINER_H

#include "Exceptions.h"

template <typename T, size_t COUNT>
class Container{
    T * elements = nullptr;
public:
    bool is_empty(){
        return elements[0]==0 && elements[1]==0 && elements[2]==0 && elements[3]==0;
    }
    T & operator[](int i){
        if(i < 0 || i >= COUNT)
            throw Improper_Range();
        return elements[i];
    }
    Container(){
        elements = new T [COUNT];
    }
    ~Container(){
        delete [] elements;
    }
};

#endif //CONTAINER_H

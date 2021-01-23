//
// Created by Admin on 02.01.2021.
//

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

struct Zero_Drink : public std::exception{
    std::string message;
    const char * what() const noexcept override{
        return message.c_str();
    };
    explicit Zero_Drink(const std::string & msg = "Lack of this drink! Choose it once more!"){
        message = msg;
    };
};

struct Wrong_Input : public std::exception{
    std::string message;
    const char * what() const noexcept override{
        return message.c_str();
    }
    explicit Wrong_Input(const std::string & msg = "Wrong input! Type it once more!"){
        message = msg;
    };
};

struct Greater_Value : public std::exception{
    std::string message;
    const char * what() const noexcept override{
        return message.c_str();
    }
    explicit Greater_Value(const std::string & msg = "Coin must not be greater than sum to pay!"){
        message = msg;
    };
};

struct Improper_Range : public std::exception{
    std::string message;
    const char * what() const noexcept override{
        return message.c_str();
    }
    explicit Improper_Range(const std::string & msg = "ID must not be less than 1 or higher than 4"){
        message = msg;
    }
};


#endif //EXCEPTIONS_H

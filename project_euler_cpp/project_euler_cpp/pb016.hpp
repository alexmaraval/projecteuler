//
//  pb016.hpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 04.10.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#ifndef pb016_hpp
#define pb016_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>

std::string manual_sum(const std::string &a, const std::string &b);
std::string manual_prod(const std::string &a, const std::string &b);

class bigint {
    
    friend std::ostream &operator<< (std::ostream &os, const bigint &n);
    
private:
    std::string _number;
    
public:
    // constructor, destructor and copy constructor
    bigint(std::string num = "0");
    ~bigint(){};
    
    // get function
    std::string get_str_num();
    
    // operators bigint with bigint
    bigint operator+(const bigint &b);
    bigint operator*(const bigint &b);
    
    // assignment and conversion
    bigint &operator= (const bigint &b);
    bigint &operator= (const std::string &s);
    
    // operators bigint with int
    bigint operator+(const int &n);
    bigint operator*(const int &n);
    
    // operators bigint with long int
    // operators bigint with long long int
    
    // methods
    int digit_sum();    // for solution to PB016
};

void pb016();

#endif /* pb016_hpp */

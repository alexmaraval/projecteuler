//
//  pb003.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 13.09.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//
// Program to print all prime factors
#include "pb003.hpp"
#include <iostream>

void pb003(long int p)
{
    for(int i=1; i<p; i++)
    {
        if(p%i == 0)
        {
            //std::cout << i << ", ";
            p = p/i;
        }
    }
    std::cout << "PB3 : largest prime number in the decomposition" << p << std::endl;
}

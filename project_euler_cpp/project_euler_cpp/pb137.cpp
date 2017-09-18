//
//  pb137.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 14.09.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb137.hpp"
double af(double x)
{
    long int max = 10000000;
    long int fiba = 1;
    long int fibb = 1;
    long int fib = 0;
    
    double sum = x*fiba + pow(x,2)*fibb;
    
    for(int i=0; i<max; i++)
    {
        fib = fiba + fibb;
        fiba = fibb;
        fibb = fib;
        
        sum += pow(x,i+3)*fib;
    }
    return sum;
}

void pb137()
{
    double x = 0.74589;
    for(int i=0; i<1e6; i++)
    {
        x += (double) 1/1e6;
        std::cout << "af=" << af(x) << ", x=" << x << std::endl;
    }
    
}

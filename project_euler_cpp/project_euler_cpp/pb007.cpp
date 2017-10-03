//
//  pb007.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 14.09.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb007.hpp"

bool isprime(long int n)
{
    for(int i=2; i<n; i++)
    {
        if(n%i==0){return false;}
    }
    return true;
}

void pb007()
{
    int counter = 0;
    long int i = 2;
    while(counter < 10001)
    {
        if(isprime(i))
        {
            counter++;
        }
        i++;
    }
    std::cout << "PB7 : 10001st prime number = " << i-1 << std::endl;
}

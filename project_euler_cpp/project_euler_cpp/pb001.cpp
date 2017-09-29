//
//  pb1.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 13.09.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb1.hpp"
#include <iostream>

void pb1()
{
    int sum = 0;
    for(int i=1; i<1000; ++i)
    {
        if(i%3 == 0 or i%5 == 0)
        {
            sum += i;
        }
    }
    std::cout << "PB1 : sum of numbers divisible by 3 & 5 = " << sum << std::endl;
}

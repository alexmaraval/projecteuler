//
//  pb6.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 14.09.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb6.hpp"
void pb6()
{
    long int sumsq = 0;
    long int sqsum = 0;
    for(int i=1; i<=100; i++)
    {
        sumsq += i*i;
        sqsum += i;
    }
    sqsum *= sqsum;
    std::cout << "PB6 : square of sum - sum of squares (1 to 100) = " << sqsum - sumsq << std:: endl;
}

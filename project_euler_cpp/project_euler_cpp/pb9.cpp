//
//  pb9.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 14.09.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb9.hpp"
bool istriplet(int a, int b, int c)
{
    if(a*a + b*b == c*c)
    {
        return true;
    }
    return false;
}

void pb9()
{
    for(int i=0; i<1000; i++)
    {
        for(int j=i+1; j<1000; j++)
        {
            for(int k=j+1; k<1000; k++)
            {
                if(istriplet(i, j, k) and i+j+k == 1000)
                {
                    std::cout << "PB9 : product of Pythagore triplet with sum equal to 1000 is = " << i*j*k << std::endl;
                }
            }
        }
    }
}


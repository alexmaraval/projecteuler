//
//  pb11.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 15.09.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb11.hpp"
int nb_div(long int n)
{
    int cnt = 0;
    for(long int i=1; i<=n; i++)
    {
        if(n%i == 0)
        {
            cnt++;
        }
    }
    return cnt;
}

long int triangular(int n)
{
    return (0.5*n*(n+1));
}

void pb11()
{
    std::cout << "PB11 : not working yet... SAD!" << std::endl;
}

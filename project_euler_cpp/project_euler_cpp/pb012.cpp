//
//  pb12.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 15.09.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb12.hpp"

int nb_div(long int n)
{
    if (n%2 == 0){n = n/2;}
    int div = 1;
    for (int i=2; i<=n; i++)
    {
        if(n%i == 0)
        {
            div++;
        }
    }
    return div;
}

void pb12()
{
    long int n = 1;
    int divn = nb_div(n);
    int divnp1 = nb_div(n+1);
    while(divn * divnp1 <= 500)
    {
        n++;
        divn = divnp1;
        divnp1 = nb_div(n+1);
    }
    std::cout << "PB12 : first triangular number with 500 multiplicators is " << n * (n+1) * 0.5 << std::endl;
}

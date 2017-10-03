//
//  pb014.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 29.09.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb014.hpp"

long int collatz_len(long int n)
{
    long int len = 1;
    while(n > 1)
    {
        len++;
        if(n%2 == 0)
        {
            n = n/2;
        }
        else
        {
            n = 3*n+1;
        }
    }
    return len;
}

void pb014()
{
    long int max_len = 0, temp_len = 0, start_ml = 0;
    for(int i=1; i<=1000000; i++)
    {
        temp_len = collatz_len(i);
        if(temp_len > max_len)
        {
            max_len = temp_len;
            start_ml = i;
        }
    }
    printf ("PB014: maximume length of collatz chain is %ld and starts from %ld\n", max_len, start_ml);
}

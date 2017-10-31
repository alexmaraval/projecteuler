//
//  tribonacci.cpp
//  tribonacci
//
//  Created by Alexandre Maraval on 31.10.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "tribonacci.hpp"

long long int recursive_tribonacci(int n)
{
    if(n == 1 or n == 2) {return 1;}
    if(n == 3) {return 2;}
    return(recursive_tribonacci(n-1) + recursive_tribonacci(n-2) + recursive_tribonacci(n-3));
}

long long int iterative_tribonacci(int n)
{
    std::vector<long long int> t = {1,1,2};
    if(n == 1 or n == 2) {return t[0];}
    if(n == 3) {return t[2];}
    
    for(int i=4; i<=n; i++)
    {
        long long int t1 = t[2], t0 = t[1];
        t[2] = t[0] + t[1] + t[2];
        t[1] = t1;
        t[0] = t0;
    }
    return(t[2]);
}

bigint big_iterative_tribonacci(int n)
{
    std::vector<bigint> t;
    t.push_back(bigint("1"));
    t.push_back(bigint("1"));
    t.push_back(bigint("2"));
    if(n == 1 or n == 2) {return t[0];}
    if(n == 3) {return t[2];}
    
    for(int i=4; i<=n; i++)
    {
        bigint t1 = t[2], t0 = t[1];
        t[2] = t[0] + t[1] + t[2];
        t[1] = t1;
        t[0] = t0;
    }
    return(t[2]);
}

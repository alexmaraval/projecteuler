//
//  pb2.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 13.09.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb2.hpp"

void pb2(int n)
{
    long int sum = 2;
    long int fiba = 1;
    long int fibb = 2;
    long int fib = 0;
    
    while(fib < n)
    {
        fib = fiba + fibb;
        fiba = fibb;
        fibb = fib;
        if(fib%2 == 0){sum += fib;}
        //std::cout << sum << std::endl;
        //std::cout << fib << std::endl;

    }
    std::cout << "PB2 : sum of even fibonacci numbers lower than n = " << sum << std::endl;
}

long int fibo(int n)
{
    if(n==1 or n==2){ return n;}
    return (fibo(n-1) + fibo(n-2));
}

long int fastfibo(int n)
{
    if(n==1 or n==2){ return n;}
    
    long int fiba = 1;
    long int fibb = 2;
    long int fib = 0;
    
    for(int i=0; i<=n-3; i++)
    {
        fib = fiba + fibb;
        fiba = fibb;
        fibb = fib;
    }
    return fib;
}

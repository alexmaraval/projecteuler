//
//  pb010.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 14.09.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb010.hpp"

void eratos1(std::vector<long int> &v, long int n)
{
    // create the array of all integers
    std::vector<long int> num;
    num.push_back(0);
    for(long int i=2; i<=n; i++)
    {
        num.push_back(i);
    }
    
    v.clear();
    // eliminate multiples : for each number in num, check if he is still in num, if yes then eliminate all its multiples by iterating by this number and replacing num reached by zero
    for(long int i=2; i<n; i++)
    {
        if(num[i-1] != 0)
        {
            v.push_back(num[i-1]);
            for(long int j=i+i; j<=n; j=j+i)
            {
                num[j-1] = 0;
            }
        }
    }
}

void pb010()
{
    long int sum = 0;
    std::vector<long int> v;
    int n = 2e6;
    eratos1(v, n);
    for(int i=0; i<v.size(); i++)
    {
        sum+=v[i];
    }
    std::cout << "PB10 : sum of primes below 2e6 = " << sum << std::endl;
}

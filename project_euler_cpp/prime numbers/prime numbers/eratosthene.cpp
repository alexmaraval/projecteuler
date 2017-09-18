//
//  eratosthene.cpp
//  prime numbers
//
//  Created by Alexandre Maraval on 14.09.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "eratosthene.hpp"

void print_vec(std::vector<long int> v)
{
    for(long int i=0; i<v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

// feed any vector to the function it will create again the array
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

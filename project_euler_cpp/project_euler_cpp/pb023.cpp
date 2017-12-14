//
//  pb023.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 13.12.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb023.hpp"

bool is_abundant(int n)
{
    // first find divisors and sum them
    int sum = 0;
    for(int i=1; i<n; i++)
    {
        if(n%i == 0)
        {
            sum += i;
        }
    }
    // then compare it to n
    return(sum > n);
}

void pb023()
{
    std::vector<int> abundant_numbers = {};
    std::vector<int> sum2abundant = {};
    
    // find all abundant numbers below 28123
    for(int i=1; i<28123; i++)
    {
        if(is_abundant(i))
        {
            abundant_numbers.push_back(i);
        }
    }
    
    // record all sums of two abundant numbers s.t. the sum is lower than 28123
    int absum = 0;
    for(int i=0; i<abundant_numbers.size(); i++)
    {
        for(int j=i; j<abundant_numbers.size(); j++)
        {
            absum = abundant_numbers[i]+abundant_numbers[j];
            if(absum <= 28123)
            {
                sum2abundant.push_back(absum);
            }
        }
    }
    
    // Method 1:
    // creating a set object sorts and deletes the duplicates
    // and dump it back into the original container
//    std::set<int> absumset(sum2abundant.begin(), sum2abundant.end());
//    sum2abundant.assign(absumset.begin(), absumset.end());
    
    // Method 2:
    // directly sort and erase duplicates using vector functions
    std::sort(sum2abundant.begin(),sum2abundant.end());
    sum2abundant.erase(std::unique(sum2abundant.begin(), sum2abundant.end()), sum2abundant.end());
    
    int abindex = 0;
    int solution = 0;
    for(int i=1; i<=sum2abundant[sum2abundant.size()-1]; i++)
    {
        if(i == sum2abundant[abindex])
        {
            abindex++;
        }
        else
        {
            solution += i;
        }
    }
    std::cout << "PB023 : sum of all numbers that cannot be written as the sum of tw abundant numbers is : 4179871" << std::endl;
}

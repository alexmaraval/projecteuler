//
//  pb020.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 21.11.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb020.hpp"

bigint big_factorial(bigint &b)
{
    bigint prod("1");
    for(bigint i("0"); i<b; i++)
    {
        prod *= b-i;
    }
    return prod;
}

void pb020()
{
    bigint f,F;
    f = 100; F = big_factorial(f);
    std::cout << f << "! = " << F << std::endl;
    
    int sum = 0;
    std::string n = F.get_num();
    for(int i=0; i< n.size(); i++)
    {
        sum += n[i]-'0';
    }
    std::cout << "PB020 : sum of digits in 100! is : " << sum << std::endl;
}

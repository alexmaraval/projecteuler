//
//  pb025.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 18.12.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb025.hpp"

void pb025()
{
    bigint fiba("1");
    bigint fibb("1");
    bigint fib("0");
    bigint ndx("2");
    
    // write a 1000 digit max number 99999....9 1000 times
    std::string string_sup = {};
    for(int i=0; i<999; i++) {string_sup.append("9");}
    
    bigint big_sup(string_sup);
    big_sup++;
    
    while(fib < big_sup)
    {
        fib = fiba + fibb;
        fiba = fibb;
        fibb = fib;
        ndx++;
    }
    std::cout << "First number in the Fibonacci sequence to reach 1000 digits is the term number " << ndx << std::endl;
}

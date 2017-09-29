//
//  pb5.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 14.09.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb5.hpp"
void pb5()
{
    int n = 1*2*3*5*7*11*13*17*19;
    n = n*2*2*2*3;
    std::cout << "PB5 : smallest ineteger divisible by all 1 to 20 wihtout rest is = " << n << std::endl;
}

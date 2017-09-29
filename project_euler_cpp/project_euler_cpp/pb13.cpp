//
//  pb13.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 29.09.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb13.hpp"

void pb13()
{
    std::ifstream file("problem13.rtf");
    
    if (!file.is_open()) {
        perror(file.string::c_str());
        std::cout << "File not found" << std::endl;
        exit(1); // terminate with error
    }
    
    long long int x, sum = 0;
    
    while (file >> x) {
        sum = sum + x;
    }
    
    file.close();
    std::cout << "Sum = " << sum << std::endl;
}

//
//  main.cpp
//  ackermann
//
//  Created by Alexandre Maraval on 03.10.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include <iostream>
#include "ackermann.hpp"

int main(int argc, const char * argv[]) {
    
    for (int i=0; i<=4; i++)
    {
        for (int j=0;j<=4; j++)
        {
            printf ("ackerman (%d,%d) is: %d\n",i,j, ack(i,j));
            if(i == 4 and j == 1)
            {
                std::cout << "Not going further than that I'm afraid..." << std::endl;
                exit(1);
            }
        }
    }
    
    return 0;
}

//
//  ackermann.cpp
//  ackermann
//
//  Created by Alexandre Maraval on 03.10.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "ackermann.hpp"

int ack(int m, int n)
{
    if      (m == 0)    { return(n+1);                  }
    else if (n == 0)    { return(ack(m-1,1));           }
    else                { return(ack(m-1, ack(m,n-1))); }
}

//
//  pb018.hpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 20.11.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#ifndef pb018_hpp
#define pb018_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

class tree {
    std::vector<std::vector< long int>> _tree;
    unsigned long _rows;
public:
    tree(std::vector<std::vector< long int>>& t);
     long int count_path();
     long int max_path();
    void print();
};
void pb018();

#endif /* pb018_hpp */

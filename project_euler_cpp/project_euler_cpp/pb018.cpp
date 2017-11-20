//
//  pb018.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 20.11.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb018.hpp"

tree::tree(std::vector<std::vector< long int>>& t)
{
    _tree = t;
    _rows = t.size();
}

 long int tree::count_path()
{
    std::vector< long int> pascal = {}, previous = {};
    
    // Pascal's triangle
    for( long int i=0; i<_rows; i++)
    {
        previous = pascal;
        for( long int j=1; j<previous.size(); j++)
        {
            pascal[j] = previous[j-1] + previous[j];
        }
        pascal.push_back(1);
    }
     long int sum = 0;
    for( long int i=0; i<pascal.size(); i++){ sum += pascal[i]; }
    return sum;
}

 long int tree::max_path()
{
    for( long int i=1; i<_rows; i++)
    {
        for( long int j=0; j<_tree[i].size(); j++)
        {
            if(j == 0)
            {
                _tree[i][j] += _tree[i-1][j];
            }
            else if (j == _tree[i].size()-1)
            {
                _tree[i][j] += _tree[i-1][j-1];
            }
            else
            {
                _tree[i][j] += std::max(_tree[i-1][j],_tree[i-1][j-1]);
            }
        }
    }
     long int max = 0;
    for( long int k=0; k<_tree[_tree.size()-1].size(); k++)
    {
        max = std::max(max, _tree[_tree.size()-1][k]);
    }
    return max;
}

void tree::print()
{
    for( long int i=0; i<_tree.size(); i++)
    {
        for( long int j=0; j<_tree[i].size(); j++)
        {
            std::cout << _tree[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void pb018()
{
    std::vector<std::vector< long int>> t =
    {
                      {75},
                     {95,64},
                    {17,47,82},
                   {18,35,87,10},
                  {20,04,82,47,65},
                 {19,01,23,75,03,34},
                {88,02,77,73,07,63,67},
               {99,65,04,28,06,16,70,92},
              {41,41,26,56,83,40,80,70,33},
             {41,48,72,33,47,32,37,16,94,29},
            {53,71,44,65,25,43,91,52,97,51,14},
           {70,11,33,28,77,73,17,78,39,68,17,57},
          {91,71,52,38,17,14,91,43,58,50,27,29,48},
         {63,66,04,68,89,53,67,30,73,16,69,87,40,31},
        {04,62,98,27,23, 9,70,98,73,93,38,53,60,04,23}
    };
    tree T(t);
//    std::cout << T.count_path() << std::endl;
//    T.print();
    std::cout << "PB067 : heaviest path is " << T.max_path() << std::endl;
//    T.print();
}

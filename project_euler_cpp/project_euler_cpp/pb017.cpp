//
//  pb017.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 08.11.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb017.hpp"

void number_decompose(int n, std::vector<int>& N)
{
    int d = 10; int x = 0, y = 0;
    while (10*n/d != 0) {
        x = (n%d - y);
        y += x;
        d *= 10;
        N.push_back(x);
    }
    std::reverse(N.begin(), N.end());
    if(N[N.size()-2] == 10)
    {
        N[N.size()-2] = N[N.size()-2] + N[N.size()-1];
        N.pop_back();
    }
}

std::string number_to_words(int n)
{
    std::vector<std::string> unit = {"","one","two", "three","four","five","six","seven","eight","nine","ten","eleven","twelve",
                                     "thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    std::vector<std::string> ten  = {"","teen","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    if(n <= 19) { return unit[n]; }
    else if(n < 100) { return ten[n/10]; }
    else if(n < 1000) { return unit[n/100] + "hundred"; }
    else if(n < 10000) { return unit[n/1000] + "thousand"; }
    else return "-void-";
}

void decompose_to_word(std::vector<int>& N, std::vector<std::string>& W)
{
    int sum = 0;
    for(int i=0; i<N.size(); i++)
    {
        sum += N[i];
        if(N[i] != 0)
        {
            W.push_back(number_to_words(N[i]));
        }
    }
    if(sum > 100 and sum%100 != 0)
    {
        W.push_back("and");
//        std::swap(W[1], W[W.size()-1]);
    }
}

void pb017()
{
    int TL = 0;
    for(int n = 1; n<=2000; n++)
    {
        std::vector<int> N = {};
        number_decompose(n, N);
//        for(int i=0; i<N.size()-1; i++)
//        {
//            std::cout << N[i] << "+";
//        }
//        std::cout << N[N.size()-1] << std::endl;
        
        std::vector<std::string> W = {};
        decompose_to_word(N, W);
        int leng = 0;
        for(int i=0; i<W.size(); i++)
        {
            leng += W[i].size();
        }
        std::cout << n << " is " << leng << " characters long : ";
        for(int i=0; i<W.size()-1; i++)
        {
            std::cout << W[i] << " ";
        }
        std::cout << W[W.size()-1] << std::endl;
        TL += leng;
    }
    std::cout << "Total length = " << TL << std::endl;
}
// nine hundred and ninety eight

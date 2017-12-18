//
//  pb024.hpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 14.12.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#ifndef pb024_hpp
#define pb024_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

// with 10 digits there are 10! = 3628800 permutations
// if we start with '0' then there are 9 digits left to permute so starting with '0' there are 9! = 362880 permuations
// if we start with '1' there will also be 9! permutations so starting with '0' or one we have 2*9! = 725760 permutations.
// Therefore, to reach the 1'000'000 th permutation in the lexicographic order, it has to start with '2' because 3*9! = 1088640 permutations.
// we can continue this inductive reasonning:
//      now that we know that the first figit must be '2' we can count the permutations again with the 9 digits left to guess the second digit.
//      starting with '20' there are 8! = 40320 permutations so we have seen 725760 + 40320 = 766080 permutations,
//      starting with '21' there are 8! = 40320 permutations so we have seen 766080 + 40320 = 806400 permutations,
//      starting with '23' there are 8! = 40320 permutations so we have seen 806400 + 40320 = 846720 permutations,
//      starting with '24' there are 8! = 40320 permutations so we have seen 846720 + 40320 = 887040 permutations,
//      starting with '25' there are 8! = 40320 permutations so we have seen 887040 + 40320 = 927360 permutations,
//      starting with '26' there are 8! = 40320 permutations so we have seen 927360 + 40320 = 967680 permutations,
//      starting with '27' there are 8! = 40320 permutations so we have seen 967680 + 40320 = 1008000 permutations, so it must start with '27'.
//          starting with '270' there are 7! = 5040 permutations so we have seen 967680 + 5040 = 972720 permutations,
//          starting with '271' there are 7! = 5040 permutations so we have seen 972720 + 5040 = 977760 permutations,
//          starting with '273' there are 7! = 5040 permutations so we have seen 977760 + 5040 = 982800 permutations,
//          starting with '274' there are 7! = 5040 permutations so we have seen 982800 + 5040 = 987840 permutations,
//          starting with '275' there are 7! = 5040 permutations so we have seen 987840 + 5040 = 992880 permutations,
//          starting with '276' there are 7! = 5040 permutations so we have seen 992880 + 5040 = 997920 permutations,
//          starting with '278' there are 7! = 5040 permutations so we have seen 997920 + 5040 = 1002960 permutations so it must to start with '278'.
//              starting with '2780' there are 6! = 720 permutations so we have seen 997920 + 720 = 998640 permutations,
//              starting with '2781' there are 6! = 720 permutations so we have seen 998640 + 720 = 999360 permutations,
//              starting with '2783' there are 6! = 720 permutations so we have seen 999360 + 720 = 1000080 permutations, so it must start with '2783'.
//                  starting with '27830' there are 5! = 120 permutations so we have seen 999360 + 120 = 999480 permutations,
//                  starting with '27831' there are 5! = 120 permutations so we have seen 999480 + 120 = 999600 permutations,
//                  starting with '27834' there are 5! = 120 permutations so we have seen 999600 + 120 = 999720 permutations,
//                  starting with '27835' there are 5! = 120 permutations so we have seen 999720 + 120 = 999840 permutations,
//                  starting with '27836' there are 5! = 120 permutations so we have seen 999840 + 120 = 999960 permutations,
//                  starting with '27839' there are 5! = 120 permutations so we have seen 999960 + 120 = 1000080 permutations, so it must start with '27839'.
//                      starting with '278390' there are 4! = 24 permutations so we have seen 999960 + 24 = 999984 permutations,
//                      starting with '278391' there are 4! = 24 permutations so we have seen 999984 + 24 = 1000008 permutations, so it must start with '278391'.
//                          starting with '2783910' there are 3! = 6 permutations so we have seen 999984 + 6 = 999990 permutations,
//                          starting with '2783914' there are 3! = 6 permutations so we have seen 999990 + 6 = 999996 permutations,
//                          starting with '2783915' there are 3! = 6 permutations so we have seen 999996 + 6 = 1000002 permutations, so it has to start with '2783915'.
//                              starting with '27839150' there are 2! = 1 permutations so we have seen 999996 + 2 = 999998 permutations,
//                              starting with '27839154' there are 2! = 1 permutations so we have seen 999998 + 2 = 1000000 permutations, so it has to start with '27839154'.
//                                  starting with '278391540' there is 1! = 1 permutation so we have seen 1000000 + 1 = 1000001 permutations, so it has to start with '278391540'.
// So '2783915406' is the permutation number 999'999 (indeed remember that permutation number 0 is 0123456789) so the 1'000'000th permutation has to be '2783915460'.

void pb024();

#endif /* pb024_hpp */

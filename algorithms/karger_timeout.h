//
// Created by Alessandro on 05/06/2020.
//

#ifndef ALGADVHW3_KARGER_TIMEOUT_H
#define ALGADVHW3_KARGER_TIMEOUT_H

#include <chrono>
#include <climits>
#include "../utilities/Graph_Data.h"
#include "../subroutines/full_contraction.h"

//#define TIMEOUT 120.00
#define TIMEOUT 60.00

unsigned int karger_timeout(const Graph_Data& G, const unsigned int d) {
    //save the starting time for the TIMEOUT
    auto start = std::chrono::steady_clock::now();
    unsigned int opt_sol = INT_MAX;
    //k = d * (n^2)/2 * log n
    double k = d * (pow(G.getNVec(),2) / 2) * log(G.getNVec());
    auto timeout_check = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_passed = timeout_check - start;
    //repeat full_contraction k times or until we exceed the TIMEOUT
    for(unsigned int cycle = 0; cycle < k && time_passed.count() < TIMEOUT; ++cycle){
        //call to full_contraction
        unsigned int random_sol = full_contraction(G.getNVec(), G.getEdges());
        //if the cut find is smaller that the past optimal solution
        if(random_sol < opt_sol){
            //save the new minimum cut
            opt_sol = random_sol;
        }
        //compute current time with respect to the starting time
        timeout_check = std::chrono::steady_clock::now();
        time_passed = timeout_check - start;
    }
    return opt_sol;
}

#endif //ALGADVHW3_KARGER_TIMEOUT_H

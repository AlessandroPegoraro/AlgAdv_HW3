//
// Created by Enrico on 05/06/2020.
//

#ifndef ALGADVHW3_KARGER_H
#define ALGADVHW3_KARGER_H

#include <climits>
#include "../utilities/Graph_Data.h"
#include "../subroutines/full_contraction.h"

unsigned int karger(const Graph_Data& G, const unsigned int d) {
    unsigned int opt_sol = INT_MAX;
    //k = d * (n^2)/2 * log n
    double k = d * (pow(G.getNVec(),2) / 2) * log(G.getNVec());
    //repeat full_contraction k times
    for(unsigned int cycle = 0; cycle < k; ++cycle){
        //call to full_contraction
        unsigned int random_sol = full_contraction(G.getNVec(), G.getEdges());
        //if the cut find is smaller that the past optimal solution
        if(random_sol < opt_sol){
            //save the new minimum cut
            opt_sol = random_sol;
        }
    }
    return opt_sol;
}

#endif //ALGADVHW3_KARGER_H
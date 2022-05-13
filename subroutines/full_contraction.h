//
// Created by Alessandro on 05/06/2020.
//

#ifndef ALGADVHW3_FULL_CONTRACTION_H
#define ALGADVHW3_FULL_CONTRACTION_H

#include <vector>
#include <random>
#include <chrono>
#include "../utilities/Graph_Data.h"

#define NOW std::chrono::system_clock::now().time_since_epoch().count()
typedef std::pair<unsigned int, unsigned int> edge_t;
typedef std::vector<edge_t> edge_vec_t;

unsigned int full_contraction(unsigned int V, edge_vec_t E){
    while(V > 2){
        std::default_random_engine gen_engine(NOW);
        std::uniform_int_distribution<int> dist(0, E.size() - 1);

        unsigned int chosen = dist(gen_engine);
        edge_t edge = E[chosen];
        unsigned int u = edge.first;
        unsigned int v = edge.second;

        edge_vec_t newE;
        for(auto & e : E){
            if(e.second == v){
                e.second = u;
            } else if(e.first == v){
                e.first = u;
            }

            if(e.first != e.second){
                newE.push_back(e);
            }
        }

        E = newE;
        --V;
    }

    return E.size();
}

#endif //ALGADVHW3_FULL_CONTRACTION_H
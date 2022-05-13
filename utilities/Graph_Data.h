//
// Created by Enrico on 06/06/2020.
//

#ifndef ALGADVHW3_GRAPH_DATA_H
#define ALGADVHW3_GRAPH_DATA_H

#include <utility>
#include <vector>
typedef std::vector<std::pair<unsigned int, unsigned int>> edge_vec_t;

class Graph_Data{
private:
    edge_vec_t edges;
    unsigned int n_vec;
    unsigned int solution;
public:
    Graph_Data(edge_vec_t , unsigned int, unsigned int);
    [[nodiscard]] edge_vec_t getEdges() const;
    [[nodiscard]] unsigned int getNVec() const;
    [[nodiscard]] unsigned int getSolution() const;
};

Graph_Data::Graph_Data(edge_vec_t  e, unsigned int v, unsigned int s) : edges(std::move(e)), n_vec(v), solution(s){}

edge_vec_t Graph_Data::getEdges() const {
    return edges;
}

unsigned int Graph_Data::getNVec() const {
    return n_vec;
}

unsigned int Graph_Data::getSolution() const {
    return solution;
}

#endif //ALGADVHW3_GRAPH_DATA_H

//
// Created by Enrico on 06/06/2020.
//

#ifndef ALGADVHW3_PARSER_H
#define ALGADVHW3_PARSER_H

#include <filesystem>
#include <fstream>
#include <sstream>
#include "Graph_Data.h"

class Parser{
public:
    static Graph_Data parse(const std::filesystem::path&, const std::filesystem::path&);
};

Graph_Data Parser::parse(const std::filesystem::path &f_name, const std::filesystem::path &o_name) {
    std::ifstream ifs (f_name, std::ifstream::in);
    std::ifstream ift (o_name, std::ifstream::in);
    std::vector<std::pair<unsigned int, unsigned int>> edges;
    unsigned int n_vec = 0;
    unsigned int sol = 0;

    if(ifs.good() && ift.good()){
        std::string d_line;

        while(std::getline(ifs, d_line)){
            std::stringstream sstream(d_line);
            unsigned int u;
            unsigned int v;

            sstream >> u;
            while(sstream >> v){
                if(u < v)
                    edges.emplace_back(u, v);
            }
            ++ n_vec;
        }

        std::getline(ift, d_line);
        std::stringstream solstream(d_line);
        solstream >> sol;
    }

    return Graph_Data(edges, n_vec, sol);
}

#endif //ALGADVHW3_PARSER_H

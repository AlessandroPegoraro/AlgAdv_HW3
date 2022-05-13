#include <iostream>
#include "utilities/Parser.h"
#include "algorithms/karger.h"
#include "algorithms/karger_timeout.h"
#include "algorithms/karger_early_stop.h"

int main() {
    //IF YOU WANT TO CHECK ONLY ONE GRAPH YOU CAN USE THIS COMMENTED SCRIPT
    /*
    std::string input_f = "..\\dataset\\input\\input_random_1_6.txt";
    std::string o_path = "..\\dataset\\output\\output_random_1_6.txt";

    Graph_Data graph = Parser::parse(input_f, o_path);
    unsigned int response_normal = karger(graph, 1);
    unsigned int response_timeout = karger_timeout(graph, 1);
    unsigned int response_early_stop = karger_early_stop(graph, 1);

    std::cout << "GRAPH : " << input_f << " EXPECTED SOLUTION : " << graph.getSolution() << std::endl;
    std::cout << "NORMAL EXCECUTION : " << response_normal << std::endl;
    std::cout << "TIMEOUT           : " << response_timeout << std::endl;
    std::cout << "EARLY STOPPING    : " << response_early_stop << std::endl;
    std::cout << std::endl;
    */

    //IF YOU WANT TO CHECK ALL THE GRAPH IN THE DATASET YOU CAN USE THIS SCRIPT
    std::string i_path = "..\\dataset\\input";
    std::string o_path = "..\\dataset\\output";
    auto input_f = begin(std::filesystem::directory_iterator(i_path));
    auto output_f = begin(std::filesystem::directory_iterator(o_path));

    while(input_f != end(std::filesystem::directory_iterator(i_path))) {
        Graph_Data graph = Parser::parse(*input_f, *output_f);
        unsigned int response_normal = karger(graph, 1);
        unsigned int response_timeout = karger_timeout(graph, 1);
        unsigned int response_early_stop = karger_early_stop(graph, 1);

        std::cout << "GRAPH : " << input_f->path() << " EXPECTED SOLUTION : " << graph.getSolution() << std::endl;
        std::cout << "NORMAL EXCECUTION : " << response_normal << std::endl;
        std::cout << "TIMEOUT           : " << response_timeout << std::endl;
        std::cout << "EARLY STOPPING    : " << response_early_stop << std::endl;
        std::cout << std::endl;
        ++input_f;
        ++output_f;
    }

    return 0;
}
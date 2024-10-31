#include <array>
#include <cstdint>
#include <cstdio>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "graph.h"
#include "gets.h"
#include <fstream>
std::array<std::string, 4> msg = {
                                "1. Input graph",
                                "2. Print matrix",
                                "3. Convert graph to dot format",
                                "4. Convert graph to dot format with a given path"
                                };

void print_msg(){
        for(auto &i : msg) std::cout << i << std::endl;
}

using namespace Graph;

int main(){
        graph a;
        std::string dot;
        std::vector<graph_matrix_element> path;
        while(true){
                print_msg();
                try{
                        std::cout << ">>>";
                        int8_t menu_choice = gets::getNum<int8_t>();
                        switch (menu_choice) {
                                case '1':
                                        clear_graph(a);
                                        full_graph(a);
                                break;
                                case '2':
                                        Print_matrix(a.matrix);
                                break;
                                case '3':
                                        {
                                                std::ofstream in {"graph.gv"};
                                                if(!in) throw std::runtime_error("Failed to open file");
                                                dot = convert_graph_to_dot(a);
                                                in << dot;
                                                in.close();
                                        }
                                break;
                                case '4':
                                        {
                                                std::ofstream in {"graph.gv"};
                                                if(!in) throw std::runtime_error("Failed to open file");
                                                full_path(path);
                                                dot = convert_graph_to_dot_with_path(a, path);
                                                in << dot;
                                                in.close();
                                        }
                                break;
                                default:
                                        std::cout << "Err input\n";
                                break;
                        }  
                }
                catch(const std::exception &e){
                        std::cerr << e.what() <<std::endl;
                        return 1;
                }
        }
}
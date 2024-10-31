#include "graph.h"
#include "gets.h"
#include <vector>
namespace Graph {

        void Print_matrix(std::vector<std::vector<graph_matrix_element>> &matrix){
                for(size_t i(0); i < matrix.size(); ++i){
                        std::cout << '\n';
                        for(size_t j(0); j < matrix.size(); ++j){
                                if(j != 0) std::cout << ' ';
                                std::cout << matrix[i][j];
                        }
                }
                std::cout << std::endl;
        }

        void clear_graph(graph &g){
                for(auto i : g.matrix){
                        i.clear();
                }
                g.matrix.clear();
        }

        using namespace gets;
        void full_path(std::vector<graph_matrix_element>&path){
                if(!path.empty()) path.clear();
                std::cout << "Enter num of vertex" << std::endl;
                size_t num = getNum<size_t>();
                path.resize(num);
                for(size_t i(0); i < num; ++i) path[i] = getNum<graph_matrix_element>();
        }

        void resize_graph(graph &gr){
                gr.matrix.resize(gr.size);
                for(size_t i(0); i < gr.size; ++i) gr.matrix[i].resize(gr.size);
        }

        void full_graph(graph &graph){
                std::cout << "Enter num of vertex" <<std::endl;
                graph.size = getNum<size_t>();
                resize_graph(graph);
                for(size_t i(0); i < graph.size - 1; ++i){
                        std::cout << "Enter dependent vertices of vertex №" << i + 1 << std::endl;
                        for(size_t j = i + 1; j < graph.size; ++j){
                                std::cout << "For " << j + 1 << " vertex:" << std::endl;
                                graph_matrix_element num = getNum<size_t>(0, 1);
                                graph.matrix[i][j] = num;
                                graph.matrix[j][i] = num;
                        }
                }
        }

        std::string convert_graph_to_dot(graph &graph){
                std::string res;
                res += "graph graphname {\n";
                for(size_t i(0); i < graph.size - 1; ++i){
                        for(size_t j(i + 1); j < graph.size; ++j){
                                res += '\t';
                                res += char(i + 97);
                                if(graph.matrix[i][j] == 1){
                                        res += " -- ";
                                        res += char(j + 97);
                                }
                                res += ";\n";
                        }
                }
                res += "}\n";
                return res;
        }

        std::string convert_graph_to_dot_with_path(graph &graph, std::vector<graph_matrix_element>&path){
                std::string res = convert_graph_to_dot(graph);
                return res;
        }

}
#ifndef GRAPH_H_
#define GRAPH_H_

#include <cstdint>
#include <string>
#include <vector>
namespace Graph{
        using graph_matrix_element = int16_t;
        struct graph{
                std::vector<std::vector<graph_matrix_element>> matrix;
                size_t size = 0;
        };

        void clear_graph(graph &g);
        void Print_matrix(std::vector<std::vector<graph_matrix_element>> &matrix);
        void full_path(std::vector<graph_matrix_element>&);
        void full_graph(graph &);
        std::string convert_graph_to_dot(graph &);
        std::string convert_graph_to_dot_with_path(graph &, std::vector<graph_matrix_element>&);
}
#endif

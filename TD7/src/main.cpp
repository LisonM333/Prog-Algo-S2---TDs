#include <iostream>
#include "graphe.hpp"

int main(){
    std::vector<std::vector<float>> adjacency_matrix {
        {0,1,0,0,2},
        {0,0,2,4,0},
        {0,0,0,1,0},
        {0,0,0,0,6},
        {0,0,0,0,0}
    };
    
    //Graph::WeightedGraph graph{
    //    {
    //        {0, {{1, 1.0f}, {4, 2.0f}}},
    //        {1, {{2, 2.0f}, {3, 4.0f}}},
    //        {2, {{3, 1.0f}}},
    //        {3, {{4, 6.0f}}},
    //        {4, {}},
    //    },
    //};
    
    Graph::WeightedGraph graph_fait_main{};
    graph_fait_main.add_vertex(0);
    graph_fait_main.add_vertex(1);
    graph_fait_main.add_vertex(2);
    graph_fait_main.add_vertex(3);
    graph_fait_main.add_vertex(4);
    graph_fait_main.add_directed_edge(0,1,1.0f);
    graph_fait_main.add_directed_edge(0,4,2.0f);
    graph_fait_main.add_directed_edge(1,2,2.0f);
    graph_fait_main.add_directed_edge(1,3,4.0f);
    graph_fait_main.add_directed_edge(2,3,1.0f);
    graph_fait_main.add_directed_edge(3,4,6.0f);

    std::cout << std::boolalpha;
    //std::cout << (graph == graph_fait_main)<< std::endl ;
    std::cout << (graph_fait_main == Graph::build_from_adjacency_matrix(adjacency_matrix)) << std::endl ;
    return 0;
}
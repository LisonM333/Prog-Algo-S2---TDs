#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "graphe.hpp"

namespace Graph {

    void WeightedGraph::add_vertex(int const id){
        auto it {adjacency_list.find(id)}; 
        if (it == adjacency_list.end()){
            std::vector<WeightedGraphEdge> pts_adj {};
            adjacency_list.insert({id,pts_adj});
        }
    }

    void WeightedGraph::add_directed_edge(int const from, int const to, float const weight /*= 1.0f*/){
        add_vertex(from);
        add_vertex(to);
        for (auto& i : adjacency_list){
            if(i.first == from){
                WeightedGraphEdge arrive {to , weight};
                i.second.push_back(arrive);
                break;
            }
        }   
    }

    void WeightedGraph::add_undirected_edge(int const from, int const to, float const weight /*= 1.0f*/){
        // add_vertex(from);
        // add_vertex(to);
        // bool from_fait{false};
        // bool to_fait{false};
        // for (auto& i : adjacency_list){
        //     if(i.first == from){
        //         WeightedGraphEdge arrive {to , weight};
        //         i.second.push_back(arrive);
        //         from_fait = true;
        //     }
        //     if(i.first == to){
        //         WeightedGraphEdge depart {from , weight};
        //         i.second.push_back(depart);
        //         to_fait = true;
        //     }
        //     if (from_fait && to_fait){
        //         break;
        //     }
        // }
        add_directed_edge(from,to,weight);
        add_directed_edge(to,from,weight);  
    }

    WeightedGraph build_from_adjacency_matrix(std::vector<std::vector<float>> const& adjacency_matrix){
        WeightedGraph graphe{};
        std::size_t nb_pts {adjacency_matrix.size()};
        for (int i{0}; i<static_cast<int>(nb_pts); i++){ //i : la ligne / from
            for(int j{0}; j<static_cast<int>(nb_pts); j++){ //j : la colonne / to
                if (adjacency_matrix[i][j]!=0){
                    graphe.add_directed_edge(i,j,adjacency_matrix[i][j]);
                }
            }
        }
        return graphe;
    }

}
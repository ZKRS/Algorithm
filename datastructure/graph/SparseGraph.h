//
// Created by wangqing on 2018.3.22.
//

#ifndef GRAPH_SPARSE_H
#define GRAPH_SPARSE_H

#include <iostream>
#include <vector>

using namespace std;

template<typename Weight>

class SparseGraph {
private:
    int edge_num, node_num;
    bool directed;
    vector<vector<int>> g;


public:
    SparseGraph(int edge_num, bool directed) {
        this->directed = directed;
        this->edge_num = edge_num;
        this->node_num = 0;
    }


    ~SparseGraph() {}

};

#endif //GRAPH_SPARSE_H

//
// Created by wangqing on 2018.3.22.
//

#ifndef GRAPH_SPARSE_H
#define GRAPH_SPARSE_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/**
 * 无权稀疏图 边数很少
 * 使用邻接表存储
 *
 * @tparam Weight
 */
class SparseGraph {
private:
    int edge_num, node_num;
    bool directed;
    vector<vector<int>> g;


public:
    SparseGraph(int node_num, bool directed) {
        assert(node_num >= 0);
        this->directed = directed;
        this->node_num = node_num;
        this->edge_num = 0;
        g = vector<vector<int>>(node_num, vector<int>()); // 邻接表

    }


    ~SparseGraph() {}

    void addEdge(int v, int w) {
        assert(v >= 0 && v < node_num);

        if (hasEdge(v, w)) return;

        g[v].push_back(w);

        if (v != w && !directed) {
            g[w].push_back(v);
        }

        edge_num++;
    }

    int nodeNum() { return node_num; }

    int edgeNum() { return edge_num; }

    bool hasEdge(int v, int w) {
        for (int i = 0; i < g[v].size(); i++) {
            if (g[v][i] == w) return true;
        }
        return false;
    }

    void show() {
        for (int i = 0; i < node_num; i++) {
            cout << "vertex " << i << ":\t";
            for (int j = 0; j < g[i].size(); j++)
                cout << g[i][j] << "\t"; // \t水平制表符

            cout << endl;
        }
    }

    class Iterator { // 邻接表某结点的相邻结点迭代器
    private:
        SparseGraph &G;
        int v;
        int index;

    public:
        Iterator(SparseGraph &graph, int v) : G(graph) {
            this->v = v;
            this->index = 0;
        }

        int begin() { // 返回与结点v相邻的第一个结点编号
            index = 0;
            if (G.g[v].size()) return G.g[v][index];

            return -1;
        }

        int next() { // 返回与结点v相邻的下一个结点编号
            index++;
            if (index < G.g[v].size())
                return G.g[v][index];

            return -1; // 没有顶点和v相连
        }

        bool end() { // 返回index是否已经到达最后
            return index >= G.g[v].size();
        }
    };
};

#endif //GRAPH_SPARSE_H

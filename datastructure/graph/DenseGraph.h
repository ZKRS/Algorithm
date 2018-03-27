//
// Created by wangqing on 2018.3.22.
//

#ifndef GRAPH_DENSEGRAPH_H
#define GRAPH_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
 * 无权稠密图: 边很多
 * 使用邻接矩阵存储
 * 空间复杂度 O(nodeNum ^ 2);
 */

class DenseGraph {


private:


public:
    int node_num, edge_num;
    bool directed;
    vector<vector<bool>> g;

    DenseGraph(int node_num, bool directed) {
        assert(node_num >= 0);
        this->node_num = node_num;
        this->directed = directed;
        this->edge_num = 0;
        g = vector<vector<bool>>(node_num, vector<bool>(node_num, false));
    }

    bool hasEdge(int v, int w) {
        return g[v][w];
    }

    void addEdge(int v, int w) {
//        assert(v >= 0 && v < node_num);
//        assert(w >= 0 && w < node_num);

        if (hasEdge(v, w)) return;

        g[v][w] = true;
        if (!directed) g[v][w] = true;
        edge_num++;
    }

    int edgeNum() { return edge_num; }

    int nodeNum() { return node_num; }

    void show() {
        for (int i = 0; i < node_num; i++) {
            for (int j = 0; j < node_num; j++)
                cout << g[i][j] << "\t";

            cout << endl;
        }

    }

    class Iterator { //
    private:
        int v;
        DenseGraph &G;
        int index;
    public:

        Iterator(DenseGraph &graph, int v) : G(graph) {
            this->v = v;
            this->index = -1;
        }

        int begin() { // 返回邻接矩阵g[v][first]存在的边的编号
            index = -1;
            return next();
        }

        int next() { // 返回与结点v相邻的下一个顶点
            for (index += 1; index < G.edgeNum(); index++) {
                if (G.g[v][index]) return index; // index和顶点编号一一对应
            }

            return -1;
        }

        bool end() {
            return index >= G.edgeNum();
        }

    };
};

#endif //GRAPH_DENSEGRAPH_H

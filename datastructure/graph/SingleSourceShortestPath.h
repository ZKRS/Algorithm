//
// Created by wangqing on 2018.3.28.
//

#ifndef GRAPH_SINGLESOURCESHORTESTPATH_H
#define GRAPH_SINGLESOURCESHORTESTPATH_H

/**
 * 邻接表 存储 图
 * 优先队列 存储 源点到当前与S集邻接结点的路径值和结点编号 make_pair(value, node)
 * 或者用最小索引堆 存储 原点到当前与S集邻接结点编号(构建是按照dis[k]大小构造的)
 *
 * 时间复杂度 O((E+V)logV)
 *
 *
 * 1.   每次取优先队列中最小值对应的得到结点编号u, 并把该结点设置为进入S集标志
 *
 * 2.   判断u的相邻结点k是否在S集中, 不是则更新该结点u的相邻结点k的dis[k]值 (k为该结点的相邻结点的编号)
 *          更新步骤: 如果dis[u] + value < dis[k], 则 dis[k] = dis[u] + value;
 *                  并把k结点放入优先队列中, 并把结点k设置为已在队列标志
 *
 * 3.   反复执行, 直至优先队列为空
 *
 *
 * 4.   最后输出dis[]
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


#define MAX 10000
#define UNVISITED 0
#define ALREADY_IN_QUEUE 1
#define ALREADY_POP 2
#define INF 1000000

using namespace std;

/**
 *
 *
 * 时间复杂度: O((E+V)logV)
 *
 * E:\wangqingAlgorithm\datastructure\graph_test\cmake-build-debug\graph_test.exe
    测试数据:
    5
    0 3 2 3 3 1 1 2
    1 2 0 2 3 4
    2 3 0 3 3 1 4 1
    3 4 2 1 0 1 1 4 4 3
    4 2 2 1 3 3

    运行结果:
    0 : 0
    1 : 2
    2 : 2
    3 : 1
    4 : 3

    Process finished with exit code 0

 */
struct cmp {
    bool operator()(const pair<int, int> a, const pair<int, int> b) {
        return a.second > b.second;
    }
};


int dijkstra() {
    int n; // number of nodes
    int v; // order number of each node
    int adjacency_number; // adjcacency number of each node
    vector<pair<int, int> > g[MAX]; // first: order number of node  second: weight of edge

    cin >> n;

    // input graph
    for (int i = 0; i < n; i++) {
        cin >> v >> adjacency_number;
        for (int j = 0; j < adjacency_number; j++) {
            int u, weight;
            cin >> u >> weight;
            g[v].emplace_back(make_pair(u, weight));
        }
    }

    vector<int> dis(n, INF); // save distance from star node to other nodes
    vector<int> statusOfNode(n, UNVISITED);

    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q; // first: order number of node   second: min value of edge

    // initial start node
    dis[0] = 0;
    q.push(make_pair(0, 0));
    statusOfNode[0] = ALREADY_IN_QUEUE;


    // handle priority_queue
    while (!q.empty()) {
        pair<int, int> node = q.top();
        int nodeV = node.first;
        int nodeValue = node.second;

        q.pop();
        statusOfNode[nodeV] = ALREADY_POP;


        for (int i = 0; i < g[nodeV].size(); i++) {

            pair<int, int> adjNode = g[nodeV][i];
            int adjNodeV = adjNode.first;
            int adjNodeWeight = adjNode.second;

            if (statusOfNode[adjNodeV] == ALREADY_POP) continue;

            if (dis[adjNodeV] > dis[nodeV] + adjNodeWeight) {
                dis[adjNodeV] = dis[nodeV] + adjNodeWeight;
                q.push(make_pair(adjNodeV, dis[adjNodeV]));
                statusOfNode[adjNodeV] = ALREADY_IN_QUEUE;
            }

        }
    }


    for (int j = 0; j < n; j++)
        cout << j << " : " << dis[j] << endl;


    return 0;

}

#endif //GRAPH_SINGLESOURCESHORTESTPATH_H

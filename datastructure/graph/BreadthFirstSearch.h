//
// Created by wangqing on 2018.3.27.
//

#ifndef GRAPH_BREADTHFIRSTSEARCH_H
#define GRAPH_BREADTHFIRSTSEARCH_H

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * 无权图
 *
 * 广度优先遍历
     * 实例: 求无权图的最短路径
 *
 * 求某个结点距离其他所有结点的最短路径
     * 第一行输入顶点数n
     * 接下来n行输入u k v1 v2 ... vk
     * u为顶点编号, k为顶点u的度, v为u的相邻结点
     *
     * distance[u] = k ; 该节点距离顶点u的距离为k
 *
 *
 * 如果用邻接矩阵实现广度搜索, 时间复杂度O(V^2)
 * 如果用邻接表实现广度搜索, 时间复杂度O(V+E)
 */

vector<vector<bool>> g;

void bfs() {
    unsigned n, v, k; // 节点数
    cin >> n;

    g = vector<vector<bool>>(n, vector<bool>(n, false)); // 开辟n*n的矩阵, 默认都不相连


    for (int i = 0; i < n; i++) { // 接受数据输入
        cin >> v;
        cin >> k;
        for (int j = 0; j < k; j++) {
            g[v][j] = true;
        }
    }


}

#endif //GRAPH_BREADTHFIRSTSEARCH_H

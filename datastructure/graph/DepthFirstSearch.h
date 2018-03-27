//
// Created by wangqing on 2018.3.27.
//

#ifndef GRAPH_DEPTHFIRSTSEARCH_H
#define GRAPH_DEPTHFIRSTSEARCH_H

#include <iostream>
#include <vector>
#include <stack>

#define UNVISITED 0
#define ALREADY_IN_STACK 1
#define ALREADY_POP_FROM_STACK 2

using namespace std;

static const int WHITE = 0;
vector<int> node_status; // 记录结点访问状态
stack<int> s; // 暂存访问过的结点

void dfs() {

}


#endif //GRAPH_DEPTHFIRSTSEARCH_H

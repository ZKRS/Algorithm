#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"

using namespace std;


/**
 * 有向图, 有权, 无权
 * 无向图, 有权, 无权
 * @return
 */
int main() {
    string filename = "testG1.txt";
    SparseGraph g(13, false);
    ReadGraph<SparseGraph> readGraph1(g, filename);
    cout << "test G1 in Sparse Graph:" << endl;
    g.show();

    DenseGraph g2(13, false);
    ReadGraph<DenseGraph> readGraph2(g2, filename);
    cout << "test G1 in Dense Graph:" << endl;
    g2.show();


    cout << endl;
    return 0;
}
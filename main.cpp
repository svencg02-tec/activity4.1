#include <iostream>
#include <vector>
#include "UMatrixGraph.h"
#include "Ugraph.h"
#include <set>
#include <string>

using namespace std;

int main() {
    UMatrixGraph<string> graph(5);
    graph.addVertex("A");
    graph.addVertex("B");
    graph.addVertex("C");
    graph.addVertex("D");
    graph.addVertex("E");
    graph.addEdge("A", "B");
    graph.addEdge("A", "C");
    graph.addEdge("B", "D");
    graph.addEdge("C", "D");
    graph.addEdge("D", "E");
    graph.addEdge("E", "A");
    graph.addEdge("E", "B");
    cout << graph;
    graph.DFS("A", graph);
    //graph.BFS("A", graph);
    return 0;
}

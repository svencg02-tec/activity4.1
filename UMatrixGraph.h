#ifndef Umatrixgraph_h
#define Umatrixgraph_h

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include "Ugraph.h"
#include <stack>
#include <string>
#include <queue>

template <class Vertex>
class UMatrixGraph : public Ugraph<Vertex>{
private:
    int size, next;
    std::vector<Vertex> Vertexes;
    std::vector<std::vector<bool>> matrix;
    int indexOf(Vertex) const;

public:
    UMatrixGraph() : size(0), next(0) {};
    UMatrixGraph(int);


    std::vector<Vertex> getVertexes() const;
    std::set<Vertex> getNeighbors(Vertex) const;


    void addVertex(Vertex);
    void addEdge(Vertex, Vertex);

    std::vector<Vertex> DFS(Vertex, const UGraph<Vertex> *);
    std::vector<Vertex> BFS(Vertex, const Ugraph<Vertex>&) const;

    template <class T>
    friend std::ostream &operator<<(std::ostream&, const UMatrixGraph<T>&);
};


template <class Vertex>
UMatrixGraph<Vertex>::UMatrixGraph(int size) : size(size), next(0) {
    matrix.resize(size);
    for (int i = 0; i < size; i++) {
        matrix[i].resize(size);
    }
}

template <class Vertex>
std::vector<Vertex> UMatrixGraph<Vertex>::getVertexes() const {
    return Vertexes;
}

template <class Vertex>
std::set<Vertex> UMatrixGraph<Vertex>::getNeighbors(Vertex v) const {
    std::set<Vertex> neighbors;
    int index = indexOf(v);
    for (int i = 0; i < size; i++) {
        if (matrix[index][i]) {
            neighbors.insert(Vertexes[i]);
        }
    }
    return neighbors;
}

template <class Vertex>
void UMatrixGraph<Vertex>::addVertex(Vertex v) {
    Vertexes.push_back(v);
    next++;
}

template <class Vertex>
void UMatrixGraph<Vertex>::addEdge(Vertex v1, Vertex v2) {
    int index1 = indexOf(v1);
    int index2 = indexOf(v2);
    matrix[index1][index2] = true;
    matrix[index2][index1] = true;
}

template <class Vertex>
int UMatrixGraph<Vertex>::indexOf(Vertex v) const {
    for (int i = 0; i < size; i++) {
        if (Vertexes[i] == v) {
            return i;
        }
    }
    return -1;
}

template <class Vertex>
std::vector<Vertex> UMatrixGraph<Vertex>::DFS(Vertex start, const UGraph<Vertex> *graph){
  std::set<Vertex> visited;
  std::vector<Vertex> vertexes;
  std::stack<Vertex> pending;
  pending.push(start);

  while (!pending.empty())
  {
    Vertex current = pending.top();
    pending.pop();

    if (visited.find(current) == visited.end())
    {
      visited.insert(current);
      vertexes.push_back(current);
      std::set<Vertex> neighbours = graph->getNeighbours(current);

      for (auto neighbour : neighbours)
        pending.push(neighbour);
    }
  }

  return vertexes;
}

template <class Vertex>
std::vector<Vertex> UMatrixGraph<Vertex>::BFS(Vertex v, const Ugraph<Vertex>& g) const {
    std::vector<Vertex> visited;
    std::queue<Vertex> queue;
    queue.push(v);
    while (!queue.empty()) {
        Vertex current = queue.front();
        queue.pop();
        if (std::find(visited.begin(), visited.end(), current) == visited.end()) {
            visited.push_back(current);
            std::set<Vertex> neighbors = g.getNeighbors(current);
            for (Vertex n : neighbors) {
                queue.push(n);
            }
        }
    }
    return visited;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const UMatrixGraph<T> &g) {
    os << "Vertexes: ";
    for (T v : g.Vertexes) {
        os << v << " ";
    }
    os << std::endl;
    os << "Matrix: " << std::endl;
    for (int i = 0; i < g.size; i++) {
        for (int j = 0; j < g.size; j++) {
            os << g.matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

#endif
// -----------------------------------------------------------
#ifndef UGRAPH_H
#define UGRAPH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <set>

template <class Vertex>
class Ugraph
{
public:
    virtual void addVertex(Vertex) = 0;
    virtual void addEdge(Vertex, Vertex) = 0;
    virtual std::vector<Vertex> getVertexes() const = 0;
    virtual std::set<Vertex> getNeighbors(Vertex) const = 0;

};

#endif

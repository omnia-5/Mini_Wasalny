//
// Created by user on ٢٥/٠٥/٢٠٢٢.
//

#include "Vertex.h"


Vertex::Vertex()
{
    stateId = 0;
    stateName = "";
}

Vertex::Vertex(int id, string name)
{
    this->stateId = id;
    this->stateName = name;
}

void Vertex::setStateID(int id)
{
    stateId = id;
}

void Vertex::setStateName(string name)
{
    stateName = name;
}

int Vertex::getStateID()
{
    return stateId;
}

string Vertex::getStateName()
{
    return stateName;
}

vector<Edge> Vertex::getEdge()
{
    return edges;
}

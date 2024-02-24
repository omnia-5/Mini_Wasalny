//
// Created by user on ٢٥/٠٥/٢٠٢٢.
//

#include "Edge.h"
Edge::Edge()
{
    DestinationVertexID = 0;
    weight = 0;
}

Edge::Edge(int DestinationVertexID, int weight)
{
    this->DestinationVertexID = DestinationVertexID;
    this->weight = weight;
}

void Edge::setDestinationVertexID(int id)
{
    this->DestinationVertexID = id;
}

void Edge::setWieght(int w)
{
    this->weight = w;
}

int Edge::getDestinationVertexID()
{
    return DestinationVertexID;
}

int Edge::getWeight()
{
    return weight;
}

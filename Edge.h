//
// Created by user on ٢٥/٠٥/٢٠٢٢.
//

#ifndef MINIWASALNY_EDGE_H
#define MINIWASALNY_EDGE_H
#include <bits/stdc++.h>
using namespace std;

class Edge {
public:

    //dataMembers

    int DestinationVertexID;
    int weight;

    //Constractors
    Edge();
    Edge(int, int);

    //Functions
    void setDestinationVertexID(int);
    void setWieght(int);
    int getDestinationVertexID();
    int getWeight();
};


#endif //MINIWASALNY_EDGE_H

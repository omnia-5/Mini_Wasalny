//
// Created by user on ٢٥/٠٥/٢٠٢٢.
//

#ifndef MINIWASALNY_VERTEX_H
#define MINIWASALNY_VERTEX_H

#include <bits/stdc++.h>
#include "Edge.h"
using namespace std;
class Vertex {
public:

    //dataMembers
    int stateId;
    string stateName;
    vector<Edge> edges;

    //Constractors
    Vertex();
    Vertex(int, string);

    //Functions
    void setStateID(int);
    void setStateName(string);
    int getStateID();
    string getStateName();
    vector<Edge> getEdge();


};


#endif //MINIWASALNY_VERTEX_H

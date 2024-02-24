//
// Created by user on ٢٥/٠٥/٢٠٢٢.
//
#include <bits/stdc++.h>
#include "Vertex.h"
#include "Edge.h"
#include<queue>
#define el '\n'
#define oo 1000000000
#ifndef MINIWASALNY_GRAPH_H
#define MINIWASALNY_GRAPH_H


using namespace std;
const int N=100,inf=2e9;

class Graph {
public:

    //DataMembers
    vector<Vertex> vertices;
    bool visited[N]={ };
    int Floyd_Arr[100][100];
    int adj_matrix[100][100];
    int cunt=0;
    unordered_map<int, string>id;
    int graphid,weight;
    string type;
    //Graph
    void print();
    void delete_graph(char s[]);

    //For Vertex
    bool checkIfVertexExistByID(int);
    bool checkIfVertexExistByName(string);
    void AddVertex(Vertex &);
    void deleteVertexByID(int);
    void updateVertex(int,int, string);
    Vertex getVertexByID(int vid);
    string getName(int);
    int getid(string);

    //For Edge

    bool checkIfEdgeExistByID(int, int);
    void AddEdge(Vertex &, Vertex &, int);
    void deleteEdgeByID(int, int);
    void updateEdgeByID(int,int, int, int);
    void updateDirectedEdge(int,int, int, int);

    //For Dijkstra

    int dijkstra(int start,int destination);
    void printPath(int parent[],int j);

    //bonus

    void bellmanFord(int);
    void printArr(int ,int dist[], int n);

    //bonus

    void fill_matrix();
    void Floyed_Warchall(int i, int j);
    void Print_Floyd_Path(int Source, int Distination);
    void Input();

    Graph ReadFile(int);
    void WriteFile(int,char);
    void SaveFile(int);
    void updateFile(string checkwith,string newVal);
};


#endif //MINIWASALNY_GRAPH_H

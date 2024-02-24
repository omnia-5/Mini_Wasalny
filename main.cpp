#include <bits/stdc++.h>
#include "Edge.h"
#include"Edge.cpp"
#include "Vertex.h"
#include "Vertex.cpp"
#include "Graph.h"
#include "Graph.cpp"
#define el '\n'
using namespace std;


int main() {
    Graph g;
    Vertex v1;
    Vertex v2;

    int choise;
    string city;
    string city2;
    int weight;
    int numberOfVerteces;
    Vertex* arr;
    cout << "Press 1 to Load a Graph Or Press 2 to add New Graph -->  ";
    cin >> choise;
    if (choise == 1) {
        cout<<"Please Enter the ID of the Graph ";
        cin>>g.graphid;
        Graph g2;
        g=g.ReadFile(g.graphid);

        do {
            cout << "Press 2 to updata vertex " << el;
            cout << "Press 3 to updata Edge " << el;
            cout << "Press 4 to delete all graph " << el;
            cout << "Press 5 to save graph " << el;
            cout << "Press 6 to Print All Graph "<<el;
            cout << "Press 7 to calculate the shortest Path " << el;
            cout << "Press 8 to Exit " << el;
            cin >> choise;
            if (choise == 2) {
                cout << "To modify press 1\n";
                cout << "To add press 2\n";
                cout << "To delete press 3\n";
                int c;
                cin >> c;
                if(c==1) {
                    cout << "Enter the name Of old city : ";
                    cin >> city;
                    cout << "Enter the name Of new city : ";
                    cin >> city2;
                    g.updateVertex(c,g.getid(city), city2);
                }else if(c==2){
                    cout << "Enter Number of cities --> ";
                    cin >> numberOfVerteces;
                    arr = new Vertex[numberOfVerteces];
                    for (int i = 0; i < numberOfVerteces; i++) {
                        cout << "The Name of city : ";
                        cin >> city;
                        arr[i].setStateName(city);
                        arr[i].setStateID(i);
                    }
                    for (int j = 0; j <numberOfVerteces; j++) {
                        g.AddVertex(arr[j]);
                    }
                }
                else
                {
                    cout << "Enter the name Of city : ";
                    cin >> city;
                    g.updateVertex(c,g.getid(city), city2);
                }


            }
            else if (choise == 3) {
                cout << "To modify press 1\n";
                cout << "To add press 2\n";
                cout << "To delete press 3\n";
                int c;
                cin >> c;
                if(c==2){
                    cout << "city 1 --> city2 --> distance : ";
                    cin >> city >> city2 >> weight;
                    v1.setStateName(city);
                    v1.setStateID(g.getid(city));

                    v2.setStateName(city2);
                    v2.setStateID(g.getid(city2));

                    g.AddEdge(v1, v2, weight);

                }else {
                    cout << "Enter the name of cityFrom : ";
                    cin >> city;
                    cout << "Enter the name of city to : ";
                    cin >> city2;
                    cout << "Enter the distance between two cities : ";
                    cin >> weight;
                    g.updateDirectedEdge(c, g.getid(city), g.getid(city2), weight);

                }
            }
            else if (choise == 4) {

                cout<<"Enter the file name as'CmakeList+id.txt'\n";
                char c[1000];
                cin>>c;
                g.delete_graph(c);
                cout << "The Graph Deleted Successfully"<<el;
            }
            else if (choise == 5) {

                g.SaveFile(g.graphid);
            }
            else if (choise == 6) {

                g.print();
            }
            else if (choise == 7) {
                cout << "Press 1 to choose Dijkstra " << endl;
                cout << "Press 2 to choose Bellman ford " << endl;
                cout << "Press 3 to choose Floyed warchall " << endl;
                cin >> choise;
                if (choise == 1) {
                    cout << "Enter Beginning city : ";
                    cin >> city;
                    cout << "Enter Ending city : ";
                    cin >> city2;
                    cout<<g.dijkstra(g.getid(city),g.getid(city2))<<el;
                }
                else if (choise == 2) {
                    cout << "Enter the Beginning city : ";
                    cin >> city;
                    g.bellmanFord(g.getid(city));
                }
                else if (choise == 3) {
                    cout << "Enter Beginning city : ";
                    cin >> city;
                    cout << "Enter Ending city : ";
                    cin >> city2;
                    g.Input();
                    g.Floyed_Warchall(g.getid(city),g.getid(city2));
                }
            }
        } while (choise != 8);
    }
    else if (choise == 2) {
        cout<<"please Enter the ID of The new Graph ";
        cin>>g.graphid;
        cout << "Press 3 to add directed graph Or Press 4 to add undirected graph --> ";
        cin >> choise;
        if (choise == 3) {
            do {
                cout << "Press 5 to add vertex " << endl;
                cout << "Press 6 to add Edge " << endl;
                cout << "Press 7 to updata vertex " << endl;
                cout << "Press 8 to updata Edge " << endl;
                cout << "Press 9 to delete all graph " << endl;
                cout << "Press 10 to save graph " << endl;
                cout << "Press 11 to Print All Graph "<<endl;
                cout << "Press 12 to calculate the shortest Path " << endl;
                cout << "Press 13 to Exit " << endl;
                cin >> choise;
                if (choise == 5) {
                    cout << "Enter Number of cities --> ";
                    cin >> numberOfVerteces;
                    arr = new Vertex[numberOfVerteces];
                    for (int i = 0; i < numberOfVerteces; i++) {
                        cout << "The Name of city : ";
                        cin >> city;
                        arr[i].setStateName(city);
                        arr[i].setStateID(i);
                    }
                    for (int j = 0; j <numberOfVerteces; j++) {
                        g.AddVertex(arr[j]);
                    }

                }
                else if (choise == 6) {
                    cout << "city 1 --> city2 --> distance : ";
                    cin >> city >> city2 >> weight;
                    v1.setStateName(city);
                    v1.setStateID(g.getid(city));

                    v2.setStateName(city2);
                    v2.setStateID(g.getid(city2));

                    g.AddEdge(v1, v2, weight);
                }
                else if (choise == 7) {


                    int c;
                    cin >> c;
                    if(c==1) {
                        cout << "Enter the name Of old city : ";
                        cin >> city;
                        cout << "Enter the name Of new city : ";
                        cin >> city2;
                        g.updateVertex(c,g.getid(city), city2);
                    }else if (c==2){
                        cout << "Enter Number of cities --> ";
                        cin >> numberOfVerteces;
                        arr = new Vertex[numberOfVerteces];
                        for (int i = 0; i < numberOfVerteces; i++) {
                            cout << "The Name of city : ";
                            cin >> city;
                            arr[i].setStateName(city);
                            arr[i].setStateID(i);
                        }
                        for (int j = 0; j <numberOfVerteces; j++) {
                            g.AddVertex(arr[j]);
                        }
                    }
                    else
                    {
                        cout << "Enter the name Of city : ";
                        cin >> city;
                        g.updateVertex(c,g.getid(city), city2);
                    }

                }
                else if (choise == 8) {
                    cout << "To modify press 1\n";
                    cout << "To add press 2\n";
                    cout << "To delete press 3\n";
                    int c;
                    cin >> c;
                    if(c==2){
                        cout << "city 1 --> city2 --> distance : ";
                        cin >> city >> city2 >> weight;

                        v1.setStateName(city);
                        v1.setStateID(g.getid(city));

                        v2.setStateName(city2);
                        v2.setStateID(g.getid(city2));
                        g.AddEdge(v1, v2, weight);
                    }else {
                        cout << "Enter the name of cityFrom : ";
                        cin >> city;
                        cout << "Enter the name of city to : ";
                        cin >> city2;
                        cout << "Enter the distance between two cities : ";
                        cin >> weight;
                        g.updateDirectedEdge(c, g.getid(city), g.getid(city2), weight);
                    }
                }
                else if (choise == 9) {
                    cout<<"Enter the file name as'CmakeList+id.txt'\n";
                    char c[1000];
                    cin>>c;
                    g.delete_graph(c);
                    cout << "The Graph Deleted Successfully"<<el;
                }
                else if (choise == 10) {

                    g.WriteFile(g.graphid,'d');
                    g.SaveFile(g.graphid);
                }
                else if (choise == 11) {

                    g.print();
                }
                else if (choise == 12) {
                    cout << "Press 1 to choose Dijkstra " << endl;
                    cout << "Press 2 to choose Bellman ford " << endl;
                    cout << "Press 3 to choose Floyed warchall " << endl;
                    cin >> choise;
                    if (choise == 1) {
                        cout << "Enter Beginning city : ";
                        cin >> city;
                        cout << "Enter Ending city : ";
                        cin >> city2;
                        cout<<g.dijkstra(g.getid(city), g.getid(city2))<<el;
                    }
                    else if (choise == 2) {
                        cout << "Enter the Beginning city : ";
                        cin >> city;
                        g.bellmanFord(g.getid(city));
                    }
                    else if (choise == 3) {
                        cout << "Enter Beginning city : ";
                        cin >> city;
                        cout << "Enter Ending city : ";
                        cin >> city2;
                        g.Input();
                        g.Floyed_Warchall(g.getid(city),g.getid(city2));
                    }
                }


            } while (choise != 13);
        }
        else if (choise == 4) {
            do {
                cout << "Press 5 to add vertex " << endl;
                cout << "Press 6 to add Edge " << endl;
                cout << "Press 7 to updata vertex " << endl;
                cout << "Press 8 to updata Edge " << endl;
                cout << "Press 9 to delete all graph " << endl;
                cout << "Press 10 to save graph " << endl;
                cout<<"Press 11 to Print all Graph "<<endl;
                cout << "Press 12 to calculate the shortest Path between two vertces " << endl;
                cout << "Press 13 to Exit " << endl;
                cin >> choise;
                if (choise == 5) {
                    cout << "Enter Number of cities --> ";
                    cin >> numberOfVerteces;
                    arr = new Vertex[numberOfVerteces];
                    for (int i = 0; i < numberOfVerteces; i++) {
                        cout << "The Name of city : ";
                        cin >> city;
                        arr[i].setStateName(city);
                        arr[i].setStateID(i);
                    }
                    for (int j = 0; j < numberOfVerteces; j++) {
                        g.AddVertex(arr[j]);
                    }

                }
                else if (choise == 6) {
                    cout << "city 1 --> city2 --> distance : ";
                    cin >> city >> city2 >> weight;

                    v1.setStateName(city);
                    v1.setStateID(g.getid(city));

                    v2.setStateName(city2);
                    v2.setStateID(g.getid(city2));
                    g.AddEdge(v1, v2, weight);
                    g.AddEdge(v2, v1, weight);
                }
                else if (choise == 7) {
                    cout << "To modify press 1\n";
                    cout << "To add press 2\n";
                    cout << "To delete press 3\n";
                    int c;
                    cin >> c;
                    if(c==1) {
                        cout << "Enter the name Of old city : ";
                        cin >> city;
                        cout << "Enter the name Of new city : ";
                        cin >> city2;
                        g.updateVertex(c,g.getid(city), city2);

                    }else if(c==2){
                        cout << "Enter Number of cities --> ";
                        cin >> numberOfVerteces;
                        arr = new Vertex[numberOfVerteces];
                        for (int i = 0; i < numberOfVerteces; i++) {
                            cout << "The Name of city : ";
                            cin >> city;
                            arr[i].setStateName(city);
                            arr[i].setStateID(i);
                        }
                        for (int j = 0; j < numberOfVerteces; j++) {
                            g.AddVertex(arr[j]);
                        }
                    }
                    else
                    {
                        cout << "Enter the name Of  city : ";
                        cin >> city;
                        g.updateVertex(c,g.getid(city), city2);

                    }
                }
                else if (choise == 8) {
                    cout << "To modify press 1\n";
                    cout << "To add press 2\n";
                    cout << "To delete press 3\n";
                    int c;
                    cin >> c;
                    if(c==2){
                        cout << "city 1 --> city2 --> distance : ";
                        cin >> city >> city2 >> weight;

                        v1.setStateName(city);
                        v1.setStateID(g.getid(city));

                        v2.setStateName(city2);
                        v2.setStateID(g.getid(city2));
                        g.AddEdge(v1, v2, weight);
                        g.AddEdge(v2, v1, weight);
                    }else {
                        cout << "Enter the name of city From : ";
                        cin >> city;
                        cout << "Enter the name of city To : ";
                        cin >> city2;
                        cout << "Enter the  distance between two cities : ";
                        cin >> weight;

                        g.updateEdgeByID(c, g.getid(city), g.getid(city2), weight);
                    }
                }
                else if (choise == 9) {
                    cout<<"Enter the file name as'CmakeList+id.txt'\n";
                    char c[1000];
                    cin>>c;
                    g.delete_graph(c);
                    cout << "The Graph Deleted Successfully";

                }
                else if (choise == 10) {

                    g.WriteFile(g.graphid,'u');
                    g.SaveFile(g.graphid);
                }
                else if (choise == 11) {
                    g.print();
                }
                else if (choise == 12) {
                    cout << "Press 1 to choose Dijkstra " << endl;
                    cout << "Press 2 to choose Bellman ford " << endl;
                    cout << "Press 3 to choose Floyed warchall " << endl;
                    cin >> choise;
                    if (choise == 1) {
                        cout << "Enter Beginning city : ";
                        cin >> city;
                        cout << "Enter Ending city : ";
                        cin >> city2;
                        cout<<g.dijkstra(g.getid(city),g.getid(city2))<<el;
                    }
                    else if (choise == 2) {
                        cout << "Enter the Beginning city : ";
                        cin >> city;
                        g.bellmanFord(g.getid(city));
                    }
                    else if (choise == 3) {
                        cout << "Enter Beginning city : ";
                        cin >> city;
                        cout << "Enter Ending city : ";
                        cin >> city2;
                        g.Input();
                        g.Floyed_Warchall(g.getid(city),g.getid(city2));
                    }
                }
            } while (choise != 13);
        }
    }
}


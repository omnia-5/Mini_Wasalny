//
// Created by user on ٢٥/٠٥/٢٠٢٢.
//

#include "Graph.h"
#include <fstream>
#include <bits/stdc++.h>
void Graph::print() {
    for (int i = 0; i < vertices.size(); i++) {
        cout << vertices.at(i).getStateName() << "-> ";
        cout << "[";
        for (auto it = vertices.at(i).edges.begin(); it != vertices.at(i).edges.end(); it++) {
            cout <<getName(it->getDestinationVertexID())<< "(" << it->getWeight() << ")";
            if(it<vertices.at(i).edges.end()-1){
                cout<<" ";
            }
        }
        cout << "]";
        cout << endl;

    }
}

//----------------For Vertex---------------

bool Graph::checkIfVertexExistByID(int id)
{
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).getStateID() == id) {
            return true;
        }
    }
    return false;
}

bool Graph::checkIfVertexExistByName(string name)
{
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).getStateName() == name) {
            return true;
        }
    }
    return false;
}

void Graph::AddVertex(Vertex & s) {
    bool Check = checkIfVertexExistByName(s.getStateName());
    if (Check==true) {
        cout << "City is Exist."<<endl;
    }
    else {
        vertices.push_back(s);

    }

}


void Graph::deleteVertexByID(int vid)
{
    if(!checkIfVertexExistByID(vid)){
        return;
    }
    for (int i = 0; i < vertices.size(); i++) {
        for (auto it = vertices.at(i).edges.begin(); it != vertices.at(i).edges.end(); it++) {
            if (it->getDestinationVertexID() == vid) {
                vertices.at(i).edges.erase(it);
                break;
            }
        }

    }
    vertices.erase(vertices.begin() + vid);
    cout << "Vertex Deleted Successfully" << endl;

}

void Graph::updateVertex(int c,int id, string NewName="")
{
    bool check = checkIfVertexExistByID(id);


    if (c == 1)
    {
        string w;
        if (check)
        {
            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices[i].getStateID() == id)
                {
                    w= getName(id);
                    vertices[i].setStateName(NewName);
                    break;
                }
            }
            char saving ;
            cout<<"Do you want to save changes to file? Y/N\n";
            cin>>saving;
            if(saving =='Y'||'y')
            {
                updateFile(w,NewName);
                SaveFile(graphid);
            }

            cout << "Successfully Updated\n";
        }
    }
        /* else if (c == 2)
         {
             Vertex v1;
             v1.setStateID(id);
             v1.setStateName(NewName);
             AddVertex(v1);
             cout << "Successfully Add the Country\n";
         }*/
    else if (c == 3)
    {
        //delete vertex
        if(check){
            deleteVertexByID(id);
            cout << "Successfully Deleted the Country \n";
        }

    }

}

Vertex Graph::getVertexByID(int vid) {
    Vertex temp;
    for (int i = 0; i < vertices.size(); i++) {
        temp = vertices[i];
        if (temp.getStateID() == vid) {
            return temp;
        }
    }
    return temp;
}

string Graph::getName(int id){
    for (int i = 0; i < vertices.size(); ++i) {
        if(vertices[i].getStateID()==id)
            return vertices[i].getStateName();
    }
}

int Graph::getid(string name) {
    for (int i = 0; i < vertices.size(); ++i) {
        if (vertices[i].getStateName() == name)
            return vertices[i].getStateID();
    }
}

//------------------For Edge--------------------

bool Graph::checkIfEdgeExistByID(int id1, int id2)
{
    Vertex v = getVertexByID(id1);
    vector < Edge > e;
    e = v.getEdge();
    for(auto it:e){
        if(it.getDestinationVertexID()==id2)
            return true;
    }
    return false;

}

void Graph::AddEdge(Vertex &s, Vertex &e, int weight) {

    bool check1 = checkIfVertexExistByName(s.getStateName());
    bool check2 = checkIfVertexExistByName(e.getStateName());
    if(s.getStateName()==e.getStateName()){
        cout<<"Can't Add path From the city and it self"<<el;
        return ;
    }
    this->weight=weight;
    bool check3 = checkIfEdgeExistByID(s.getStateID(),e.getStateID());
    if ((check1 && check2 )) {

        if (check3 == true) {
            cout << "Edge between " << s.getStateName() << " and " << e.getStateName() <<  " Already Exist" << endl;
        }
        else {

            for (int i = 0; i < vertices.size(); i++) {

                if ( vertices.at(i).getStateName() == s.getStateName()) {
                    Edge e1(e.getStateID(), weight);
                    vertices.at(i).edges.push_back(e1);
                }
            }

            cout << "Edge between " << s.getStateName() << " and " << e.getStateName() << " added Successfully" << endl;
        }
    }
    else {
        cout << "Invalid Vertex Name entered.";
    }

}

void Graph::deleteEdgeByID(int fromVertex, int toVertex)
{

    if(!checkIfEdgeExistByID(fromVertex, toVertex)){
        cout<<"there is no edge between 2 countries\n";
        return;
    }


    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i].getStateID() == fromVertex) {
            for (auto it = vertices[i].edges.begin();it != vertices.at(i).edges.end(); it++) {
                if (it->getDestinationVertexID() == toVertex) {
                    vertices.at(i).edges.erase(it);
                    cout<<"edge deleted \n";

                    break;
                }
            }
        }
    }


}

void Graph::updateEdgeByID(int c,int fromVertex, int toVertex, int newWeight)
{
    bool check=checkIfEdgeExistByID(fromVertex, toVertex);

    if (c == 1)
    {
        if (check)
        {
            int w;
            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices[i].getStateID() == fromVertex)
                {
                    for (int j = 0; j < vertices[i].edges.size(); i++)
                    {
                        if (vertices[i].edges[j].getDestinationVertexID() == toVertex)
                        {
                            vertices[i].edges[j].setWieght(newWeight);
                            break;
                        }
                    }
                }
                if (vertices[i].getStateID() == toVertex)
                {
                    for (int j = 0; j < vertices[i].edges.size(); i++)
                    {
                        if (vertices[i].edges[j].getDestinationVertexID() == fromVertex)
                        {
                            w=weight;
                            vertices[i].edges[j].setWieght(newWeight);
                            break;
                        }
                    }
                }
            }
            char saving ;
            cout<<"Do you want to save changes to file? Y/N\n";
            cin>>saving;
            if(saving =='Y'||'y')
            {
                updateFile(to_string(w),to_string(newWeight));
                SaveFile(graphid);
            }
            cout << "Successfully Updated\n";
        }
    }


    else if (c == 3)
    {

        deleteEdgeByID(fromVertex, toVertex);
        deleteEdgeByID(toVertex, fromVertex);
        cout << "Successfully Delete the Edge\n";

    }

}

void Graph::updateDirectedEdge(int c,int fromVertex, int toVertex, int newWeight)
{
    bool check = checkIfEdgeExistByID(fromVertex, toVertex);

    int w;
    if (c == 1)
    {
        if (check)
        {

            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices[i].getStateID() == fromVertex)
                {

                    for (int j = 0; j < vertices[i].edges.size(); i++)
                    {
                        if (vertices[i].edges[j].getDestinationVertexID() == toVertex)
                        {
                            w=weight;
                            vertices[i].edges[j].setWieght(newWeight);
                            break;
                        }
                    }
                }
            }
            char saving ;
            cout<<"Do you want to save changes to file? Y/N\n";
            cin>>saving;
            if(saving =='Y'||'y')
            {
                updateFile(to_string(w),to_string(newWeight));
                SaveFile(graphid);
            }
            cout << "Successfully Updated\n";
        }
    }

    else if (c == 3)
    {

        deleteEdgeByID(fromVertex, toVertex);
        cout << "Successfully Delete Edge\n";

    }
}

void Graph::delete_graph(char s[])
{
    for (int i = 0; i < vertices.size(); i++) {
        vertices.clear();
    }


    int status = remove(s);
    if(status==0)
        cout<<"\nFile Deleted Successfully!";
    else
        cout<<"\nError Occurred!";
    cout<<endl;


}

//--------------For Dijkstra------------------------

void Graph::printPath(int parent[],int j){
    if(parent[j]==-1){
        return;
    }
    printPath(parent,parent[j]);
    cout<<getName(j)<<' ';

};

int Graph::dijkstra(int start, int destination) {
    int parent[N]={ };
    memset(visited,false,sizeof(visited));
    memset(parent,-1,sizeof(parent));
    int dist[N]={ };
    for (int i = 0; i <N; i++)
        dist[i] = inf;
    priority_queue<pair<int,int>> q;
    q.push({0,start});
    dist[start]=0;
    while (!q.empty()) {
        int node = q.top().second; q.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (auto child : vertices[node].edges) {
            int childid = child.DestinationVertexID, weight = child.getWeight();
            if (dist[node]+weight < dist[childid]) {
                dist[childid] = dist[node]+weight;
                q.push({-dist[childid],childid});
                parent[childid]=node;

            }
        }
    }

    cout<<"The Cities Of The Shortest Path are : "<<el;
    cout<<getName(start)<<' ';
    printPath(parent,destination);
    cout<<'\n';
    cout<<"The Minimum Destination between Cities is : ";
    return dist[destination];
}

//----------------Bonus-------------

void Graph::printArr(int start,int dist[], int n)
{
    cout<<"City   Distance from Source "<<getName(start)<<el;

    for (int i = 0; i < n; ++i){
        cout<<getName(i)<<"\t\t"<<dist[i]<<el;
    }

}

void Graph::bellmanFord(int start) {
    int dist[N]={ };
    for (int i = 0; i <N; i++)
        dist[i] = inf;
    dist[start]=0;
    int parent[N]={ };
    for (int i = 0; i <vertices.size()-1 ; ++i) {
        memset(parent,-1,sizeof(parent));
        for(auto child:vertices[i].edges){
            int a,b,cost;
            a=i;
            b=child.DestinationVertexID;
            cost=child.weight;
            dist[b]=min(dist[b],dist[a]+cost);

        }
    }

    printArr(start,dist,vertices.size());



}

//----------------Bonus-------------

void Graph::Input()
{
    for (int i = 0; i < vertices.size(); ++i)
    {
        id[cunt++]=vertices[i].getStateName();
    }
}
void Graph::fill_matrix()
{
    for (int i = 0; i < vertices.size(); i++) // initializing the adjacency matrix with infinity except the self edges
    {
        for (int j = 0; j < vertices.size(); j++)
        {
            Floyd_Arr[i][j] = -1;          // Floyd_Arr Is used In Printing The Path
            if (i == j)adj_matrix[i][j] = 0;
            else
                adj_matrix[i][j] = oo;
        }
    }
    for (int i = 0; i < vertices.size(); i++)// filling up the adjacency matrix
    {
        for(auto j:vertices[i].edges){
            if (j.getWeight()< adj_matrix[i][j.DestinationVertexID])//Assigning The Least Value
                adj_matrix[i][j.DestinationVertexID] = j.weight;
        }

    }
}

void Graph::Print_Floyd_Path(int Source, int Distination)
{
    if (Floyd_Arr[Source][Distination] == -1)
    {
        cout << id[Source] << " " << id[Distination] << "\n";
        return;
    }
    Print_Floyd_Path(Source, Floyd_Arr[Source][Distination]);
    Print_Floyd_Path(Floyd_Arr[Source][Distination], Distination);
}

void Graph::Floyed_Warchall(int i, int j)
{
    // The Algorithm works on connected Graphs
    fill_matrix();
    for (int i = 0; i < vertices.size(); i++) // k Will Act As Intermediate node
        for (int j = 0; j < vertices.size(); j++)// i And j Traverse The Adjacency matrix
            for (int k = 0; k < vertices.size(); k++)
            {
                if (!id.count(i) || !id.count(j) || !id.count(k))continue;
                if (adj_matrix[i][k] + adj_matrix[k][j] < adj_matrix[i][j])
                {
                    adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j];
                    Floyd_Arr[i][j] = k;  // This Arr is For Printing The Path
                }

            }
    if (adj_matrix[i][j] == oo)
    {
        cout << "There's No Path Between " << id[i] << " And " << id[j] << "\n"; return;
    }
    cout << "The Cost Between " << id[i] << " And " << id[j] << " is " << adj_matrix[i][j] << "\n";
    Print_Floyd_Path(i, j);
}

Graph Graph::ReadFile(int ID){
    string source,dest,weight;
    string s="CMakeLists"+to_string(ID)+".txt";
    fstream myfile(s);

    string fileId;
    myfile>> fileId;
    graphid=stoi(fileId);


    string graphType;
    myfile>>graphType;
    type=graphType;


    Graph g;
    int c=0;
    g.type=type;
    g.graphid=graphid;
    Vertex arr[100];
    if(myfile.is_open())
    {
        while(myfile>>source>>dest>>weight)
        {


            /*Vertex v,v2;
            v.setStateName(source);
            v.setStateID(getid(source));
            g.AddVertex(v);
            v2.setStateName(dest);
            v2.setStateID(getid(dest));
            g.AddVertex(v2);
            g.AddEdge(v,v2,stoi(weight));*/
            arr[c].setStateName(source);
            arr[c].setStateID(c);
            g.AddVertex(arr[c]);

            c++;
            arr[c].setStateName(dest);
            arr[c].setStateID(c);
            g.AddVertex(arr[c]);
            g.AddEdge(arr[c-1],arr[c],stoi(weight));
            c++;


        }
    }
    return g;

}

void Graph::WriteFile(int  id,char type)
{
    fstream myfile;
    string s="CMakeLists"+to_string(graphid)+".txt";
    myfile.open(s, ios::out | ios::app);
    if (myfile.is_open()) {
        myfile << id<<"\n"<<type<<"\n";

        for (int i = 0; i < vertices.size(); i++) {
            for (auto it = vertices.at(i).edges.begin(); it != vertices.at(i).edges.end(); it++) {
                myfile << vertices.at(i).getStateName() << " ";
                myfile << getName(it->getDestinationVertexID()) << " " << it->getWeight() ;
                myfile << endl;
            }
            myfile <<"\n";
        }

    }
    myfile.close();
}


void Graph::SaveFile(int graphid)
{

    fstream  myfile("CMakeLists"+to_string(graphid)+".txt");
    if (myfile.is_open()) {
        cout << "Changes are Saved.";
    }
    myfile.close();
}
void Graph::updateFile(string checkwith,string newVal)
{
    cout<<"Enter the file name as'CmakeList+id.txt'\n";
    char c[1000];
    cin>>c;

    fstream myfile;
    fstream temp;
    myfile.open(c, ios::in);
    temp.open("temp2.txt", ios::out);
    string line;
    while (!myfile.eof())
    {
        getline(myfile, line);


        if (line.find(checkwith) != std::string::npos)
        {
            newVal = line.replace(line.find(checkwith), checkwith.size(), newVal);
            temp << newVal << "\n";
        }
        else
        {
            temp << line << "\n";
        }
    }

    temp.close();
    myfile.close();
    remove(c);
    rename("temp2.txt",c);
    /*myfile.open("CMakeLists.txt", ios::out);
    temp.open("temp.txt", ios::in);
    while (!temp.eof())
    {
        getline(myfile, line);

        myfile << line << "\n";
    }
    temp.close();
    myfile.close();
    remove("temp.txt");
    cout << "udated in file Sucessfully\n";
*/
}


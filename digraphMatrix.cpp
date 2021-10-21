#include "digraphMatrix.h"
#include <string>
#include <iostream>
using namespace std;

DigraphMatrix::DigraphMatrix(const string& filename)
{
    ifstream input(filename);

    if(!input.is_open()){
        cout << "No file found!" << endl;
        return; // break out of the fnc
    }

/*
 n = # of vertex (from header)
 m = num of edges
*/
    int x, y;
    input >> x;
    n = x; // assigning the num of vertices

    marks = new mark_t[n];
    for(int i = 0; i < n; i++)
        marks[i] = UNDISCOVERED;

    for(int i = 0; i < n; i++)
        CID.push_back(0);

// allocating space for the n by n adjacency matrix and the inverse matrix
    adjMatrix = new bool*[n];
    for(int i = 0; i<n; i++){
        adjMatrix[i] = new bool[n];
        for(int j = 0; j<n; j++){
            adjMatrix[i][j] = false;
        }
    }
// reverse matrix instead of incoming neighbours
    rev_adjMatrix = new bool*[n];
    for(int i = 0; i<n; i++){
        rev_adjMatrix[i] = new bool[n];
        for(int j = 0; j<n; j++){
            rev_adjMatrix[i][j] = false;
        }
    }

    input >> x; //x = to the num of edges in the graph

    while(input >> x){
        input >> y;             // exist an edge between x and y
        adjMatrix[x][y] = true;
        rev_adjMatrix[y][x] = true;
    }
}

//reverse getOutNeighbor
vector<int> DigraphMatrix::getOutNeighbors_rev(const int x) const
{
    vector<int> ret;

    for(int i = 0; i < n; i++) {
        if (rev_adjMatrix[x][i])
            ret.push_back(i);
    }
    return ret;
    
}

//Out Neighbor Directions
vector<int> DigraphMatrix::getOutNeighbors(const int x) const
{
    vector<int> ret;

    for(int i = 0; i < n; i++) {
        if (adjMatrix[x][i])
            ret.push_back(i);
    }

    return ret;
}

//Computing SCC
vector<int> DigraphMatrix::stronglyConnectedComponents()
{
    vector<int> ret;
    for(int i = 0; i < n; i++)
        ret.push_back(0);

    for (int i = 0; i < n; i++){
        if (marks[i] == UNDISCOVERED)
            DFS(i);
    }

    stack<int> temp_stack;
    temp_stack = val;

    while(!val.empty())
        val.pop();
    

    for(int i = 0; i < n; i++)
        marks[i] = UNDISCOVERED;

    while (!temp_stack.empty()){
        if(marks[temp_stack.top()] == UNDISCOVERED) {
            rev_DFS(temp_stack.top());
            count++;
        }
        temp_stack.pop();
    }


    while(!val.empty()){
        val.pop();
    }

    return CID;
}
 
 //DFS for Second Pass
void DigraphMatrix::rev_DFS(const int x) {
    
    marks[x] = DISCOVERED;
    
    for(int id : getOutNeighbors_rev(x)) {
        if(marks[id] == UNDISCOVERED)
            rev_DFS(id);
    }
    
    marks[x] = EXPLORED;
    val.push(x);
    CID[x] = count;

}

//DFS for First Pass
void DigraphMatrix::DFS(const int x) {
    
    marks[x] = DISCOVERED;
    
    for(int id : getOutNeighbors(x)) {
        if(marks[id] == UNDISCOVERED)
            DFS(id);
    }
    
    marks[x] = EXPLORED;
    val.push(x);
}
#ifndef __DIGRAPH_MATRIX_H
#define __DIGRAPH_MATRIX_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
#include <stack>
using namespace std;

enum mark_t { UNDISCOVERED, DISCOVERED, EXPLORED };

class DigraphMatrix
{
private:
    int n;                // n = # of vertex
    bool** adjMatrix;     // 2d bool array, indexes represent the id's true values represent edges
    bool** rev_adjMatrix; // 2d Reversed Adjancency Matrix (bool array)
    mark_t* marks;        // enum representations of vertex discovery
    stack<int> val;       // stack that holds the explored vertices of DFS and rev_DFS
    vector<int> CID;      // vector for strongly connected components
    int count = 0;        // global component while loop index

public:
    // Reads in digraph from given file
    // Stores graph as an adjacency matrix
    DigraphMatrix(const string&);

    // Returns vector containing component ID for each vertex
    vector<int> stronglyConnectedComponents();

    vector<int> getOutNeighbors_rev(const int) const; // used an inverse matrix instead of incoming neighbors
    vector<int> getOutNeighbors(const int) const;     
    
    //DFS Graph Traversal Functions (regular and reversed)
    void DFS(const int);
    void rev_DFS(const int x);
};

#endif
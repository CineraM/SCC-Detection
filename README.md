# SCC-Detection
Strongly Connected Layers detection - Deep First Seach based algorithm 
Since a DFS based algorithm was used, I implemented a Adjancecy Matrix based graph.
A SCC ina a diagraph is the maximal set of vertices so that every vertex in the set is connected to every other vertex.

DFA Based algorithm example:
Output: [2, 1, 1, 3, 1, 0]
Explanation: Nodes are grouped by index. There are four SCC:
[5], [1, 2, 4] , [0], [3] à There are four components!

# SCC-Detection  
Strongly Connected Layers detection - Deep First Seach based algorithm  
Since a DFS based algorithm was used, I implemented a Adjancecy Matrix based graph.  
A SCC ina a diagraph is the maximal set of vertices so that every vertex in the set is connected to every other vertex.  
DFA Based algorithm

SCC example:  
![image](https://user-images.githubusercontent.com/64340009/138234135-3b34ad0f-3de1-43c4-8b7d-de33a76e9171.png)  
Output: [2, 1, 1, 3, 1, 0]  
Explanation: Each node belongs to a SCC Group, each index represents the node each value represents in which group the index should be in.  
There are four SCC:  
Group 0: [5] 
Group 1: [1, 2, 4]   
Group 2: [0]
Group 3: [3]  
--> There are four components!


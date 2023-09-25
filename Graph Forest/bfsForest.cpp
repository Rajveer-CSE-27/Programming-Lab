#include <iostream>
#include <vector>
#include <queue>
#include "adjacencyMatrix.cpp"


using namespace std;
int main() {
	
	Graph g(6);
	
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(5, 5);
    
    vector<vector<int>> bfsForest = g.bFSForest();
    
    cout << "BFSForest" << endl;
    
    for (int i = 0; i < bfsForest.size(); i++) {
        cout << "Component " << i + 1 << ": ";
        
        for (int j = 0; j < bfsForest[i].size(); j++) {
            cout << bfsForest[i][j] << " ";
        }
        cout << endl;
    }
	
	
}
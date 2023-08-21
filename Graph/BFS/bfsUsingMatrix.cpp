#include <iostream>
#include <vector>
#include <queue>
#include "adjacencyMatrix.cpp"

vector<int> bfs(int vertices, Graph graph) {
	vector<int> ans;
	
	bool visited[vertices] = {false};
	queue<int> q;
	
	q.push(0);
	while(!q.empty()) {
		int vertex = q.front();
		q.pop();
		ans.push_back(vertex);
		visited[vertex] = true;
		for(int i=0; i<vertices; i++) {
			if(visited[i] == false and graph.getEdge(vertex,i) == true) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
	
	return ans;
}


using namespace std;
int main() {
	
	Graph graph(5);
	
	graph.addEdge(0,1);
	graph.addEdge(0,2);
	graph.addEdge(2,3);
	graph.addEdge(3,1);
	graph.addEdge(4,1);
	graph.addEdge(4,3);
	
	graph.printGraph();
	cout << endl;
	graph.removeEdge(4,3);
	
	graph.printGraph();
	cout << endl;
	
	vector<int> breadthFirstSearch = bfs(5,graph);
	for(auto it:breadthFirstSearch) {
		cout << it << " ";
	}
	cout << endl;
	return 0;
}

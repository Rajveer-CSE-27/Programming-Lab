#include <iostream>
#include <vector>
#include "adjacencyList.cpp"

void dfs(int vertex, Graph graph, bool visited[], vector<int>& ans) {
	visited[vertex] = true;
	ans.push_back(vertex);
	
	for(auto it:graph.getListForCurrentVertex(vertex)) {
		if(visited[it] == false) {
			dfs(it, graph, visited, ans);
		}
	}
}

vector<int> dfsGraph(int vertices, Graph graph) {
	bool visited[vertices] = {false};
	vector<int> ans;
	dfs(0, graph, visited, ans);
	
	return ans;
}

using namespace std;
int main() {
	
	Graph g;
	
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.addEdge(3,1);
	g.addEdge(4,1);
	g.addEdge(4,3);
	
	g.printGraph();
	cout << endl;
	
	g.removeEdge(4,3);
	g.printGraph();
	
	vector<int> depthFirstSearch = dfsGraph(5, g);
	cout << endl;
	for(auto it:depthFirstSearch) {
		cout << it << " ";
	}
	return 0;
}
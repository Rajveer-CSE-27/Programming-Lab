#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
	
	int vertices = 5;
	vector<int> graph[5];
	
	void addEdge(int vertex1, int vertex2) {
		if(vertex1 < 0 or vertex1 >= vertices or vertex2 < 0 or vertex2 >= vertices) {
			cout << "Index out of bound";
			return;
		}
	
		graph[vertex1].push_back(vertex2);
		graph[vertex2].push_back(vertex1);
	}

	void removeEdge(int vertex1, int vertex2) {
		if(vertex1 < 0 or vertex1 >= vertices or vertex2 < 0 or vertex2 >= vertices) {
			cout << "Index out of bound";
			return;
		}
		auto iterator1 = graph[vertex1].begin();
		auto iterator2 = graph[vertex2].begin();
	
		while(iterator1 != graph[vertex1].end()) {
			if(*iterator1 == vertex2) {
				break;
			}
			iterator1++;
		}
		while(iterator2 != graph[vertex2].end()) {
			if(*iterator2 == vertex1) {
				break;
			}
			iterator2++;
		}
	
		if(iterator1 != graph[vertex1].end()) {
			graph[vertex1].erase(iterator1, ++iterator1);
			graph[vertex2].erase(iterator2, ++iterator2);
		}
	
	} 

	void printGraph() {
		for(int i=0; i<vertices; ++i) {
			cout << i << ": ";
			for(auto it:graph[i]) {
				cout << it << " ";
			}
			cout << endl;
		}
	}
	
	vector<int> getListForCurrentVertex(int vertex) {
		vector<int> ans;
		for(auto it:graph[vertex]) {
			ans.push_back(it);
		}
		
		return ans;
	}
};

// int main() {
	
// 	int vertices = 5;
	
// 	vector<int> graph[vertices];
// 	addEdge(0,1,vertices,graph);
// 	addEdge(0,2,vertices,graph);
// 	addEdge(2,3,vertices,graph);
// 	addEdge(3,1,vertices,graph);
// 	addEdge(4,1,vertices,graph);
// 	addEdge(4,3,vertices,graph);
	
// 	printGraph(vertices, graph);
// 	cout << endl;
	
// 	removeEdge(4,3,vertices,graph);
// 	printGraph(vertices, graph);

	
// 	return 0;
// }
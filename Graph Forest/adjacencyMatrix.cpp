#include <iostream>
using namespace std;


class Graph {
public:
	
	int vertices;
	bool** matrix;
	
	Graph(int n) {
		vertices = n;
		matrix = new bool*[vertices];
		
		for(int i=0; i<vertices; ++i) {
			matrix[i] = new bool[vertices];
			for(int j=0; j<vertices; ++j) {
				matrix[i][j] = false;
			}
		}
	}
	
	vector<vector<int>> bFSForest() {
		vector<bool> visited(vertices, false);
		vector<vector<int>> forest;
		
		for(int i=0; i<vertices; i++) {
			if (!visited[i]) {
                vector<int> component;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    component.push_back(u);
                    
                    for (int v = 0; v < vertices; ++v) {
                        if (matrix[u][v] == true && !visited[v]) {
                            q.push(v);
                            visited[v] = true;
                        }
                    }
                }
                
                forest.push_back(component);
            }
		}
		
		
		return forest;
	}
	
	void addEdge(int vertex1, int vertex2) {
		if(vertex1 < 0 or vertex1 >= vertices or vertex2 < 0 or vertex2 >= vertices) {
			cout << "Index out of bound";
			return;
		}
		
		
		matrix[vertex1][vertex2] = true;
		matrix[vertex2][vertex1] = true;
	}
	
	void removeEdge(int vertex1, int vertex2) {
		if(vertex1 < 0 or vertex1 >= vertices or vertex2 < 0 or vertex2 >= vertices) {
			cout << "Index out of bound";
			return;
		}
		
		matrix[vertex1][vertex2] = false;
		matrix[vertex2][vertex1] = false;
	}
	
	void printGraph() {
		for(int i=0; i<vertices; ++i) {
			for(int j=0; j<vertices; ++j) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	
	bool getEdge(int vertex1, int vertex2) {
		if(vertex1 < 0 or vertex1 >= vertices or vertex2 < 0 or vertex2 >= vertices) {
			cout << "Index out of bound";
			return false;
		}
		if(matrix[vertex1][vertex2] == 1) {
			return true;
		}
		
		return false;
	}
};


// int main() {
// 	Graph graph(5);
	
// 	graph.addEdge(0,1);
// 	graph.addEdge(0,2);
// 	graph.addEdge(2,3);
// 	graph.addEdge(3,1);
// 	graph.addEdge(4,1);
// 	graph.addEdge(4,3);
	
// 	graph.printGraph();
// 	cout << endl;
// 	graph.removeEdge(4,3);
	
// 	graph.printGraph();
	
// 	return 0;
// }
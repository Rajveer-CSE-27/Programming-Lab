#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;
    vector<vector<int>> revAdj; // adjacency matrix for complement graph

    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
        revAdj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    void DFS(int v, vector<bool>& visited, stack<int>& s) {
        visited[v] = true;
        
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited, s);
            }
        }
        s.push(v);
    }

    void reverseDFS(int v, vector<bool>& visited, vector<int>& component) {
        visited[v] = true;
        component.push_back(v);
        for (int neighbor : revAdj[v]) {
            if (!visited[neighbor]) {
                reverseDFS(neighbor, visited, component);
            }
        }
    }

    vector<vector<int>> findSCCs() {
        vector<bool> visited(V, false);
        stack<int> s;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, visited, s);
            }
        }

        // Reset visited array to all false
        fill(visited.begin(), visited.end(), false);

        vector<vector<int>> SCCs;

        while (!s.empty()) {
            int v = s.top();
            s.pop();

            if (!visited[v]) {
                vector<int> component;
                reverseDFS(v, visited, component);
                SCCs.push_back(component);
            }
        }

        return SCCs;
    }
};

int main() {
    int V = 8; 
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 3);
    g.addEdge(6, 5);
    g.addEdge(6, 7);

    vector<vector<int>> SCCs = g.findSCCs();

    cout << "Strongly Connected Components:" <<endl;
    for (vector<int>& component : SCCs) {
        for (int vertex : component) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}

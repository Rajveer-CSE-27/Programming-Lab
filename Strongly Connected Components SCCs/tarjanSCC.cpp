#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj; 
    int time;
    vector<int> disc; 
    vector<int> low; 
    vector<bool> inStack; // Tracks whether a vertex is in the stack
    stack<int> s;
    vector<vector<int>> SCCs;

    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
        disc.resize(V, -1);
        low.resize(V, -1);
        inStack.resize(V, false);
        time = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void tarjanDFS(int v) {
        disc[v] = low[v] = time;
        time++;
        s.push(v);
        inStack[v] = true;

        for (int neighbor : adj[v]) {
            if (disc[neighbor] == -1) {
                tarjanDFS(neighbor);
                low[v] = min(low[v], low[neighbor]);
            } else if (inStack[neighbor]) {
                low[v] = min(low[v], disc[neighbor]);
            }
        }

        if (low[v] == disc[v]) {
            vector<int> component;
            while (true) {
                int top = s.top();
                s.pop();
                inStack[top] = false;
                component.push_back(top);
                if (top == v) {
                    break;
                }
            }
            SCCs.push_back(component);
        }
    }

    vector<vector<int>> findSCCs() {
        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                tarjanDFS(i);
            }
        }
        return SCCs;
    }
};

int main() {
    int V = 8; 
    Graph g(V);

    // Adding edges to the graph
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

    cout << "Strongly Connected Components:\n";
    for (const vector<int>& component : SCCs) {
        for (int vertex : component) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}

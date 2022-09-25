#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
	BFS(Breadth First Search)

	- Assumes All Vertices are Reachable from Start
	- Checks Visited / Not Visited
	- Uses Queue
*/

class Graph {

	// The Number of Vertex
	int v;
	// The Lists of Adjacency of Specific Vertex
	// adj[1] indicates the adjacent vertices of Vertex 1.
	vector<vector<int>> adj;

public:
	Graph(int n); // Constructor
	void connectEdge(int v, int x); // Connects Edges nearby Vertex v, by adding them to adj
	void BFS(int start); // BFS Computer
};

Graph::Graph(int n) {
	v = n;
	adj.resize(v);
}

void Graph::connectEdge(int v, int x) {
	adj[v].push_back(x);
}

void Graph::BFS(int start) {
	vector<bool> visited(v, false);
	queue<int> queue;

	// Enqueue the start vertex
	visited[start] = true;
	queue.push(start);

	// Until the queue becomes empty
	while (!queue.empty()) {
		// Dequeue the front vertex -> Print
		start = queue.front();
		cout << start << " ";
		queue.pop();

		// Enqueue all adjacent vertices of 'start'
		for (auto v : adj[start]) {
			// If an adjacent vertex 'v' is not visited,
			if (!visited[v]) {
				// Mark it visited, and enqueue it.
				visited[v] = true;
				queue.push(v);
			}
		}
	}
}

int main()
{
	// Example Graph
	Graph g(4);
	g.connectEdge(0, 1);
	g.connectEdge(0, 2);
	g.connectEdge(1, 2);
	g.connectEdge(2, 0);
	g.connectEdge(2, 3);
	g.connectEdge(3, 3);

	cout << "BFS Result: " << endl;
	g.BFS(2);

	return 0;
}
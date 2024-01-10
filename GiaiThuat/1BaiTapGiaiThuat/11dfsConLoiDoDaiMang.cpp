#include <vector>
#include <iostream>
using namespace std;
const int N = 1000;
vector<int> adj[N];
void dfsUtil(int u, int node, bool visited[],
	vector<pair<int, int> > road_used, int parent,
	int it)
{
	int c = 0;
	for (int i = 0; i < node; i++)
		if (visited[i])
			c++;
	if (c == node)
		return;
	visited[u] = true;
	road_used.push_back({ parent, u });
	cout << u << " ";
	for (int x : adj[u]) {
		if (!visited[x])
			dfsUtil(x, node, visited, road_used, u, it + 1);
	}
	for (auto y : road_used)
		if (y.second == u)
			dfsUtil(y.first, node, visited, road_used, u,
				it + 1);
}
void dfs(int node)
{
	bool visited[node];
	vector<pair<int, int> > road_used;
	for (int i = 0; i < node; i++)
		visited[i] = false;
	dfsUtil(0, node, visited, road_used, -1, 0);
}
void insertEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int main()
{
	int node = 11, edge = 13;
	insertEdge(0, 1);
	insertEdge(0, 2);
	insertEdge(1, 5);
	insertEdge(1, 6);
	insertEdge(2, 4);
	insertEdge(2, 9);
	insertEdge(6, 7);
	insertEdge(6, 8);
	insertEdge(7, 8);
	insertEdge(2, 3);
	insertEdge(3, 9);
	insertEdge(3, 10);
	insertEdge(9, 10);
	dfs(node);
	return 0;
}

#include <iostream>
#include <queue>
#include <list>
using namespace std;
class Graph
{
    int V;
    list<pair<int, int>> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<pair<int, int>>[V];
    }
    // undirected graph
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    void shortestPath(int src)
    {
        /// TC = V + ELogV
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT16_MAX);
        // Insert source itself in priority queue and initialize
        // its distance as 0.
        pq.push(make_pair(0, src)); //{distance,src}
        dist[src] = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for (auto it : adj[u])
            {
                int v = it.first;
                int weight = it.second;
                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        printf("\nShortest Distance from source = \n");
        for (int i = 0; i < V; i++)
        {
            printf("%d \t\t %d\n", i, dist[i]);
        }
    }
};
int main()
{
    int V = 9;
    Graph g(V);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.shortestPath(0);
}
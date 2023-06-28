#include <bits/stdc++.h>
using namespace std;
vector<long long int> dijkstra(vector<vector<pair<long long int, long long int>>> &graph, int n, int sourse)
{
    vector<long long int> dist(n + 1, 1e18), vis(n+1);
    set<pair<long long int, long long int>> pq;
    dist[sourse] = 0;
    pq.insert({dist[sourse], sourse});
    while (pq.size())
    {
        int v = (*pq.begin()).second;
        pq.erase(pq.begin());
		if (vis[v])continue;
		vis[v]=1;
        for (auto i : graph[v])
        {
            long long nod = i.first, dis = i.second;
            if (dist[nod] > dis + dist[v])
            {
                dist[nod] = dis + dist[v];
                pq.insert({dist[nod], nod});
            }
        }
    }
    return dist;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<long long int, long long int>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        long long int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }
    vector<long long int> dist = dijkstra(graph, n, 1);
    for (int i = 1; i <= n; i++)
        cout << dist[i] << " ";
}
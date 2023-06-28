#include <bits/stdc++.h>
using namespace std;
double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
{
    vector<vector<pair<int, double>>> adj(n);
    vector<bool> vis(n, 0);
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
        adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }
    double ans = 0;
    set<pair<double, int>, greater<pair<double, int>>> q;
    vector<double> dis(n);
    dis[start] = 1;
    q.insert({dis[start], start});
    while (q.size())
    {
        auto node = *q.begin();
        q.erase(q.begin());
        int vid = node.second;
        double prb = node.first;
        if (vis[vid])
            continue;
        vis[vid] = true;
        for (auto i : adj[vid])
            if (prb * i.second > dis[i.first])
            {
                dis[i.first] = prb * i.second;
                q.insert({dis[i.first], i.first});
            }
    }
    return dis[end];
}
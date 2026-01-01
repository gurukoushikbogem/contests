#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> g_from(m), g_to(m);
    for (int i = 0; i < m; i++)
    {
        cin >> g_from[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> g_to[i];
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < m; i++)
    {
        mp[g_from[i]].push_back(g_to[i]);
        mp[g_to[i]].push_back(g_from[i]);
    }
    vector<int> ans;
    vector<int> vis(n+1, -1);
    queue<int> q;
    priority_queue<int>pq;
    pq.push(n);
    while (!pq.empty())
    {
        int tp = pq.top();
        pq.pop();
        if(vis[tp])continue;
        vis[tp]=1;
        ans.push_back(tp);
        for (auto i : mp[tp])
        {
            if(vis[i]==-1)
            pq.push(i);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}
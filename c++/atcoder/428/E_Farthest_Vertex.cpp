#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define INF 1e15
#define SORT(v) sort((v).begin(), (v).end())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define mod (long long)(1e9 + 7)
#define vi vector<long long>
#define vvi vector<vector<long long>>
#define vc vector<char>
#define vpii vector<pair<long long, long long>>
#define endl "\n"
#define mpii map<long long, long long>
#define umpii unordered_map<long long, long long>
#define mpci map<char, long long>
using namespace std;
template <class T>
void input(vector<T> &a)
{
    for (auto &x : a)
        cin >> x;
}

template <class T>
void print(vector<T> &a)
{
    for (auto &x : a)
        cout << x << " ";
    cout << endl;
}

template <class T>
void print(T x) { cout << x << " "; }

template <class T>
void println(T x) { cout << x << "\n"; }

pair<int, int> find_farthest(vector<vector<int>> &adj, int st, int n)
{
    vector<int> m1(n + 1, -1);
    queue<int> q;
    q.push(st);
    m1[st] = 0;

    int farthest_node = st;
    int m2 = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (m1[u] > m2 || (m1[u] == m2 && u > farthest_node))
        {
            m2 = m1[u];
            farthest_node = u;
        }

        for (int v : adj[u])
        {
            if (m1[v] == -1)
            {
                m1[v] = m1[u] + 1;
                q.push(v);
            }
        }
    }

    return {farthest_node, m2};
}

vector<int> cds(vector<vector<int>> &adj, int st, int n)
{
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(st);
    dist[st] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;
}

void solution()
{
    int N;
    cin >> N;

    vector<vector<int>> adj(N + 1);

    map < int, int > mp;

    for (int i = 0; i < N - 1; i++)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
        mp[A]++;
    }

    int uv = find_farthest(adj, 1, N).first;

    int vu = find_farthest(adj, uv, N).first;

    vector<int> d1 = cds(adj, uv, N);
    vector<int> d2 = cds(adj, vu, N);

    for (int v = 1; v <= N; v++)
    {
        if (d1[v] > d2[v])
        {
            printf("%lld\n", uv);
        }
        else if (d2[v] > d1[v])
        {
            printf("%lld\n", vu);
        }
        else
        {
            printf("%lld\n", max(uv, vu));
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    while (t--)
    {
        solution();
    }
    return 0;
}

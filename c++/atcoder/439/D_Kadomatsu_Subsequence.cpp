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

void solution()
{
    int n;
    cin >> n;

    map<int, vector<int>> mp;

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        mp[a].push_back(i);
    }

    int ans = 0;

    for (auto &p : mp)
    {
        int v = p.first;
        if (v % 5 != 0)
            continue;

        int x = v / 5;
        int a7 = 7 * x;
        int a3 = 3 * x;

        if (!mp.count(a7) || !mp.count(a3))
            continue;

        auto &m5 = mp[v];
        auto &m7 = mp[a7];
        auto &m3 = mp[a3];

        for (int j : m5)
        {
            int ir = m7.end() - upper_bound(m7.begin(), m7.end(), j);
            int kr = m3.end() - upper_bound(m3.begin(), m3.end(), j);
            ans += ir * kr;

            int il = lower_bound(m7.begin(), m7.end(), j) - m7.begin();
            int kl = lower_bound(m3.begin(), m3.end(), j) - m3.begin();
            ans += il * kl;
        }
    }

    println(ans);
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
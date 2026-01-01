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
    vector<int> v(n);
    vector<int> dis(n);
    map<int, vector<int>> mp;
    set<pair<int, int>> visited_intervals; 
    vector<pair<int, int>> dr;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]].push_back(i);
        dis[i] = mp.size();
    }

    int ans = 0;

    for(auto &i: mp){
        vector<int> &indices = i.second;
        int k = indices.size();
        dr.push_back({indices[k-1]-indices[0]+1,i.first});
    }

    sort(dr.begin(),dr.end(),greater<pair<int,int>>());

    for (auto i:dr)
    {
        vector<int> &indices = mp[i.second];
        int k = indices.size();

        if (k > 1)
        {
            int l = dis[indices[0]];    
            int r = dis[indices[k - 1]];
            bool is_overlapping = false;

            for (auto &interval : visited_intervals)
            {
                if (l >= interval.first && r <= interval.second)
                {
                    is_overlapping = true;
                    break;
                }
            }

            if (!is_overlapping)
            {
                ans += (r - l + 1);
                visited_intervals.insert({l, r});
            }
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
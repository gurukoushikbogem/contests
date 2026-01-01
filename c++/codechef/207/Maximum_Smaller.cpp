#include <bits/stdc++.h>
#define ll long long
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

ll power(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return ans;
}

void solution()
{
    int n;
    cin >> n;
    vi q(n);
    input(q);
    vi ans(n, 0);
    mpii mp;
    vi tt = q;
    sort(tt.begin(), tt.end());
    for (int i = 1; i <= n; i++)
    {
        mp[i]++;
    }
    for (int i = 0; i < n; i++)
    {
        auto it = mp.lower_bound(q[i]);
        if (mp.size() == 1)
        {
            ans[q[i] - 1] = mp.begin()->first;
            mp.erase(mp.begin());
            break;
        }
        if (it != mp.begin() && it->first != q[i])
        {
            ans[q[i] - 1] = it->first;
            mp.erase(it);
        }
        else if (it != mp.begin() && it->first == q[i])
        {
            it--;
            if (it != mp.begin())
            {
                ans[q[i] - 1] = it->first;
                mp.erase(it);
            }
        }
        else
        {
            it++;
            if (it != mp.end())
            {
                ans[q[i] - 1] = it->first;
                mp.erase(it);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == 0)
        {
            if(mp.size() == 0)
                break;
            ans[i] = mp.begin()->first;
            mp.erase(mp.begin());
        }
    }
    print(ans);
}
int main()
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
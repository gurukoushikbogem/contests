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
    int a, b;
    cin >> a >> b;
    vector<int> v(a);
    input(v);
    vector<int> u(b);
    input(u);
    int i = 0, j = 0;
    int ans = 0;
    set<int> s;
    vector<pair<int, int>> p(b);
    int fl = 0, fg = 0;
    int mis = 0;
    for (int i = 0; i < a; i++)
    {
        if ((v[i] == 1 && p[i].first == 0) || (v[i] == 0 && p[i].second == 0))
        {
            mis++;
        }
        else if (mis < b && (v[i] == 1 && p[mis].first == 1) || (v[i] == 0 && p[mis].second == 1))
        {
            ans++;
        }
        cout << mis << " ";
    }
    cout << a - ans << endl;
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
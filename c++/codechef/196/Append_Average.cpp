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
    int n, k;
    cin >> n >> k;
    vi a(n);
    input(a);
    ll sum = 0;
    ll kk = INF, pp = INF;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < kk)
        {
            pp = kk;
            kk = a[i];
        }
        else if (a[i] < pp)
        {
            pp = a[i];
        }
        sum += a[i];
    }
    map<int, int> mp;
    for (int i = 0; i < k; i++)
    {
        ll tt = kk + pp;
        ll avg = 0;
        if (tt % 2)
            avg = (tt + 1) / 2;
        else
            avg = tt / 2;
        sum += avg;
        if (avg <= kk)
        {
            pp = kk;
            kk = avg;
        }
        else if (avg < pp)
        {
            pp = avg;
        }
        if (mp.find(avg) != mp.end())
        {
            sum += (k - i - 1) * avg;
            break;
        }
        else
        {
            mp[avg]++;
        }
    }
    cout << sum << "\n";
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
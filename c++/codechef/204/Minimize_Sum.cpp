#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define INF 1e15
#define SORT(v) sort((v).begin(), (v).end())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define mod (ll)(1e9 + 7)
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define vc vector<char>
#define vpii vector<pair<ll, ll>>
#define endl "\n"
#define mpii map<ll, ll>
#define umpii unordered_map<ll, ll>
#define mpci map<char, ll>
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
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    ll bs = 0;
    vector<ll> mod_arr;

    for (int idx = 0; idx < n; idx++)
    {
        cin >> a[idx];
        bs += a[idx];
        if (a[idx] > 0)
        {
            mod_arr.push_back(k - a[idx]);
        }
    }

    sort(mod_arr.begin(), mod_arr.end());

    mpii freq;
    for (auto x : mod_arr)
    {
        freq[x]++;
    }

    ll ans = bs;
    ll pl = 0;

    for (int pos = 0; pos < mod_arr.size();)
    {
        int nxt = pos;

        while (nxt < mod_arr.size() && mod_arr[nxt] == mod_arr[pos])
        {
            nxt++;
        }

        pl += (nxt - pos);
        ll shift = mod_arr[pos];
        ll cd = bs;
        cd += n * shift;
        cd -= k * pl;

        if (cd < ans)
        {
            ans = cd;
        }

        pos = nxt;
    }

    println(ans);
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
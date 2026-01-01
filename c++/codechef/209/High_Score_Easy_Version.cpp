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
    int m, n;
    cin >> m >> n;
    vi a(m), b(n);
    input(a);
    input(b);
    multiset<int> s1, s2;
    for (int i = 0; i < n; i++)
    {
        s1.insert(a[i]);
        s2.insert(b[i]);
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    vi v;
    int i = 0;
    while (m && i < n)
    {
        auto it = s2.upper_bound(a[i]);
        if (it != s2.end())
        {
            v.push_back(a[i] + *it);
            s2.erase(it);
            m--;
        }
        else
        {
            it = s2.find(a[i]);
            while (it != s2.begin() && *it == a[i])
            {
                it--;
                v.push_back(a[i] + *it);
                s2.erase(it);
                m--;
            }
        }
        i++;
    }
    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < min(m, (int)v.size()); i++)
        ans += v[i];
    cout << ans << "\n";
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
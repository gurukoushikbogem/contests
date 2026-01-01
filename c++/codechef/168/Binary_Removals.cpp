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
    int n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    int c = 0, c1 = 0;
    int ans = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            ans += c1;
            c2++;
        }
        else if (s[i] == '1')
        {
            c1++;
        }
    }
    if (c2 == 0 || c1 == 0)
        cout << 1 << endl;
    else if (ans <= x && ans % k == 0)
        cout << 1 << endl;
    else
    cout << 2 << endl;
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
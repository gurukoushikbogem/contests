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
    string a, b;
    cin >> a >> b;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if (j != b.size())
    {
        cout << "-1\n";
        return;
    }
    map<int, int> mp;
    int ans = 0, jg = b.size() - 1;
    for (int i = a.size() - 1; i >= 0 && jg >= 0; i--)
    {
        if (a[i] == b[jg])
        {
            jg--;
            mp[i]++;
        }
    }
    int c = 1;
    for (int i = 0; i < a.size(); i++)
    {
        if (mp.find(i) != mp.end())
        {
            c++;
        }
        else
        {
            ans += c;
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
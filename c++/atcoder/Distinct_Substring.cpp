#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define endl "\n"
#define mod ((int)(1e9) + 7ll)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define F first
#define S second
#define vi vector<int>
#define vc vector<char>
#define vpi vector<pair<int, int>>
#define si set<int>
#define pi pair<int, int>
#define mi map<int, int>
#define miv map<int, vector<int>>
using namespace std;
void solve()
{
    int n, m;
    cin >> m >> n;
    int y = n * (n + 1) / 2;
    y += n - 1;
    if (y <= m)
        yes;
    else
        no;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

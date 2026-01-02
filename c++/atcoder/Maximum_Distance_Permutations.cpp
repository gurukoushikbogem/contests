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
    int n;
    cin >> n;
        vector<int>v;
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i);
            cout << i << " ";
        }
        cout<<endl;
        for(int i=(n/2);i<n;i++){
            cout<<v[i]<<" ";
        }
        for(int i=0;i<(n/2);i++){
            cout<<v[i]<<" ";
        }
        cout << endl;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

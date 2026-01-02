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
    string s;
    cin >> s;
    int c1 = 0, c2 = 0;
    for (char i : s)
    {
        if (islower(i))
        {
            c1++;
        }
        else
        {
            c2++;
        }
    }
    if (c1 > c2)
    {
        for (char &i : s)
        {
            i = tolower(i);
        }
    }
    else
    {
        for (char &i : s)
        {
            i = toupper(i);
        }
    }
    cout << s << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    while (t--)
    {
        solve();
    }

    return 0;
}

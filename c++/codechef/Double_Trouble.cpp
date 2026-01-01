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
    vi v(n), p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    vi left(n, 0), right(n, 0);

    right[0] = 0;

    for (int i = 1; i < n; i++)
    {
        if (v[i-1] + p[i-1] >= v[i])
        {
            right[i] = right[i - 1];
        }
        else
        {
            right[i] = i;
        }
    }

    left[n - 1] = n-1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i+1] - p[i+1] <= v[i])
        {
            left[i] = left[i + 1];
        }
        else
        {
            left[i] = i;
        }
    }


    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (left[i] == n - 1 || left[left[i] + 1] == n - 1 || right[0] == left[i] + 1)
            {
                yes;
                return;
            }
        }
        else if (i == n - 1)
        {
            if (right[i] == 0 || right[right[i]-1] == 0 || left[n-1]==right[i]+1)
            {
                yes;
                return;
            }
        }
        else if ((left[i + 1] == n - 1 && (right[i] == 0 || left[0]==i)))
        {
            yes;
            return;
        }
        else if ((left[i] == n - 1 && (right[i-1] == 0 || left[0] == i-1)))
        {
            yes;
            return;
        }
        else if (right[i] == 0 && (right[n - 1] == i + 1 || left[i + 1] == n - 1))
        {
            yes;
            return;
        }
        else if (right[i-1] == 0 && (right[n - 1] == i  || left[i] == n - 1))
        {
            yes;
            return;
        }

        if(i==1){
            if(left[i]==n-1){
                yes;
                return;
            }
        }
        if (i == n-2)
        {
            if (right[i] == 0)
            {
                yes;
                return;
            }
        }
    }

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
    return 0;
}

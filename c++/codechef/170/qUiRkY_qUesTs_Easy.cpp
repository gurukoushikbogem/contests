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
    int n;
    cin >> n;
    vi v(n);
    input(v);
    SORT(v);
    int mex = 0;
    if (v[0] == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] > mex + 1)
            {
                mex++;
                break;
            }
            else
            {
                mex = v[i];
            }
            if (i == n - 1)
            {
                mex = v[i] + 1;
            }
        }
    }
    if (mex > v[n - 1])
    {
        cout << mex * n << endl;
        return;
    }
    int sum = 0, ind = 0;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (v[i] <= mex)
        {
            continue;
        }
        else
        {
            if (mex + 1 == v[i])
            {
                mex++;
            }
            else
            {
                ind = i - 1;
                break;
            }
        }
        if (i == n - 1)
        {
            flag = true;
        }
    }
    sum = (ind + 1) * mex;
    if (ind < 0)
        ind = 0;
    if (flag)
    {
        cout << mex * n << endl;
        return;
    }
    for (int i = ind; i < n; i++)
    {
        sum += v[i];
    }
    cout << sum << endl;
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
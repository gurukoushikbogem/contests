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

bool help(int a, int b, int m, vector<int> &v1, vector<int> &v2, vector<int> &v3)
{
    if ((b - a + 1) % 2)
        return false;

    int c1 = v1[b], c2 = v2[b], c3 = v3[b];
    if(a>0){
        c1 -= v1[a - 1];
        c2 -= v2[a - 1];
        c3 -= v3[a - 1];
    }
    int n = b - a + 1;
    if (c1 ==(n/2))
        return true;
    if (c2 == (n / 2))
        return true;
    if (c3 == (n / 2))
        return true;
    return false;
}

void solution()
{
    int m, n;
    cin >> m >> n;
    vector<int> v1(m), v2(m), v3(m);
    vector<int> v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
        if(i!=0)
        v1[i] = v1[i - 1], v2[i] = v2[i - 1], v3[i] = v3[i - 1];
        if (v[i] == 1)
        {
            v1[i]+=1;
        }
        else if (v[i] == 2)
        {
            v2[i] += 1;
        }
        else
        {
            v3[i] += 1;
        }
    }
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if (help(a-1, b-1, m, v1, v2, v3))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
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
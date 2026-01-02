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
    int N;
    cin >> N;

    vi A(N);
    input(A);

    mpii mp;

    int X, Y;
    cin >> X >> Y;

    int d = Y - X;
    int R0 = (A[0] * X) % d;
    for (int i = 1; i < N; i++)
    {
        if ((A[i] * X) % d != R0)
        {
            println(-1);
            return;
        }
    }

    int L = LLONG_MIN, R = LLONG_MAX;

    for (int i = 0; i < N; i++)
    {
        L = max(L, A[i] * X);
        R = min(R, A[i] * Y);
        mp[A[i]]++;
    }

    int W = R - ((R - R0) % d);
    if (W < L)
    {
        println(-1);
        return;
    }

    if (L > R)
    {
        println(-1);
        return;
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += (W - A[i] * X) / d;
    }

    println(ans);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    while (t--)
    {
        solution();
    }
    return 0;
}
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

const int N=30;

int dp[N+10][500];

void solution()
{
    int n, k;
    cin >> n >> k;
    int incr_sub = n * (n + 1) / 2 - k;
    if (!dp[n][incr_sub])
    {
        println(0);
        return;
    }
    vi ans;
    int curr = n;
    while (n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (dp[curr - i][incr_sub - i * (i + 1) / 2])
            {
                for (int j = curr - i + 1; j <= curr; j++)
                {
                    ans.pb(j);
                }
                curr -= i;
                incr_sub -= i * (i + 1) / 2;
                n -= i;
                break;
            }
        }
    }
    print(ans);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    dp[0][0] = 1;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 1; i + j <= N; j++)
        {
            int tt = j * (j + 1) / 2;
            for (int k = 0; k + tt <= N * (N + 1) / 2; k++)
            {
                dp[i + j][k + tt] |= dp[i][k];
            }
        }
    }
    while (t--)
    {
        solution();
    }
    return 0;
}
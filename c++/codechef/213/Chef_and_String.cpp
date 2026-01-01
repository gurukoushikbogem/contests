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
    int N, K;
    cin >> N >> K;
    
    string S;
    cin >> S;

    string F;

    for (char c : S)
    {
        if (c != 'I')
            F += c;
    }

    long long ans = 1LL * N * K - 1;

    if (F.size() == 0)
    {
        println(ans);
        return;
    }

    int temp = 0;
    for (int i = 0; i + 1 < F.size(); i++)
    {
        if (F[i] != F[i + 1])
            temp++;
    }

    long long lll = 1LL * K * temp;

    if (F.front() != F.back())
        lll += (K - 1);

    println(ans - lll);
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
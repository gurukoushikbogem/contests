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

int mergeOverlap(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end());
    int resIdx = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[resIdx][1] >= arr[i][0])
            arr[resIdx][1] = max(arr[resIdx][1], arr[i][1]);
        else
        {
            resIdx++;
            arr[resIdx] = arr[i];
        }
    }
    return (resIdx + 1);
}

void solution()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    vi a(n);
    input(a);
    SORT(a);
    vector<vector<int>> arr;
    for (int i = 0; i < n - 1; i++)
    {
        arr.push_back({a[i + 1] - a[i] + 1, a[i + 1] + a[i] - 1});
        arr.push_back({a[n-1] - a[i] + 1, a[n-1] + a[i] - 1});
    }

    int newSize = mergeOverlap(arr);
    int ans = 0;
    for (int i = 0; i < newSize; i++)
    {
        ans += (arr[i][1] - arr[i][0] + 1);
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
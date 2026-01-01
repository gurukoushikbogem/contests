#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define INF 1e15
#define SORT(v) sort((v).begin(), (v).end())
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define MOD (long long)(1e9 + 7)
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
void readInput(vector<T> &v)
{
    for (auto &elem : v)
    {
        cin >> elem;
    }
}

template <class T>
void printVector(const vector<T> &v)
{
    for (const auto &elem : v)
    {
        cout << elem << " ";
    }
    cout << endl;
}
template <class T>
void printSingle(T x)
{
    cout << x << " ";
}

template <class T>
void printSingleLine(T x)
{
    cout << x << "\n";
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    map<int, int> freq;

    vector<int> a(n);
    bool allEqualToK = true;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        freq[a[i]]++;
        if (a[i] != k)
        {
            allEqualToK = false;
        }
    }

    if (allEqualToK)
    {
        cout << 0 << '\n';
        return;
    }

    int leadingCount = 0;
    while (leadingCount < n && a[leadingCount] == k)
    {
        freq[k]--;  
        leadingCount++;
    }

    while (!a.empty() && a[a.size()-1] == k)
    {
        freq[k]--;
        a.pop_back();
    }

    vector<int> filteredArray(a.begin() + leadingCount, a.end());

    bool allSame = true;
    for (size_t i = 1; i < filteredArray.size(); ++i)
    {
        freq[filteredArray[i]]--;
        if (filteredArray[i] != filteredArray[i - 1])
        {
            allSame = false;
            break;
        }
    }
    if (allSame)
    {
        cout << 1 << '\n';
        return;
    }

    bool gcdConditionMet = true;
    for (const auto &value : filteredArray)
    {
        if (gcd(value, k) != k)
        {
            gcdConditionMet = false;
            break;
        }
    }

    cout << (gcdConditionMet ? 1 : 2) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        solve();
    }
    return 0;
}

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

vector<string> getSubstringsOfSize4(const string &s)
{
    vector<string> result;
    int n = s.size();

    for (int i = 0; i <= n - 4; ++i)
    {
        result.push_back(s.substr(i, 4));
    }
    return result;
}

bool isSubsequence(const string &s, const string &pattern)
{
    int i = 0, j = 0;
    while (i < s.size() && j < pattern.size())
    {
        if (s[i] == pattern[j])
            j++;
        i++;
    }
    return j == pattern.size();
}

void solution()
{
    map<string, int> mp;
    mp["1001"]++;
    mp["1100"]++;
    mp["0011"]++;
    mp["0110"]++;

    int n;
    cin >> n;

    string s;
    cin >> s;

    if (n < 4)
    {
        cout << n << endl;
        return;
    }

    vector<string> substrings = getSubstringsOfSize4(s);
    int flag = 0, bhp = 0;
    for (const string &sub : substrings)
    {
        if (mp.find(sub) == mp.end())
        {
            bhp = 1;
        }
    }

    string patterns[] = {"1001", "1100", "0011", "0110"};
    for (const string &pat : patterns)
    {
        if (isSubsequence(s, pat))
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1 && bhp == 0)
    {
        cout << 3 << endl;
        return;
    }
    else if (flag == 1 && bhp == 1)
    {
        cout << 4 << endl;
        return;
    }
    cout << n << endl;
    return;
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
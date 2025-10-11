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

void solution()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < k; i++)
    {
        if (s[i] == '0')
            c1++;
        if (s[i] == '1')
            c2++;
        if (s[i] == '2')
            c3++;
    }
    string s1(c1, '-');
    string s2(c2, '-');
    if (c3 + c1 + c2 >= n)
    {
        string ans(n, '-');
        println(ans);
        return;
    }
    string ans(n - c1 - c2, '+');
    int i = 0, j = n - c1 - c2 - 1;
    while (i <= j && c3 > 0)
    {
        ans[i] = '?';
        ans[j] = '?';
        i++;
        j--;
        c3--;
    }
    println(s1 + ans + s2);
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
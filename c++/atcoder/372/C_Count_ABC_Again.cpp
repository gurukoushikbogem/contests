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

void help(string &s, int &c, int r, char cr)
{
    if (s[r] == cr)
    {
        return;
    }

    if (cr == 'A')
    {
        if (r + 2 < s.size() && s[r + 1] == 'B' && s[r + 2] == 'C')
        {
            c++;
        }
    }
    if (cr == 'B')
    {
        if (r - 1 >= 0 && r + 1 < s.size() && s[r - 1] == 'A' && s[r + 1] == 'C')
        {
            c++;
        }
    }
    if (cr == 'C')
    {
        if (r - 2 >= 0 && s[r - 1] == 'B' && s[r - 2] == 'A')
        {
            c++;
        }
    }

    if (r + 2 < s.size() && s[r] == 'A' && s[r + 1] == 'B' && s[r + 2] == 'C' )
    {
        c--;
    }
    if (r - 1 >= 0 && r + 1 < s.size() && s[r - 1] == 'A' && s[r + 1] == 'C' && s[r] == 'B')
    {
        c--;
    }
    if (r - 2 >= 0 && s[r - 1] == 'B' && s[r - 2] == 'A' && s[r]=='C')
    {
        c--;
    }

    s[r] = cr;
}

void solution()
{
    int n, q;
    cin >> n >> q;
    string s, temp = "";
    cin >> s;
    int c = 0;
    for (int i = 0; i < 3; i++)
    {
        temp += s[i];
    }
    if (temp == "ABC")
    {
        c++;
    }
    for (int i = 3; i < n; i++)
    {
        temp.erase(temp.begin());
        temp += s[i];
        if (temp == "ABC")
        {
            c++;
        }
    }
    while (q--)
    {
        int r;
        char cr;
        cin >> r >> cr;
        help(s, c, r - 1, cr);
        cout << c << endl;
    }
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
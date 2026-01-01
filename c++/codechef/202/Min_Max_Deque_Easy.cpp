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

void solution()
{
    string a, b;
    cin >> a >> b;
    
    map<char, int> mp;
    for (auto &x : a)
        mp[x]++;

    string ans = "";
    bool bigger = false;

    for (int i = 0; i < b.size(); i++)
    {
        bool placed = false;

        if (!bigger)
        {
            if (mp[b[i]] > 0)
            {
                ans += b[i];
                mp[b[i]]--;
                continue;
            }

            for (char c = b[i] + 1; c <= 'z'; c++)
            {
                if (mp[c] > 0)
                {
                    ans += c;
                    mp[c]--;
                    bigger = true;
                    placed = true;
                    break;
                }
            }

            if (!placed)
            {
                while (!ans.empty())
                {
                    char last = ans.back();
                    ans.pop_back();
                    mp[last]++;

                    for (char c = last + 1; c <= 'z'; c++)
                    {
                        if (mp[c] > 0)
                        {
                            ans += c;
                            mp[c]--;
                            bigger = true;
                            placed = true;
                            break;
                        }
                    }
                    if (placed)
                        break;
                }
                if (!placed)
                {
                    println(-1);
                    return;
                }
            }
        }

        if (bigger)
        {
            for (auto &x : mp)
            {
                while (x.second--)
                    ans += x.first;
            }
            break;
        }
    }
    cout << ans;
    if (ans > b)
        println(ans);
    else
        println(-1);
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

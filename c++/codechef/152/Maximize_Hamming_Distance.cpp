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
    int n, m;
    cin >> n >> m;
    int yp=m;
    int kp = m;
    vector<int> v1(n), v2(n), v3(n);
    int sum = 0;
    vector<string> h;
    while (m--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                v1[i]++;
            else if (s[i] == '1')
                v2[i]++;
            else
            {
               v3[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (v3[i] > 0)
        {
            if (v1[i] > 0 && v2[i]>0)
            {
                sum+=max(v1[i],v2[i]);
                sum += v3[i];
            }
            else
            {
                if(v1[i]==0 && v2[i]==0){
                    sum+=yp;
                    sum--;
                }
                else{
                if(v1[i]==0)v1[i]++;
                else v2[i]++;
                v3[i]--;
                sum += max(v1[i], v2[i]);
                sum += v3[i];
                }
            }
        }
        else
        {
            if (v1[i] > 0 && v2[i] > 0)
                sum += max(v1[i], v2[i]);
        }
    }
    cout << sum << endl;
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
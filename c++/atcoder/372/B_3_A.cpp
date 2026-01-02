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

void help(vector<vector<int>> &ans,vector<pair<int, int>> &a, int m, int i, vector<int> &temp, int n)
{
    if(ans.size()>0){
        return;
    }

    if (m == 0)
    {
        if(temp.size()>20){
            return;
        }
        ans.push_back(temp);
        return;
    }
    if(m<0){
        return;
    }   
    if (i >= n)
    {
        return;
    }
    if (a[i].first <= m)
    {
        temp.push_back(a[i].second);
        help(ans,a, m - a[i].first, i, temp, n);
        temp.pop_back();
    }
    help(ans,a, m, i + 1, temp, n);
}

void solution(vector<pair<int, int>> &a)
{
    int m;
    cin >> m;
    vector<int> temp;
    vector<vector<int>>ans;
    help(ans,a, m, 0, temp, a.size());
    for(auto i:ans){
        cout<<i.size()<<endl;
        for(auto j:i){
            cout<<j<<" ";
        }
        break;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    vector<pair<int, int>> a;
    int g = 1, c = 0;

    for (int i = 0; i <= 10; i++)
    {
        a.push_back({g, c});
        g *= 3, c++;
    }
    reverse(a.begin(), a.end());
    while (t--)
    {
        solution(a);
    }
    return 0;
}
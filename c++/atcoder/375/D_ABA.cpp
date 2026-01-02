#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define INF 1e15
#define SORT(v) sort((v).begin(),(v).end())
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define mod (long long)(1e9 + 7)
#define vi vector<long long>
#define vvi vector< vector <long long> >
#define vc vector<char>
#define vpii vector< pair<long long,long long> >
#define endl "\n"
#define mpii map<long long,long long>
#define umpii unordered_map<long long, long long> 
#define mpci map<char,long long>
using namespace std;
template<class T>
void input(vector<T>&a){ for(auto &x : a)cin>>x; }



void solution()
{
    string s;
    cin>>s;
    int n = s.size();
    vector<vector<int>>dp(26);
    for(int i=0;i<n;i++){
        dp[s[i]-'A'].pb(i);
    }
    int ans=0;
    for (auto &positions : dp)
    {
        int m = positions.size();
        if (m < 2)
            continue;
        long long cumulative_sum = 0;
        for (int k = 1; k < m; k++)
        {
            cumulative_sum += positions[k - 1]; 
            ans += positions[k] * (k)-cumulative_sum - k;
        }
    }
    cout<<ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t=1;
    while(t--)
    {
       solution();
    }
    return 0;
}
#include<bits/stdc++.h>
#define int long long 
#define pb push_back
#define endl "\n"
#define mod ((int)(1e9) + 7ll)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define F first
#define S second
#define vi vector<int>
#define vc vector<char>
#define vpi vector<pair<int,int>>
#define si set<int>
#define pi pair<int,int>
#define mi map<int, int>
#define miv map<int,vector<int>>
using namespace std;

void solve(){

    int n = 600;

    vector<int> dp(n + 1, 0);
    dp[0] = 1; 

    for (int i = 1; i <= n; i++)
    {
        dp[i] += dp[i - 1];
    }

    for (int i = 2; i <= n; i++)
    {
        dp[i] += dp[i - 2];
    }

    for (int i = 3; i <= n; i++)
    {
        dp[i] += dp[i - 3];
    }

    cout<< dp[600] ;
}

signed main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1; 
    while(t--){
        solve();
    }
}


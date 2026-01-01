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
    string s;
    cin >> s;
    int ans1 = 1,ans2=1;
    int f1 = 0, f2 = 0, f3 = 0, f0 = 0;
    if(s[0]=='1'){
        ans1 += 10;
    } if (s[1] == '1')
    {
        ans1 += 10;
    }
    if (s[2] == '1')
    {
        ans2 += 10;
    }if (s[3] == '1'){
        ans2 += 10;
    }
    cout << ans1 * ans2 << endl;
}

signed main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1; cin>>t;
    while(t--){
        solve();
    }
}


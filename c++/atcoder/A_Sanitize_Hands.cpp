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
    int n, m;
    cin >> n >> m;
    vi v(n);
    int c = 0;
    for (int i = 0; i < n;i++){
        cin >> v[i];
        
    }
    for (int i = 0; i < n; i++)
    {
        if (m >= v[i])
        {
            m -= v[i];
            c++;
        }
        else{
            break;
        }
    }
    cout << c << endl;
}

signed main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1; 
    while(t--){
        solve();
    }
}


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

template<class T>
void print(vector<T>&a){
    for(auto &x: a)cout<<x<<" ";
    cout<<endl;
}

template<class T>
void print(T x){cout<<x<<" ";}

template<class T>
void println(T x){ cout<<x<<"\n";}



void solution()
{
    int n,m;
    cin>>n>>m;
    set<pair<int,int>> s;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        s.insert({x,y});
        if(x-1>0 && y-2>0)
            s.insert({x-1,y-2});
        if(x-1>0 && y+2<=n)
            s.insert({x-1,y+2});
        if(x+1<=n && y-2>0)
            s.insert({x+1,y-2});
        if(x+1<=n && y+2<=n)
            s.insert({x+1,y+2});
        if(x-2>0 && y-1>0)
            s.insert({x-2,y-1});
        if(x-2>0 && y+1<=n)
            s.insert({x-2,y+1});
        if(x+2<=n && y-1>0)
            s.insert({x+2,y-1});
        if(x+2<=n && y+1<=n)
            s.insert({x+2,y+1});
        
    }
    cout<<n*n-s.size()<<endl;
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
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
    int n;
    cin>>n;
    vector<int> a(n);
    input(a);
    int k=a[0];
    int ans=1;
    sort(a.begin(),a.end());
    int i1=-1,i2=n;
    for(int i=0;i<n;i++){
        if(a[i]==k){
            i1=i-1;
            i2=i+1;
            break;
        }
    }
   // cout<<i1<<" "<<i2<<endl;
    if(i1>=0){
        int y1=a[i1];
        int diff=abs(y1-k);
        diff/=2;
        ans+=diff;
    }
    else{
        ans+=k-1;
    }
    if(i2<n){
        int y2=a[i2];
        int diff=abs(y2-k);
        diff/=2;
        ans+=diff;
    }
    else{
        ans+=(1000000-k);
    }
    cout<<ans<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
       solution();
    }
    return 0;
}
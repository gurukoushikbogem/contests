#include<bits/stdc++.h>
#define ll long long
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

ll power(ll a,ll b,ll m)
{
    if(b==0)
        return 1;
    ll ans = 1;
    while (b > 0)
    {
        if(b&1)
            ans = (ans * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return ans;
}

void solution()
{
    int n;
    cin>>n;
    vi a(n);
    input(a);
    int ans=0;
    auto isprime = [](int x){
        if(x<2) return false;
        for(int i=2;i*i<=x;i++){
            if(x%i==0) return false;
        }
        return true;
    };
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(isprime(a[i]+a[j])) ans++;
        }
    }
    println(ans);
}
int main()
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
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
    vi a(n);
    input(a);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    int k1=(a[i]^a[j]);
                    int k2=(a[k]^a[l]);
                    int k3=(a[i]^a[l]);
                    int k4=(a[j]^a[k]);
                    if(k1==k2 && k3==k4){
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans*16<<endl;
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
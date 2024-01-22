// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define endl "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define int long long 

void remove(vector<long>&v, int index1){
    v.erase(v.begin()+index1);
}

void solve(){
    int n,w;
    cin>>n>>w;
    vector<int>w1(n);
    vector<int>v1(n);
    for(int i=0;i<n;i++){
        cin>>w1[i]>>v1[i];
    }
    int dp[n+1][w+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        int cw=w1[i-1];
        int cv=v1[i-1];
        for(int j=1;j<=w;j++){
            if(cw<=j){
                dp[i][j]=max(cv+dp[i-1][j-cw],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=w;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n][w]<<endl;
}
// long long dp[n+1][w+1];
int dp[105][100006];
int func(vector<int>& w1, vector<int>& v1, int w, int index){
    if(index<0){
        return 0;
    }
    if(w==0){
        return 0;
    }
    if(dp[index][w]!=-1){
        return dp[index][w];
    }
    int ans1=func(w1,v1,w,index-1);
    if(w1[index]<=w){
        ans1=max(ans1,func(w1,v1,w-w1[index],index-1)+v1[index]);
    }
    dp[index][w]=ans1;
    return dp[index][w];
}
signed main()
{
    // fast_cin();
    // solve();
    memset(dp,-1,sizeof(dp));
    int n,w;
    cin>>n>>w;
    vector<int>w1;
    vector<int>v1;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        w1.pb(x);
        v1.pb(y);
    }
    // cout<<func(w1,v1,w,n-1)<<endl;
    cout<<func1(w1,v1,w,n-1)<<endl;
    return 0;
}

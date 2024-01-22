#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
int sum(int bit[], int index){
    int sum1=0;
    for(int i=index;i>0;i-=(i&(-i))){
      sum1+=bit[i];
    }
    return sum1;
}
/*To add a val to index i*/
void update(int bit[], int index, int last, int x){
    for(int i=index;i<=last;i+=(i&(-i))){
        bit[i]+=x;
    }
}

bool fibo(int x, int y, int n, vector<int>& v1){
    if(n==1){
        return true;
    }
    int val1=min(y,v1[n+1]-y+1);

    int val2=v1[n+1]-v1[n];

    if(val1>val2){
        return false;
    }
    y=min(y,v1[n+1]-y+1);
    return fibo(y,x,n-1,v1);
}

void solve(vector<int>& v1){
    int n,x,y;
    cin>>n>>x>>y;

    if(fibo(x,y,n,v1)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
signed main()
{
    fast_cin();
    ll t;
    cin >> t;
    vector<int>v1;
    v1.pb(1);
    v1.pb(1);
    for(int i=0;i<=45;i++){
        v1.pb(v1[i]+v1[i+1]);
    }
    while(t--){
        solve(v1);
    }
    return 0;
}

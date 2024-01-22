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

int binarysearch(int& cost, int& total, int& x, int st, int end, int val){
    if(st<=end){
        int mid=(st+end)/2;
        int final=cost+(total*mid);
        if(final<=x){
            val=max(val,mid);
            return binarysearch(cost, total, x, mid+1, end, val);
        }
        else{
            return binarysearch(cost, total, x, st, mid-1, val);
        }
    }
    else{
        return val+1;
    }
}

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int>v;
    vector<int>prefix;
    int sum1=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.pb(x);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        sum1+=v[i];
        prefix.pb(sum1);
    }
    int extra=0;
    int ans=0;
    for(int i=0;i<n;i++){
        int cost=prefix[i];
        int j=i+1;
        int add=binarysearch(cost,j,x,0,x,-1);
        if(add==0){
            break;
        }
        ans+=add;
    }
    cout<<ans<<endl;
}
signed main()
{
    fast_cin();
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

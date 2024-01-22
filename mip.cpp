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

void solve(){
    int n,c,d;
    cin>>n>>c>>d;
    unordered_map<int,int>amap;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        amap[x]++;
    }
    int ans=0;
    int diff=n-amap.size();
    ans+=(c*diff);
    vector<int>v;
    for(auto i:amap){
        v.pb(i.first);
    }
    sort(v.begin(),v.end());
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    if(v.size()==1){
        int val=(v[0]-0-1)*d;
        int ans1=min(val+ans,(c*n)+d);
        cout<<ans1<<endl;
    }
    else{
        vector<int>min1;
        int cost=(v[0]-0-1)*(d);
        min1.pb(cost+((v.size()-1)*c));
        // cout<<cost<<" ";
        // cout<<cost+((v.size()-1)*c)<<" ";
        for(int i=1;i<v.size();i++){
            cost+=((v[i]-v[i-1]-1)*(d));
            // cout<<cost<<" ";
            int val=cost+((v.size()-i-1)*c);
            // cout<<val<<" ";
            min1.pb(val);
        }
        // cout<<endl;
        int minel=LLONG_MAX;
        for(int i=0;i<min1.size();i++){
            minel=min(minel,min1[i]);
            // cout<<min1[i]<<" ";
        }
        // cout<<endl;
        int ans1=min(minel+ans,(c*n)+d);
        cout<<ans1<<endl;
    }
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

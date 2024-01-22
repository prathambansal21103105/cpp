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
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void remove(vector<long>&v, int index1){
    v.erase(v.begin()+index1);
}

void solve(){
    int n;
    cin>>n;
    vector<int>v;
    int min1=INT_MAX;
    int max1=INT_MIN;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x>max1){
            max1=x;
        }
        if(x<min1){
            min1=x;
        }
        v.push_back(x);
    }
    if(v[0]==min1 or v[n-1]==max1){
        cout<<max1-min1<<endl;
        return;
    }
    int ans=INT_MIN;
    for(int i=0;i<n-1;i++){
        int diff=v[i]-v[i+1];
        if(diff>ans){
            ans=diff;
        }
    }
    ans=max(ans,v[n-1]-v[0]);
    for(int i=1;i<n;i++){
        int diff=v[i]-v[0];
        if(diff>ans){
            ans=diff;
        }
    }
    for(int i=0;i<n-1;i++){
        int diff=v[n-1]-v[i];
        if(diff>ans){
            ans=diff;
        }
    }
    cout<<ans<<endl;

}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

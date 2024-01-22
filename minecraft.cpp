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
#define int long long
 
void remove(vector<long>&v, int index1){
    v.erase(v.begin()+index1);
}
 
// void solve(){
 
// }
signed main()
{
    fast_cin();
    // ll t;
    // cin >> t;
    // while(t--){
    //     solve();
    // }
    int n,m;
    cin>>n>>m;
    vector<int>v;
    vector<vector<int> > vect1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        vector<int>v1;
        v1.push_back(x-1);
        v1.push_back(y-1);
        vect1.push_back(v1);
    }
    int sum=0;
    vector<int>prefix;
    prefix.push_back(0);
    for(int i=1;i<n;i++){
        if(v[i]<v[i-1]){
            sum+=abs(v[i]-v[i-1]);
        }
        prefix.push_back(sum);
    }
    vector<int>prefix1;
    prefix1.push_back(0);
    sum=0;
    for(int i=n-2;i>=0;i--){
        if(v[i]<v[i+1]){
            sum+=abs(v[i]-v[i+1]);
        }
        prefix1.push_back(sum);
    }
    for(int i=0;i<m;i++){
        if(vect1[i][0]<=vect1[i][1]){
            cout<<abs(prefix[vect1[i][0]]-prefix[vect1[i][1]])<<endl;
        }
        else{
            cout<<abs(prefix1[n-1-vect1[i][0]]-prefix1[n-1-vect1[i][1]])<<endl;
        }
    }
 
    return 0;
}
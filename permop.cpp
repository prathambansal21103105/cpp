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
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.pb(x);
    }
    if(n==1){
        cout<<1<<endl;
        return;
    }
    vector<vector<int> >v1;
    for(int i=1;i<n;i++){
        vector<int>vnew;
        if(v[i]<v[i-1]){
            vnew.pb(v[i-1]-v[i]);
        }
        else{
            continue;
        }
        vnew.pb(i+1);
        v1.pb(vnew);
    }
    map<int,int>amap;
    map<int,int>indexes;
    for(int i=0;i<v1.size();i++){
        if(amap.count(v1[i][0])==0){
            amap[v1[i][0]]++;
        }
        else{
            while(amap.count(v1[i][0])!=0){
                v1[i][0]++;
            }
            amap[v1[i][0]]++;
        }
    }
    map<int,int>amap1;
    for(int i=0;i<v1.size();i++){
        amap1[v1[i][0]]=v1[i][1];
        indexes[v1[i][1]]++;
    }
    vector<int>index;
    for(int i=1;i<=n;i++){
        if(indexes.count(i)!=0){
            continue;
        }
        index.pb(i);
    }
    int k=0;
    for(int i=1;i<=n;i++){
        if(amap1.count(i)==0){
            cout<<index[k]<<" ";
            k++;
        }
        else{
            cout<<amap1[i]<<" ";
        }
    }
    cout<<endl;

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

/*
4 1 3 2
5 2 4 3
5 2 6 5
5 5 9 8
5 5 9 12


4 1 3 2

5 2 4 3
5 2 6 5
5 2 6 8
5 6 10 12

4 1 3 2
0 3 0 1

*/
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
void func(vector<int>& d, vector<int>a, int index){
    if(index==d.size()-1){
        if(a[index-1]+d[index]>=0 and a[index-1]-d[index]>=0 and a[index-1]+d[index]!=a[index-1]-d[index]){
            cout<<-1<<endl;
            return;
        }
        if(a[index-1]+d[index]>=0){
            a.pb(a[index-1]+d[index]);
            for(int i=0;i<a.size();i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        else if(a[index-1]-d[index]>=0){
            a.pb(a[index-1]-d[index]);
            for(int i=0;i<a.size();i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
            return;
        }
    }
    else{
        if(a[index-1]+d[index]>=0 and a[index-1]-d[index]>=0 and a[index-1]+d[index]!=a[index-1]-d[index]){
            cout<<-1<<endl;
            return;
        }
        if(a[index-1]+d[index]>=0){
            a.pb(a[index-1]+d[index]);
            func(d,a,index+1);
        }
        else if(a[index-1]-d[index]>=0){
            a.pb(a[index-1]-d[index]);
            func(d,a,index+1);
        }
        else{
            cout<<-1<<endl;
            return;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int>d;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        d.pb(x);
    }
    if(n==1){
        cout<<d[0]<<endl;
        return;
    }
    vector<int>a;
    a.pb(d[0]);
    func(d,a,1);

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
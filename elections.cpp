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

void remove(vector<long>&v, int index1){
    v.erase(v.begin()+index1);
}

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b and b==c){
        cout<<1<<" "<<1<<" "<<1<<endl;
    }
    else if(a==b){
        if(b>c){
            cout<<1<<" "<<1<<" "<<b-c+1<<endl;
        }
        else{
            cout<<c-a+1<<" "<<c-b+1<<" "<<0<<endl;
        }
    }
    else if(b==c){
        if(b>a){
            cout<<b-a+1<<" "<<1<<" "<<1<<endl;
        }
        else{
            cout<<0<<" "<<a-b+1<<" "<<a-c+1<<endl;
        }
    }
    else if(a==c){
        if(a>b){
            cout<<1<<" "<<a-b+1<<" "<<1<<endl;
        }
        else{
            cout<<b-a+1<<" "<<0<<" "<<b-c+1<<endl;
        }
    }
    else{
        int max1=max(a,max(b,c));
        if(max1==a){
            cout<<0<<" ";
        }
        else{
            cout<<max1-a+1<<" ";
        }
        if(max1==b){
            cout<<0<<" ";
        }
        else{
            cout<<max1-b+1<<" ";
        }
        if(max1==c){
            cout<<0<<endl;
        }
        else{
            cout<<max1-c+1<<endl;
        }
    }
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

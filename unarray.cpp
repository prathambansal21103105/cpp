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

void solve(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.pb(x);
    }
    if(v.size()==2 or v.size()==1){
        cout<<0<<endl;
        return;
    }
    if(v.size()==3){
        if(v[0]==v[1] and v[1]==v[2]){
            cout<<1<<endl;
            return;
        }
        else{
            cout<<0<<endl;
            return;
        }
    }
    int count=0;
    for(int i=0;i<n-1;i++){
        if(v[i]==v[i+1]){
            count++;
        }
    }
    if(count==0 or count==1){
        cout<<0<<endl;
    }
    else{
        int f=0;
        int s=0;
        int flag=0;
        for(int i=0;i<n-1;i++){
            if(flag==0){
                if(v[i]==v[i+1]){
                    f=i;
                    flag=1;
                }
            }
            if(v[i]==v[i+1]){
                s=i;
            }
        }
        // cout<<s<<" "<<f<<endl;
        if(s-f==1){
            cout<<1<<endl;
        }
        else{
            cout<<s-f-1<<endl;
        }
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

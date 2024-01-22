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
    int x;
    cin>>x;
    string s;
    cin>>s;
    vector<int>v;
    vector<int>vnew;
    vector<int>v1;
    for(int i=0;i<s.length();i++){
        int r=s[i]-'0';
        v.pb(r);
        vnew.pb(0);
        v1.pb(1);
    }
    if(v.size()==1 and v[0]==9){
        cout<<2<<endl;
        return;
    }
    if(v[0]==9){
        // cout<<"YES"<<endl;
        int flag=0;
        for(int i=x-1;i>=0;i--){
            if(v1[i]+flag>=v[i]){
                vnew[i]=v1[i]+flag-v[i];
                flag=0;
            }
            else{
                vnew[i]=v1[i]+flag+10-v[i];
                flag=-1;
            }
        }
    }
    else{
        // cout<<"NO"<<endl;
        for(int i=0;i<v.size()/2;i++){
            int j=v.size()-1-i;
            vnew[i]=9-v[i];
            vnew[j]=9-v[j];
        }
    }
    for(int i=0;i<vnew.size();i++){
        cout<<vnew[i];
    }
    cout<<endl;
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
/*
9 0 9
2 0 2
 
999
222
1201
 
9199
2012
11211
99
22
1
*/
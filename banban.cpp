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
    if(n%2==0){
        cout<<n/2<<endl;
        int j=(n*3/2)+1;
        int i=0;
        int k=0;
        while(k<n/2){
            cout<<i+1<<" "<<j+1<<endl;
            i+=3;
            j+=3;
            k+=1;
        }
    }
    else{
        if(n==1){
            cout<<1<<endl;
            cout<<1<<" "<<2<<endl;
        }
        else{
            int j=(n*3)-2;
            int i=0;
            int k=0;
            vector<vector<int>>v;
            while(j>i){
                if((j+1)%3==1){
                    j-=1;
                }
                vector<int>v1;
                v1.push_back(i+1);
                v1.push_back(j+1);
                v.push_back(v1);
                i+=3;
                j-=3;
                k+=1;
            }
            cout<<v.size()<<endl;
            for(int i=0;i<v.size();i++){
                cout<<v[i][0]<<" "<<v[i][1]<<endl;
            }
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
/*
BANBANBAN
BANBANBANBAN
AANAANBBNBBN

BANBANBANBANBANBAN
BAN
ANB

BAN BAN BAN

BAN BAN BAN BAN BAN BAN BAN

*/
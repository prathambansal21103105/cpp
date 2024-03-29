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


void solve(){
    int n,k;
    cin>>n>>k;
    int count1=0;
    v32 v;
    int temp=k;
    int left=n;
    int diff=1;
    while(temp>=left){
        if(left>0){
            v.push_back(temp);
        }
        else{
            break;
        }
        temp-=diff;
        left-=1;
        diff+=1;
    }
    int x=v[v.size()-1];
    for(int i=x-1;i>=0;i--){
        if(left>0){
            v.push_back(i);
            left-=1;
        }
        else{
            break;
        }
    }
    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i]<<" ";
    }
    cout<<endl;

}

int main(){

    fast_cin();
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

/*
4 12
12 4
11 3
9 2
6 1

8 11
11 8
10 7
8  6
5  5
1  4

*/
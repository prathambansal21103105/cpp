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
    int n,m;
    cin>>n>>m;
    vector<int>v1;
    v1.push_back(1);
    int count=0;
    int last=-1;
    for(int i=0;i<m-2;){
        if(count%2==0){
            v1.push_back(0);
            v1.push_back(0);
            last=0;
            count+=1;
            i+=2;
        }
        else{
            v1.push_back(1);
            v1.push_back(1);
            last=1;
            count+=1;
            i+=2;
        }
    }
    if(last==0){
        v1.push_back(1);
    }
    else{
        v1.push_back(0);
    }
    vector<int>v2;
    for(int i=0;i<m;i++){
        if(v1[i]==0){
            v2.push_back(1);
        }
        else{
            v2.push_back(0);
        }
    }
    count=0;
    vector<vector<int> > v3;
    for(int i=0;i<n;){
        if(count%2==0){
            v3.push_back(v1);
            v3.push_back(v2);
            count+=1;
            i+=2;
        }
        else{
            v3.push_back(v2);
            v3.push_back(v1);
            count+=1;
            i+=2;
        }
    }
    for(int i=0;i<v3.size();i++){
        for(int j=0;j<v3[i].size();j++){
            cout<<v3[i][j]<<" ";
        }
        cout<<endl;
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
n==4
m==6

1 0 0 1 1 0 
0 1 1 0 0 1
0 1 1 0 0 1
1 0 0 1 1 0


*/
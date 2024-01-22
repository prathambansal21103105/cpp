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
int binary(int& n, int st, int end, int val, int& flag){
    if(st<=end){
        int mid=(st+end)/2;
        if(mid*mid==n){
            flag=1;
            return mid;
        }
        else if(mid*mid<n){
            val=max(val,mid);
            return binary(n,mid+1,end,val,flag);
        }
        else{
            return binary(n,st,mid-1,val,flag);
        }
    }
    else{
        flag=0;
        return val;
    }
}
int solve(int n){
    if(n==1){
        return 0;
    }
    else{
        int flag=-1;
        int x=binary(n,1,1e9,0,flag);
        if(flag==1){
            if(x&1){
                return x-1;
            }
            else{
                return x;
            }
        }
        else{
            if(x&1){
                return x+1;
            }
            else{
                return x;
            }
        }
    }
}
int solve1(int n){
    if(n==1){
        return 0;
    }
    else{
        int flag=-1;
        int x=binary(n,1,1e9,0,flag);
        if(flag==1){
            if(x&1){
                return x;
            }
            else{
                return x-1;
            }
        }
        else{
            if(x&1){
                return x;
            }
            else{
                return x+1;
            }
        }
    }
}
signed main()
{
    fast_cin();
    ll t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        cout<<min(solve(n),solve1(n))<<endl;
    }
    return 0;
}

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

int power(int n, int bits){
    if(bits==0){
        return 1;
    }
    return (n*(power(n,bits-1)))%(1000000007);
}

void solve(){
    int n,k;
    cin>>n>>k;
    int ans=0;
    while(k>0){
        int y=1;
        int bits=0;
        int add=1;
        int ans1=0;
        int lastcheck=0;
        for(int i=1;i<=31;i++){
            y*=2;
            int check=y-1;
            if(check<=k){
                bits=i;
                ans1=ans1%(1000000007);
                add=add%(1000000007);
                ans1+=add;
                add=((add%(1000000007))*(n%(1000000007)))%(1000000007);
                ans1=ans1%(1000000007);
                add=add%(1000000007);
                lastcheck=check;
            }
        }
        k-=lastcheck;
        if(k==0){
            ans+=ans1;
            ans=ans%(1000000007);
        }
        else{
            int x=power(n,bits)%(1000000007);
            ans+=x;
            ans=ans%(1000000007);
            k-=1;
        }
    }
    cout<<ans<<endl;
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
// 1 1 1 1 1 1
// 5 4 3 2 1 0
// 243 81 27 9 3 1


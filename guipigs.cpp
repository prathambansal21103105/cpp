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

int gv(int x){
    if(x&1){
        return (x-1)/2;
    }
    else{
        return (x-2)/2;
    }
}
int ex(int x){
    if(x&1){
        return x-gv(x)-1;
    }
    else{
        return x-gv(x)-1;
    }
}
void check(int& z, int& extra){
    if(z>2){
        if(z&1){
            extra+=(z/2);
            z=1;
        }
        else{
            extra+=((z-2)/2);
            z=2;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int>v;
    int count1=0;
    int flag=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==1){
            flag=1;
        }
        if(flag==1){
            v.pb(x);
        }
    }
    n=v.size();
    if(n==0){
        cout<<0<<endl;
        return;
    }
    // for(int i=0;i<n;i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    flag=0;
    int av=0;
    int extra=0;
    int z=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(v[i]==2){
            z+=av;
            check(z,extra);
            // int add1=ex(av);
            // extra+=add1;
            // if(av%2==0){
            //     z+=2;
            //     check(z,extra);
            // }
            // else{
            //     z++;
            //     check(z,extra);
            // }
            av=0;
            flag=1;
        }
        else{
            if(extra>0 and flag==1){
                extra--;
                z++;
            }
            else{
                ans++;
                av++;
            }
        }
        // cout<<ans<<" "<<extra<<" "<<z<<endl;
    }
    // cout<<ans<<" "<<extra<<" "<<z<<" "<<av<<endl;
    cout<<ans<<endl;
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

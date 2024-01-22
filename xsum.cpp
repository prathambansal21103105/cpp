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
    vector<vector<int> >v;
    vector<vector<int> >vnew;
    for(int i=0;i<n;i++){
        vector<int>v1;
        vector<int>v2;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            v1.pb(x);
            v2.pb(0);
        }
        v.pb(v1);
        vnew.pb(v2);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int currx=i;
            int curry=j;
            int sum=0;
            while(currx<n and curry<m){
                sum+=v[currx][curry];
                currx++;
                curry++;
            }
            currx=i;
            curry=j;
            while(currx<n and curry>=0){
                sum+=v[currx][curry];
                currx++;
                curry--;
            }
            currx=i;
            curry=j;
            while(currx>=0 and curry>=0){
                sum+=v[currx][curry];
                currx--;
                curry--;
            }
            currx=i;
            curry=j;
            while(currx>=0 and curry<m){
                sum+=v[currx][curry];
                currx--;
                curry++;
            }
            vnew[i][j]=sum-(3*v[i][j]);
        }
    }
    int max1=0; 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            max1=max(max1,vnew[i][j]);
        }
    }
    cout<<max1<<endl;
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

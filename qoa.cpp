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

bool func(pair<int,int>& a, pair<int,int>& b){
    return a.second<b.second;
}
// class offer{
//     public:
//     string name="";
//     int days=0;
//     int cost=0;
// }

void solve(){
    int n;
    cin>>n;
    map<string,int>amap;
    map<string,vector<pair<int,int> > > amap1;
    // vector<offer>v;
    for(int i=0;i<n;i++){
        // offer y;
        string x;
        cin>>x;
        int days;
        cin>>days;
        int cost;
        cin>>cost;
        // y.name=x;
        // y.days=days;
        // y.cost=cost;
        amap[x]+=days;
        pair<int,int>p;
        p.first=days;
        p.second=cost;
        amap1[x].push_back(p);
    }
    // vector<pair<int,int>>
    // sort(v.begin(),v.end(),func);
    vector<int>v1;
    for(auto i:amap){
        v1.pb(i.second);
    }
    sort(v1.begin(),v1.end());
    int max1=0;
    int total=v1.size();
    int val=0;
    for(int i=0;i<v1.size();i++){
        if(v1[i]*(total-i)>max1){
            max1=v1[i]*(total-i);
            val=v1[i];
        }
    }
    cout<<max1<<" ";
    int ans=0;
    for(auto i:amap){
        if(i.second>=val){
            string name=i.first;
            sort(amap1[name].begin(),amap1[name].end(),func);
            int count=0;
            int val1=val;
            for(int j=0;j<amap1[name].size();j++){
                if(amap1[name][j].first>=val1){
                    ans+=(amap1[name][j].second*val1);
                    val1=0;
                    break;
                }
                else{
                    ans+=(amap1[name][j].second*amap1[name][j].first);
                    val1-=amap1[name][j].first;
                }
            }
        }
    }
    cout<<ans<<endl;


}
signed main()
{
    fast_cin();
    solve();
    return 0;
}

/*
8
l 2 100
d 1 50
p 3 200
r 2 100
l 1 40
p 1 80
b 5 170
d 3 75

5
n 4 100
b 3 10
n 2 15
w 1 12
p 3 80
*/
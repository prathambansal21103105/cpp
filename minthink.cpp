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
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.pb(x);
    }
    vector<int>pre;
    unordered_map<int,int>amap;
    int sum1=0;
    for(int i=0;i<n;i++){
        sum1+=v[i];
        // cout<<sum1<<" ";
        pre.pb(sum1);
        amap[sum1]=i;
    }
    // cout<<endl;
    vector<int>ind;
    for(int i=0;i<n;i++){
        if(pre[n-1]%pre[i]==0){
            ind.pb(i);
        }
    }
    if(ind.size()==1){
        cout<<n<<endl;
    }
    else{
        int min1=INT_MAX;
        for(int i=0;i<ind.size();i++){
            int curr=pre[ind[i]];
            int last=pre[n-1];
            int range=last/curr;
            int diff=0;
            int nex=n-1;
            int prev=0;
            for(int j=range-1;j>=1;j--){
                if(amap.count(curr*j)!=0){
                    prev=amap[curr*j];
                    diff=max(diff,nex-prev);
                    nex=prev;
                }
                else{
                    diff=0;
                    break;
                }
            }
            if(diff==0){
                continue;
            }
            diff=max(diff,nex+1-0);
            // cout<<curr<<endl;
            min1=min(min1,diff);
        }
        if(min1==INT_MAX){
            cout<<n<<endl;
        }
        else{
            cout<<min1<<endl;
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

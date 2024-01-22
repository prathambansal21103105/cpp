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

void solve(){
    int n;
    cin>>n;
    vector<int>v;
    map<int,int>amap;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.pb(x);
        amap[x]++;
    }
    if(amap[1]==2){
        cout<<"NO"<<endl;
        return;
    }
    vector<int>v1;
    unordered_map<int,int>ans;
    unordered_map<int,int>ans1;

    map<int,int>newmap;
    for(int i=1;i<=n;i++){
        if(amap[i]==0){
            v1.pb(i);
            v1.pb(i);
        }
        else if(amap[i]==1){
            ans[i]=i;
        }
        else if(amap[i]==2){
            newmap[i]=2;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    int j=0;
    for(auto i:newmap){
        if(j==v1.size()){
            cout<<"NO"<<endl;
            return;
        }
        else{
            if(i.first>v1[j]){
                ans[i.first]=v1[j];
                ans1[i.first]=v1[j];
                j++;
                j++;
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    vector<int>x1;
    vector<int>x2;
    for(int i=0;i<n;i++){
        if(ans[v[i]]!=0){
            x1.pb(v[i]);
            x2.pb(ans[v[i]]);
            ans[v[i]]=0;
        }
        else{
            x1.pb(ans1[v[i]]);
            x2.pb(v[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(x1[i]>=1 and x1[i]<=n){
            continue;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i=0;i<n;i++){
        if(x2[i]>=1 and x2[i]<=n){
            continue;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        cout<<x1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<x2[i]<<" ";
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

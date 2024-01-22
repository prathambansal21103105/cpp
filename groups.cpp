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
    vector<vector<int> >v;
    for(int i=0;i<n;i++){
        vector<int>v1;
        for(int j=0;j<5;j++){
            int x;
            cin>>x;
            v1.pb(x);
        }
        v.pb(v1);
    }
    if(n&1){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            int x=0;
            int y=0;
            int z=0;
            int flag=0;
            for(int k=0;k<n;k++){
                if(v[k][i]==1 and v[k][j]==1){
                    z++;
                } 
                else if(v[k][i]==1){
                    x++;
                }
                else if(v[k][j]==1){
                    y++;
                }
                else{
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                continue;
            }
            if(x+y==n and x==y){
                cout<<"YES"<<endl;
                return;
            }
            else{
                if(x==y){
                    cout<<"YES"<<endl;
                    return;
                }
                else if(x<y){
                    if(x+z<y){
                        continue;
                    }
                    else{
                        cout<<"YES"<<endl;
                        return;
                    }
                }
                else{
                    if(y+z<x){
                        continue;
                    }
                    else{
                        cout<<"YES"<<endl;
                        return;
                    }
                }
            }
        }
    }
    cout<<"NO"<<endl;
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

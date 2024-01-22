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
    vector<int>v1;
    vector<int>indo[100001];
    vector<int>inde[100001];
    int dp[100001]={0};
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.pb(x);
        v1.pb(1);
        dp[x]=1;
    }
    for(int i=0;i<n;i++){
        int val=v[i];
        int score=0;
        if(indo[val].size()==0 and i%2==0){
            if(i%2==0){
                inde[val].pb(i);
            }
            else{
                indo[val].pb(i);
            }
            continue;
        }
        else if(inde[val].size()==0 and i%2!=0){
            if(i%2==0){
                inde[val].pb(i);
            }
            else{
                indo[val].pb(i);
            }
            continue;
        }
        else{
            if(i%2==0){
                int j=indo[val].size()-1;
                int k=indo[val][j];
                score=1+v1[k];
                dp[val]=max(dp[val],score);
            }
            else{
                int j=inde[val].size()-1;
                int k=inde[val][j];
                score=1+v1[k];
                dp[val]=max(dp[val],score);
            }
            v1[i]=max(v1[i],score);
            if(i%2==0){
                inde[val].pb(i);
            }
            else{
                indo[val].pb(i);
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<v1[i]<<" ";
    // }
    // cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" "; 
    }
    cout<<endl;
    // cout<<endl;


}
int main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
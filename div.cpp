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
#define int long long

void remove(vector<long>&v, int index1){
    v.erase(v.begin()+index1);
}

void solve(){
    int n;
    cin>>n;
    vector<int>v;
    vector<int>v1;
    int count=0;
    vector<int>ind;
    int val=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.pb(x);
        int temp=x;
        if(i%2==0 and i!=0){
            if(i&(i-1)==0){
                val+=1;
                ind.pb(val);
            }
        }
        int temp1=i;
        int add=0;
        if(temp1!=0 and temp1%2==0){
            while(temp1%2==0){
                temp1=temp1/2;
                add++;
            }
            v1.pb(add);
        }
        if(temp%2==0){
            while(temp%2==0){
                temp=temp/2;
                count++;
            }
        }
    }
    if(count>=n){
        cout<<0<<endl;
    }
    else{
        int diff=n-count;
        int sum1=0;
        int ans=0;
        for(int i=v1.size()-1;i>=0;i--){
            if(sum1<diff){
                sum1+=v1[i];
                ans++;
            }
            else{
                break;
            }
        }
        cout<<ans<<endl;
    }
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

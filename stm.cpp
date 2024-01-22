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
int func(string& s, vector<int>v, int sum, int index, int n){
    if(index==n-1){
        if(s[index]=='1'){
            sum+=v[index];
        }
        return sum;
    }
    else{
        if(s[index]=='0' and s[index+1]=='1'){
            string s1=s;
            s1[index+1]='0';
            int sum1=sum;
            sum1+=v[index];
            int ans1=func(s1,v,sum1,index+1,n);
            int ans2=func(s,v,sum,index+1,n);
            return max(ans1,ans2);
        }
        else{
            if(s[index]=='0'){
                return func(s,v,sum,index+1,n);
            }
            else{
                return func(s,v,sum+v[index],index+1,n);
            }
        }
    }
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>v;
    vector<int>dp;
    v.pb(0);
    s='0'+s;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.pb(x);
        dp.pb(0);
    }
    // int ans=func(s,v,0,0,n);
    int ans=0;
    int i=0;
    while(i<=n){
        int min1=v[i];
        int sum1=min1;
        int j=i+1;
        while(j<=n and s[j]=='1'){
            min1=min(min1,v[j]);
            sum1+=v[j];
            j++;
        }
        ans+=(sum1-min1);
        i=j;
    }
    cout<<ans<<endl;
    // int sum=0;
    // if(s[0]=='1'){
    //     sum+=v[0];
    //     dp.pb(v[i]);
    // }
    // else{
    //     dp.pb(0);
    // }
    // for(int i=1;i<n;i++){
    //     if(s[i]=='1' and s[i-1]=='0' and s[i+1]=='0'){
    //         if(v[i]>v[i-1]){
    //             sum+=v[i];
    //         }
    //         else{
    //             sum+=v[i-1];
    //             s[i-1]='1';
    //             s[i]='0';
    //         }
    //     }

    // }
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

/*

20 10 4 50 100

  0 1  2  3  4  5
0 0  0  0  0  0  0
1 M 20 20 20 20 20
2 M 40 10 10 10 10
3 M 60 30 4  4  4
4 M 80 20 20 20 20
5 M100 30 14 14 14  


*/
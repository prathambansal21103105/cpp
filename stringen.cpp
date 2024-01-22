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
bool func(string& s, string& m, int st, int end, int ind, int** dp){
    int i=st;
    int j=end;
    int k=ind;
    if(dp[i][j]!=-1){
        if(dp[i][j]==0){
            return false;
        }
        else{
            return true;
        }
    }
    while(i<j){
        // cout<<i<<" "<<j<<" "<<k<<endl;
        if(s[k]==m[i] and s[k]==m[j]){
            bool check1=func(s,m,i+1,j,k-1,dp) or func(s,m,i,j-1,k-1,dp);
            dp[i][j]=check1;
            return dp[i][j];
        }
        else if(s[k]==m[i]){
            k--;
            i++;
        }
        else if(s[k]==m[j]){
            k--;
            j--;
        }
        else{
            dp[st][end]=0;
            return false;
        }
    }
    return dp[st][end];
}
void solve(int count){
    int l;
    cin>>l;
    string s,m;
    cin>>s>>m;
    int **dp =new int*[l+1];
    for(int i=0;i<=l;i++){
        dp[i]=new int[l+1];
    }
    for(int i=0;i<=l;i++){
        for(int j=0;j<=l;j++){
            dp[i][j]=-1;
        }
    }
    if(func(s,m,0,l-1,l-1,dp)){
        cout<<"Case "<<count<<": YES"<<endl;
    }
    else{
        cout<<"Case "<<count<<": NO"<<endl;
    }
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    int count=1;
    while(t--){
        solve(count);
        count++;
    }
    return 0;
}

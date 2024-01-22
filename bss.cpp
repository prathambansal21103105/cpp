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
const int m=1e12;
const int M=(1e12)+1;

void remove(vector<long>&v, int index1){
    v.erase(v.begin()+index1);
}

int func(string& str, int index, int prev, int k){
    int i=index;
    if(index>=str.length()){
        return 0;
    }
    else{
        if(str[i]=='1' and str[prev]=='1'){
            k++;
            return func(str,index+1,prev,k);
        }
        else if(str[i]=='0' and str[prev]=='1'){
            int x=M+func(str,index+1,prev-1,k-1);
            str[i]='1';
            int y=(k*m)+func(str,index+1,k);
            return min(x,y);
        }
        else{
            return func(str,index+1,k);
        }
    }
}

void solve(){
    string s;
    cin>>s;
    int x=-1;
    int y=-1;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            x=i;
            break;
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            y=i;
        }
    }
    int first1=x;
    int last0=y;
    if(first1==-1){
        cout<<0<<endl;
    }
    else if(last0==-1){
        cout<<0<<endl;
    }
    else{
        if(last0<first1){
            cout<<0<<endl;
        }
        else{
            string str="";
            for(int i=first1;i<=last0;i++){
                str+=s[i];
            }
            cout<<"str :"<<str<<endl;
            int m=1e12;
            int M=m+1;
            int n=str.length();
            // delete cost=M
            // swap cost=m
            int dp[n+1];
            if(n==1){
                cout<<0<<endl;
            }
            int ans=func(str,1,0,1);
            cout<<ans<<endl;
        }
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

/*
011101100
*/
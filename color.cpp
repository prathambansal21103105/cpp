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
    string s;
    cin>>s;
    string str="";
    str+=s[0];
    for(int i=1;i<n;i++){
        if(s[i]==str[str.size()-1]){
            continue;
        }
        else{
            str+=s[i];
        }
    }
    if(str.size()==1){
        if(str[0]=='W'){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        return;
    }
    for(int i=0;i<str.size();i++){
        if(i==0){
            if(str[i]=='B'){
                if(str[i+1]=='R'){
                    continue;
                }
                else{
                    cout<<"NO"<<endl;
                    return;
                }
            }
            else if(str[i]=='R'){
                if(str[i+1]=='B'){
                    continue;
                }
                else{
                    cout<<"NO"<<endl;
                    return;
                }
            }
            else{
                continue;
            }
        }
        else if(i==str.size()-1){
            if(str[i]=='B'){
                if(str[i-1]=='R'){
                    continue;
                }
                else{
                    cout<<"NO"<<endl;
                    return;
                }
            }
            else if(str[i]=='R'){
                if(str[i-1]=='B'){
                    continue;
                }
                else{
                    cout<<"NO"<<endl;
                    return;
                }
            }
            else{
                continue;
            }
        }
        else{
            if(str[i]=='B'){
                if(str[i-1]=='R' or str[i+1]=='R'){
                    continue;
                }
                else{
                    cout<<"NO"<<endl;
                    return;
                }
            }
            else if(str[i]=='R'){
                if(str[i-1]=='B' or str[i+1]=='B'){
                    continue;
                }
                else{
                    cout<<"NO"<<endl;
                    return;
                }
            }
            else{
                continue;
            }
        }
    }
    cout<<"YES"<<endl;
    return;
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
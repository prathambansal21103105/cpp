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
#include<climits>

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
double eps = 1e-12;
#define endl "\n"
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

template <int MOD=1000000007>
struct Modular {
  int value;
  static const int MOD_value = MOD;

  Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
  Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

  Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
  Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
  Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

  friend Modular mexp(Modular a, long long e) {
    Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
  friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
  friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};

Modular<>z=1;
Modular<>y=0;

int Mex(vector<int> a) {
    sort(a.begin(), a.end());
    if(a[0] > 0) return 0;
    for (int i = 1; i < (int) a.size(); i++) {
        if (a[i] > a[i - 1] + 1) {
            return a[i - 1] + 1;
        }
    }
    return a.back() + 1;
}
void binary(vector<int>&v, int& target, int& val1, int st, int end){
    if(st<=end){
        int mid=(st+end)/2;
        if(v[mid]<=target){
           val1=max(val1,v[mid]);
           binary(v,target,val1,mid+1,end);
        }
        else{
           binary(v,target,val1,st,mid-1);
        }
    }
    else{
        return;
    }
}
void remove(vector<long>&v, int index1){
    v.erase(v.begin()+index1);
}
int sum(int bit[], int index){
    int sum1=0;
    for(int i=index;i>0;i-=(i&(-i))){
      sum1+=bit[i];
    }
    return sum1;
}
/*To add a val to index i*/
void update(int bit[], int index, int last, int x){
    for(int i=index;i<=last;i+=(i&(-i))){
        bit[i]+=x;
    }
}


void solve(){
    int n,x;
    cin>>n>>x;
    set<int>aset;
    for(int i=0;i<n;i++){
        int y;
        cin>>y;
        aset.insert(y);
    }
    vector<int>v;
    for(auto i:aset){
        v.pb(i);
    }
    int y=1;
    int i=0;
    vector<int>arr;
    vector<int>v1(32);
    for(int j=0;j<32;j++){
        v1[j]=0;
    }
    while((y<<i)<=x){
        if(((y<<i)&x)!=0){
            v1[31-i]=1;
            arr.pb(i);
        }
        i++;
    }
    int bits[v.size()][32];
    for(int i=0;i<v.size();i++){
        for(int j=0;j<32;j++){
            bits[i][j]=0;
        }
    }
    for(int i=0;i<v.size();i++){
        int val=v[i];
        int sh=0;
        int y=1;
        while((y<<sh)<=val){
            if(((y<<sh)&val)!=0){
                bits[i][31-sh]=1;
            }
            sh++;
        }
    }
    n=v.size();
    vector<int>change;
    vector<int>same;
    for(int i=0;i<32;i++){
        int flag=0;
        if(v1[i]==0){
            for(int j=0;j<n;j++){
                if(bits[j][i]==bits[j][0]){
                    continue;
                }
                else{
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                cout<<x<<endl;
                return;
                same.pb(i);
            }
        }
        else{
            for(int j=0;j<n;j++){
                if(bits[j][i]==bits[j][0]){
                    continue;
                }
                else{
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                change.pb(i);
            }
        }
    }
    sort(change.rbegin(),change.rend());
    for(int i=0;i<change.size();i++){
        int val=change[i];
        v1[val]=0;
        for(int j=val+1;j<32;j++){
            v1[j]=1;
        }
    }
    int ans=0;
    int shift=0;
    for(int i=0;i<32;i++){
        if(v1[i]==1){
            ans+=(1<<(31-i));
        }
    }
    cout<<ans<<endl;
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
/*
x = 1010101
p = 0101111
q = 0011111
*/
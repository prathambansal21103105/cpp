/*------------Pratham Bansal-----------------*/
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

long long GCD(long long x, long long y){
   if(y==0){
       return x;
   }
   return GCD(y, x%y);
}
long long LCM(long long x, long long y){
   return x*y/GCD(x,y);
}
// #define int long long
/*------------code-----------------*/
// void solve(){
//     int n,t;
//     cin>>n>>t;
//     vector<int>v1;
//     vector<int>v2;
//     for(int i=0;i<n;i++){
//         int x;
//         cin>>x;
//         x+=i;
//         v1.pb(x);
//     }
//     for(int i=0;i<n;i++){
//         int x;
//         cin>>x;
//         v2.pb(x);
//     }
//     int max1=0;
//     int index=-1;
//     for(int i=0;i<n;i++){
//         if(v1[i]<=t and v2[i]>=max1){
//             max1=v2[i];
//             index=i+1;
//         }
//     }
//     cout<<index<<endl;
// }
// void solve(){
//     int n;
//     cin>>n;
//     vector<int>v;
//     for(int i=0;i<n;i++){
//         int x;
//         cin>>x;
//         v.pb(x);
//     }
//     sort(v.begin(),v.end());
//     int ans1=v[0]*v[1];
//     int ans2=v[n-1]*v[n-2];
//     if(ans1>ans2){
//         cout<<ans1<<endl;
//     }
//     else{
//         cout<<ans2<<endl;
//     }
// }
// void solve(){
//     int n;
//     cin>>n;
//     int ans=1+((n-2)*(n-1))+n-1+(4*(n));
//     cout<<ans<<endl;
// }
// void solve(){
//     int n;
//     cin>>n;
//     vector<int>v;
//     v.pb(n);
//     if(n&1){
//         if(n==1){
//             cout<<1<<endl;
//         }
//         else{
//             cout<<-1<<endl;
//         }
//         return;
//     }
//     int j=n-1;
//     int k=2;
//     for(int i=1;i<n;i++){
//         if(i&1){
//             v.pb(j);
//             j-=2;
//         }
//         else{
//             v.pb(k);
//             k+=2;
//         }
//     }
//     int sum=0;
//     for(int i=0;i<n;i++){
//         sum+=v[i];
//         cout<<v[i]<<" ";
//     }
//     cout<<endl;
// }
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n&1){
        cout<<-1<<endl;
    }
    else{
        unordered_map<char,int>amap;
        unordered_map<char,int>rep;
        int tar=(n/2)+1;
        for(int i=0;i<n;i++){
            amap[s[i]]++;
            if(amap[s[i]]==tar){
                cout<<-1<<endl;
                return;
            }
        }
        int i=0;
        int j=n-1;
        int count=0;
        while(i<j){
            if(s[i]==s[j]){
                rep[s[i]]++;
            }
            i++;
            j--;
        }
        vector<int>fre;
        for(auto i:rep){
            fre.pb(i.second);
        }
        if(fre.size()==0){
            cout<<count<<endl;
        }
        else{
            sort(fre.rbegin(),fre.rend());
            int extra=fre[0];
            // for(int i=0;i<fre.size();i++){
            //     cout<<fre[i]<<" ";
            // }
            // cout<<endl;
            int flag=0;
            for(int i=1;i<fre.size();i++){
                flag=1;
                if(fre[i]==extra){
                    count+=extra;
                    extra=0;
                }
                else if(fre[i]>extra){
                    count+=fre[i]-extra;
                    extra=fre[i]-extra;
                }
                else{
                    count+=extra-fre[i];
                    extra=extra-fre[i];
                }
            }
            if(flag==0){
                count+=extra;
            }
            cout<<count<<endl;
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
/*
1 -> 3
2 -> 2
3 -> 2
4 -> 1
5 -> 4

*/

/*
1 2 3 4 5 6 7 8
8 7 2 5 4 3 6 1
0 7 1 6 2 5 3 4
*/
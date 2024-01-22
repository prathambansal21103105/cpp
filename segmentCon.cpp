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
int binexp(int a, int b, int M){
  if(b==0){
     return 1;
  }
  long long x=binexp(a,b/2,M)%M;
  if(b&1){
      return ((((a%M)*(x%M))%M)*(x%M))%M;
  }
  else{
      return ((x%M)*(x%M))%M;
  }
}
/*     bin=pow(b,m-2)     */
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
bool isPrime(int n){
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
void primefactors(vector<int>& v, int x){
    while(x%2==0){
        v.pb(2);
        x/=2;
    }
    for(int i=3;i<=sqrt(x);i+=2){
        while(x%i==0){
            v.pb(i);
            x/=i;
        }
    }
    if(x>2){
        v.pb(x);
    }
}
string getbin(int val){
    string str;
    for(int i=0;i<32;i++){
        if((val & (1<<i)) !=0){
            str='1' + str;
        }
        else{
            str='0' + str;
        }
    }
    return str;
}
/*------------code-----------------*/
int countfactor(int x){
    int ans=0;
    for(int i=1;i<=sqrt(x);i++){
        if(x%i==0){
            if(i*i!=x){
                ans+=2;
            }
            else{
                ans+=1;
            }
        }
    }
    return ans;
}
void build(int seg[], int low, int high, int i){
    if(low==high){
        seg[i]=v[low];
        return;
    }
    int mid=low+(high-low)/2;
    build(seg,low,mid,2*i+1);
    build(seg,mid+1,high,2*i+2);
    seg[i]=seg[2*i+1]+seg[2*i+2];
}
void build1(int max1[], int low, int high , int i){
    if(low==high){
        max1[i]=v[low];
        return;
    }
    int mid=low+(high-low)/2;
    build(max1,low,mid,2*i+1);
    build(max1,mid+1,high,2*i+2);
    max1[i]=max(max1[2*i+1],max1[2*i+2]);
}
void update(int lazy[], int max1[], int l, int r, int low, int high, int i){
    if(l>=low and r<=high){
        if(max1[i]>2){
            lazy[i]++;
        }
        return;
    }
    if(r<low or l>high){
        return;
    }
    int mid=low+(high-low)/2;
    update(lazy,l,r,low,mid,2*i+1);
    update(lazy,l,r,mid+1,high,2*i+2);
}
int query(int seg[], int lazy[], int max1[], int x, int low, int high, int i){
    if(x<low or x>high){
        return 0;
    }
    if(max1[i]<=2){
        return seg[i];
    }
    if(low==high){
        int ans=seg[low];
        for(int i=0;i<lazy[i];i++){
            ans=countfactor(ans);
        }
        lazy[i]=0;
        return ans;
    }
    int mid=low+(high-low)/2;
    if(lazy[i]>0){
        lazy[2*i+1]+=lazy[i];
        lazy[2*i+2]+=lazy[i];
        lazy[i]=0;
    }
    int ans1=query(seg,lazy,max1,x,low,mid,2*i+1);
    int ans2=query(seg,lazy,max1,x,mid+1,high,2*i+2);
    max1[i]=max(max1[2*i+1],max1[2*i+2]);
    seg[i]=seg[2*i+1]+seg[2*i+2];
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int seg[4*n];
    int max1[4*n];
    int lazy[4*n];
    build(seg,0,n-1,0);
    build1(max1,0,n-1,0);
    for(int i=0;i<4*n;i++){
        lazy[i]=0;
    }
    for(int i=0;i<m;i++){
        int t,l,r;
        cin>>t>>l>>r;
        if(t==1){
            update(lazy,l,r,0,n-1,0);
        }
        else{
            int ans=query(seg,lazy,l,r,0,n-1,0);
            cout<<ans<<endl;
        }
    }
}
int main()
{
    fast_cin();
    // ll t;
    // cin >> t;
    // while(t--){
        solve();
    // }
    return 0;
}

/*
factor[1]=1; 0
factor[2]=2; 0
factor[3]=2; 1
factor[4]=3; 2
factor[5]=2; 1

*/
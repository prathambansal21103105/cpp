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
#define int long long
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
void build(int seg[], int maxtree[], vector<int>& v, int i, int low, int high){
    if(low==high){
        // cout<<low<<" "<<high<<" "<<v[low]<<endl;
        seg[i]=v[low];
        maxtree[i]=v[low];
        return;
    }
    int mid=low+(high-low)/2;
    build(seg,maxtree,v,2*i+1,low,mid);
    build(seg,maxtree,v,2*i+2,mid+1,high);
    seg[i]=seg[2*i+1]+seg[2*i+2];
    maxtree[i]=maxtree[2*i+1]+maxtree[2*i+2];
}
void update(int seg[], int maxtree[], int i, int low, int high, int l, int r){
    if(l>high or r<low){
        return;
    }
    if(maxtree[i]<=2){
        return;
    }
    else{
        if(low==high){
            seg[i]=countfactor(seg[i]);
            maxtree[i]=seg[i];
            return;
        }
        int mid=low+(high-low)/2;
        update(seg,maxtree,2*i+1,low,mid,l,r);
        update(seg,maxtree,2*i+2,mid+1,high,l,r);
        seg[i]=seg[2*i+1]+seg[2*i+2];
        maxtree[i]=max(maxtree[2*i+1],maxtree[2*i+2]);
    }
}
int query(int seg[], int i, int low, int high, int l, int r){
    if(low>=l and high<=r){
        return seg[i];
    }
    else if(r<low or l>high){
        return 0;
    }
    int mid=low+(high-low)/2;
    int ans1=query(seg,2*i+1,low,mid,l,r);
    int ans2=query(seg,2*i+2,mid+1,high,l,r);
    return ans1+ans2;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int seg[4*n];
    int maxtree[4*n];
    build(seg,maxtree,v,0,0,n-1);
    for(int i=0;i<m;i++){
        int t,l,r;
        cin>>t>>l>>r;
        l--;
        r--;
        if(t==1){
            //update
            update(seg,maxtree,0,0,n-1,l,r);
        }
        else{
            //sum
            int ans=query(seg,0,0,n-1,l,r);
            cout<<ans<<endl;
        }
    }
}
signed main()
{
    fast_cin();
    // ll t;
    // cin >> t;
    // while(t--){
        solve();
    // }
    return 0;
}

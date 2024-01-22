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
int func1(vector<int>& v, int n, int k){
    int sum1=0;
    for(int i=0;i<n;i++){
        sum1+=v[i];
    }
    int x=k/sum1;
    int res=0;
    res+=(x*n);
    int rem=k%sum1;
    if(rem>0){
        unordered_map<int,int>amap;
        sum1=0;
        int min1=INT_MAX;
        for(int i=0;i<2*n;i++){
            sum1+=v[i%n];
            if(sum1==rem){
                min1=min(min1,i+1);
            }
            if(amap.count(sum1-rem)!=0){
                min1=min(min1,i-amap[sum1-rem]);
            }
            amap[sum1]=i;
        }
        return (min1!=INT_MAX)? res+min1:-1;
    }
    else{
        return res;
    }
}
void build(long long seg[], long long dp[], int low, int high, int i, int mod){
    if(low==high){
        seg[i]=dp[low];
        return;
    }
    int mid=low+(high-low)/2;
    build(seg,dp,low,mid,2*i+1,mod);
    build(seg,dp,mid+1,high,2*i+2,mod);
    seg[i]=(seg[2*i+1]+seg[2*i+2])%mod;
}
int query(long long seg[], int low, int high, int l, int r, int i, int mod){
    if(low>=l and high<=r){
        return seg[i];
    }
    else if(l>high or r<low){
        return 0;
    }
    int mid=low+(high-low)/2;
    int left=query(seg,low,mid,l,r,2*i+1,mod);
    int right=query(seg,mid+1,high,l,r,2*i+2,mod);
    return left+right;
}
void solve(){
    int k;
    cin>>k;
    vector<vector<int> >v(k,vector<int>(2,0));
    int max1=0;
    for(int i=0;i<k;i++){
        cin>>v[i][0]>>v[i][1];
        max1=max(max1,v[i][1]);
    }
    int mod1=1000000007;
    long long seg[(max1+1)*4];
    long long dp[max1+1];
    for(int i=0;i<=max1;i++){
        dp[i]=0;
    }
    dp[0]=1;
    for(int i=0;i<=max1;i++){
        dp[i+1]=(dp[i+1]+dp[i])%mod1;
        if(i+k<=max1){
            dp[i+k]=(dp[i+k]+dp[i])%mod1;
        }
    }
    build(seg,dp,0,max1,0,mod1);
    for(int i=0;i<k;i++){
        cout<<query(seg,0,max1,v[i][0],v[i][1],0,mod1)<<endl;
    }
}
vector<int> func1(vector<int>& v, int n){
    int prev=0;
    vector<int>res;
    for(int i=0;i<n;i++){
        string strp=to_string(prev);
        string str=to_string(v[i]);
        int x=strp.length();
        int m = str.length();
        int val=INT_MAX;
        for(int j=0;j<m;j++){
            if(m-j+1>=x){
                string s=str.substr(j,x);
                if(stoi(s)>=prev){
                    val=min(val,stoi(s));
                }
            }
        }
        for(int j=0;j<m;j++){
            if(m-j+1>=x+1){
                string s=str.substr(j,x+1);
                if(stoi(s)>=prev){
                    val=min(val,stoi(s));
                }
            }
        }
        if(val==INT_MAX){
            res.pb(-1);
            return res;
        }
        v[i]=val;
        prev=v[i];
    }
    return v;
}
void solve1(){
    int n;
    cin>>n;
    int q;
    cin>>q;
    vector<int>v(n);
    vector<int>queries(q);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<q;i++){
        cin>>queries[i];
    }
    unordered_map<int,int>prefix;
    unordered_map<int,int>suffix;
    int sum1=INT_MIN;
    for(int i=0;i<n;i++){
        sum1=max(sum1,v[i]);
        prefix[sum1]++;
    }
    sum1=INT_MAX;
    for(int i=n-1;i>=0;i--){
        sum1=min(sum1,v[i]);
        suffix[sum1]++;
    }
    vector<int>res;
    for(int i=0;i<queries.size();i++){
        int val=queries[i];
        int count=0;
        for(int j=1;j<=sqrt(val);j++){
            if(val%j==0){
                if(prefix.count(j)!=0 and suffix.count(val/j)!=0){
                    count+=(prefix[j]*suffix[val/j]);
                }
                if(prefix.count(val/j)!=0 and suffix.count(j)!=0){
                    count+=(prefix[val/j]*suffix[j]);
                }
            }
        }
        res.pb(count);
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    fast_cin();
    solve1();
    return 0;
}

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
int func(vector<int>& vals, int i, int n, int k, int val, int** dp){
    if(i==n){
        return 0;
    }
    if(dp[i][val]!=-1){
        return dp[i][val];
    }
    int ans1=func(vals,i+1,n,k,val,dp);
    int newval=vals[i] | val;
    int ans2=0;
    if(__builtin_popcount(newval)<=k){
        ans2=1+func(vals,i+1,n,k,newval,dp);
    }
    return dp[i][val]=max(ans1,ans2);
}
int countBits1(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int solution(vector<string>& S, int K) {
    int n = S.size();
    vector<int> v(n, 0);

    for (int i = 0; i < n; i++) {
        for (char c : S[i]) {
            v[i] |= (1 << (c - 'a'));
        }
    }

    int max1 = 0;
    for (int i = 0; i < (1 << 10); i++) {
        if (countBits1(i) == K) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if ((v[j] & i) == v[j]) {
                    count++;
                }
            }
            max1 = max(max1, count);
        }
    }

    return max1;
}
// int solution(vector<string> &s, int k) {
//     vector<string>v;
//     for(int i=0;i<s.size();i++){
//         string str=s[i];
//         set<char>aset;
//         for(int j=0;j<str.length();j++){
//             aset.insert(str[j]);
//         }
//         if(aset.size()>k){
//             continue;
//         }
//         string str1="";
//         for(auto i:aset){
//             str1.push_back(i);
//         }
//         v.push_back(str1);
//     }
//     int n=v.size();
//     vector<int> vals(n,0);
//     for(int i=0;i<v.size();i++){
//         for(int j=0;j<v[i].length();j++){
//             int x=v[i][j]-'a';
//             vals[i]+=pow(2,x);
//         }
//     }
//     int **dp =new int*[n+1];
//     for(int i=0;i<n+1;i++){
//         dp[i]=new int[1<<10];
//         int val=(1<<10);
//         for(int j=0;j<val;j++){
//             dp[i][j]=-1;
//         }
//     }
//     int val=0;
//     int ans=func(vals,0,n,k,val,dp);
//     return ans;
// }
// int solution(vector<int> &A) {
//     int nums=A.size();
//     int pointer1=0;
//     int count=0;
//     vector<int>v;
//     while(pointer1<nums){
//         if(A[pointer1]==0 or A[pointer1]==1){
//             if(A[pointer1]==1){
//                 count++;
//             }
//             pointer1++;
//             continue;
//         }
//         if(pointer1==nums-1){
//             v.push_back(A[pointer1]/2);
//             int vals=solution(v);
//             if(A[pointer1]%2==1){
//                 count++;
//             }
//             count+=vals;
//             pointer1++;
//             continue;
//         }
//         A[pointer1+1]=A[pointer1+1]+(A[pointer1]/2);
//         A[pointer1]=A[pointer1]%2;
//     }
//     return count;
// }
// void solve(){
//     int n;
//     cin>>n;
//     vector<int>v(n);
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }
//     int ans=solution(v);
//     cout<<ans<<endl;
// }

void solve(){
    int n;
    cin>>n;
    vector<string>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int k;
    cin>>k;
    int ans=solution(v,k);
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

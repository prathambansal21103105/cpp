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
#include <climits>

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
vector<int> topoSort(int v, vector<int> adj[]) {
    vector<int>indegree(v,0);
    for(int i=0;i<v;i++){
        for(int j=0;j<adj[i].size();j++){
            indegree[adj[i][j]]++;
        }
    }
    vector<int>visited(v,0);
    vector<int>res;
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int f=q.front();
        q.pop();
        visited[f]=1;
        res.push_back(f);
        for(int i=0;i<adj[f].size();i++){
            indegree[adj[f][i]]--;
            if(indegree[adj[f][i]]==0){
                q.push(adj[f][i]);
            }
        }
    }
    return res;
}
vector<int> getPrimes(int n){
    vector<int>counts(n+1,0);
    vector<int>res;
    for(int i=2;i<=n;i++){
        if(counts[i]==0){
            res.pb(i);
            for(int j=i*i;j<=n;j+=i){
                counts[j]++;
            }
        }
        else{
            continue;
        }
    }
    return res;
}
/*------------code-----------------*/
struct node {
    int leftfour;
    int rightfour;
    int four;
    node(){
        leftfour=0;
        rightfour=0;
        four=0;
    }
    node(int a, int b, int c){
        leftfour=a;
        rightfour=b;
        four=c;
    }
};
node tree[4000000];
int lazy[4000000];
void build(vector<int>& v, int l, int r, int i){
    if(l==r){
        if(v[l]==4){
            tree[i]=node(1,1,1);
        }
        else{
            tree[i]=node(-1,-1,0);
        }
        return;
    }
    int mid=l+(r-l)/2;
    build(v,l,mid,(2*i)+1);
    build(v,mid+1,r,(2*i)+2);
    node left=tree[(2*i)+1];
    node right=tree[(2*i)+2];
    tree[i].four=left.four+right.four;
    if(mid-l+1==left.four){
        tree[i].leftfour=left.four+max(0,right.leftfour);
    }
    else{
        tree[i].leftfour=left.leftfour;
    }
    if(r-mid==right.four){
        tree[i].rightfour=right.four+max(0,left.rightfour);
    }
    else{
        tree[i].rightfour=right.rightfour;
    }
}
void update(int l, int r, int i, int l1, int r1){
    if(lazy[i]&1){
        if(l!=r){
            lazy[(2*i)+1]+=1;
            lazy[(2*i)+2]+=1;
        }
        lazy[i]=0;
        tree[i].leftfour=(-tree[i].leftfour);
        tree[i].rightfour=(-tree[i].rightfour);
        tree[i].four=r-l+1-tree[i].four;
    }
    else{
        lazy[i]=0;
    }
    if(l>=l1 && r<=r1){
        if(l!=r){
            lazy[(2*i)+1]+=1;
            lazy[(2*i)+2]+=1;
        }
        tree[i].leftfour=(-tree[i].leftfour);
        tree[i].rightfour=(-tree[i].rightfour);
        tree[i].four=r-l+1-tree[i].four;
        return;
    }
    else if(l>r1 || r<l1){
        return;
    }
    int mid=l+(r-l)/2;
    update(l,mid,(2*i)+1,l1,r1);
    update(mid+1,r,(2*i)+2,l1,r1);
    node left=tree[(2*i)+1];
    node right=tree[(2*i)+2];
    tree[i].four=left.four+right.four;
    if(mid-l+1==left.four){
        tree[i].leftfour=left.four+max(0,right.leftfour);
    }
    else{
        tree[i].leftfour=left.leftfour;
    }
    if(r-mid==right.four){
        tree[i].rightfour=right.four+max(0,left.rightfour);
    }
    else{
        tree[i].rightfour=right.rightfour;
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<int>v(n,0);
    for(int i=0;i<n;i++){
        v[i]=(s[i]-'0');
    }
    for(int i=0;i<4*n;i++){
        lazy[i]=0;
    }
    build(v,0,n-1,0);
    // cout<<tree[0].four<<endl;
    string op;
    int l,r;
    for(int i=0;i<m;i++){
        cin>>op;
        if(op=="count"){
            int ans1=max(0,tree[0].leftfour)+(n-tree[0].four);
            int ans2=tree[0].four+max(0,-tree[0].rightfour);
            cout<<max(ans1,ans2)<<endl;
        }
        else{
            cin>>l>>r;
            l--;
            r--;
            update(0,n-1,0,l,r);
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
477747
4447474777
*/
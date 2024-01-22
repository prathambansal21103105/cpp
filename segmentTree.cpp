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
struct Node{
    int pre;
    int suff;
    int maxVal;
};
void update(vector<int>& v, int* tree, int node, int val, int low, int high, int i){
    if(low==high){
        tree[i]=val;
        return;
    }
    int mid=low+(high-low)/2;
    if(node>=low && node<=mid){
        update(v,tree,node,val,low,mid,2*i);
    }
    else{
        update(v,tree,node,val,mid+1,high,(2*i)+1);
    }
    tree[i]=tree[2*i]+tree[(2*i)+1];
}
void build(vector<int>& v, int* tree, int low, int high, int i){
    if(low==high){
        tree[i]=v[low];
        return;
    }
    int mid=low+(high-low)/2;
    build(v,tree,low,mid,2*i);
    build(v,tree,mid+1,high,2*i+1);
    tree[i]=tree[2*i]+tree[(2*i)+1];
}
int query(vector<int>&v, int* tree, int low, int high, int i, int l, int r){
    if(low>=l && high<=r){
        return tree[i];
    }
    else if(l>high || r<low){
        return 0;
    }
    int mid=low+(high-low)/2;
    int val1=query(v,tree,low,mid,2*i,l,r);
    int val2=query(v,tree,mid+1,high,(2*i)+1,l,r);
    return val1+val2;
}
void buildTree(vector<int>& v, pair<int,int>* tree, int low, int high, int i){
    if(low==high){
        tree[i]=make_pair(v[low],0);
        return;
    }
    int mid=low+(high-low)/2;
    buildTree(v,tree,low,mid,2*i);
    buildTree(v,tree,mid+1,high,(2*i)+1);
    int max1=max(tree[2*i].first,tree[(2*i)+1].first);
    int max2=(tree[2*i].first>=tree[(2*i)+1].first)? max(tree[2*i].second,tree[(2*i)+1].first):max(tree[2*i].first,tree[(2*i)+1].second);
    tree[i]=make_pair(max1,max2);
}
pair<int,int> queryTree(vector<int>&v, pair<int,int>* tree, int low, int high, int i, int l, int r){
    if(low>=l && high<=r){
        return tree[i];
    }
    else if(low>r || high<l){
        return make_pair(0,0);
    }
    int mid=low+(high-low)/2;
    pair<int,int>p1=queryTree(v,tree,low,mid,2*i,l,r);
    pair<int,int>p2=queryTree(v,tree,mid+1,high,(2*i)+1,l,r);
    int max1=max(p1.first,p2.first);
    int max2=(p1.first>=p2.first)? max(p1.second,p2.first):max(p1.first,p2.second);
    return make_pair(max1,max2);
}
void buildSub(vector<int>&v, Node*tree, int low, int high, int i, vector<int>&total){
    if(low==high){
        tree[i].pre=v[low];
        tree[i].suff=v[low];
        tree[i].maxVal=v[low];
        return;
    }
    int mid=low+(high-low)/2;
    buildSub(v,tree,low,mid,2*i,total);
    buildSub(v,tree,mid+1,high,(2*i)+1,total);
    Node left=tree[2*i];
    Node right=tree[(2*i)+1];
    int prefix=max(left.pre,total[mid+1]-total[low]+max(0,right.pre));
    int suffix=max(right.suff,total[high+1]-total[mid+1]+max(0,left.suff));
    int max1=max(left.maxVal,right.maxVal);
    int max2=max(prefix,suffix);
    int max3=max(max1,max2);
    int maxSub=max(max3,left.suff+right.pre);
    int maxSub1=max(maxSub,total[mid+1]-total[low]+total[high+1]-total[mid+1]);
    tree[i].pre=prefix;
    tree[i].suff=suffix;
    tree[i].maxVal=maxSub1;
}
Node query(vector<int>&v, Node* tree, int low, int high, int i, int l, int r, vector<int>&total){
    if(low>=l && high<=r){
        return tree[i];
    }
    else if(l>high || r<low){
        Node x;
        x.suff=INT_MIN;
        x.pre=INT_MIN;
        x.maxVal=INT_MIN;
        return x;
    }
    int mid=low+(high-low)/2;
    Node left=query(v,tree,low,mid,2*i,l,r,total);
    Node right=query(v,tree,mid+1,high,(2*i)+1,l,r,total);
    int prefix=max(left.pre,total[mid+1]-total[low]+max(0,right.pre));
    int suffix=max(right.suff,total[high+1]-total[mid+1]+max(0,left.suff));
    int max1=max(left.maxVal,right.maxVal);
    int max2=max(prefix,suffix);
    int max3=max(max1,max2);
    int maxSub=max(max3,left.suff+right.pre);
    int maxSub1=max(maxSub,total[mid+1]-total[low]+total[high+1]-total[mid+1]);
    Node final;
    final.pre=prefix;
    final.suff=suffix;
    final.maxVal=maxSub1;
    return final;
}
void solve(){
    int n;
    cin>>n;
    vector<int>v(n),total(n+1);
    total[0]=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        total[i+1]=total[i]+v[i];
    }
    // int *tree=new int[4*n];
    // build(v,tree,0,n-1,1);
    // int node;
    // cin>>node;
    // int val;
    // cin>>val;
    // update(v,tree,node,val,0,n-1,1);
    // for(int i=1;i<2*n;i++){
    //     cout<<tree[i]<<" ";
    // }
    // cout<<endl;
    // pair<int,int>* tree=new pair<int,int>[4*n];
    // buildTree(v,tree,0,n-1,1);
    // int l,r;
    // cin>>l>>r;
    // // cout<<query(v,tree,0,n-1,1,l,r)<<endl;
    // auto p=queryTree(v,tree,0,n-1,1,l,r);
    // cout<<p.first<<" "<<p.second<<endl;
    Node* tree=new Node[4*n];
    buildSub(v,tree,0,n-1,1,total);
    // int l,r;
    // cin>>l>>r;
    // l--;
    // r--;
    // cout<<query(v,tree,0,n-1,1,0,n-1,total).maxVal<<endl;
    cout<<tree[1]<<endl;
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

*/
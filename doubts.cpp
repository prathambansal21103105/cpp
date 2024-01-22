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
/*------------code-----------------*/
int helper(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>& v){
    int count=0;
    if(root==NULL){
        return 0;
    }
    if(root==p){
        count+=1;
    }
    if(root==q){
        count+=1;
    }
    count+=helper(root->left,p,q,v);
    count+=helper(root->right,p,q,v);
    if(count==2){
        v.push_back(root);
    }
    return count;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> v;
    helper(root,p,q,v);
    return v[0];
}
void helper(BinaryTreeNode<int>* root, int k, vector<vector<int> >& res, vector<int> v){
    if(root==NULL){
        return;
    }
    if(root->left==NULL and root->right==NULL){
        if(root->data==k){
            v.push_back(root->data);
            res.push_back(v);
        }
    }
    else{
        if(root->data<=k){
            v.push_back(root->data);
            helper(root->left,k-root->data,res,v);
            helper(root->right,k-root->data,res,v);
        }
    }
}
void rootToLeafPathsSumToK(BinaryTreeNode<int>* root, int k){
    vector<vector<int> > res;
    vector<int>v;
    helper(root,k,res,v);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
void helper(BinaryTreeNode<int>* root, map<int,int>& amap){
    if(root==NULL){
        return;
    }
    else{
        amap[root->data]++;
        helper(root->left,amap);
        helper(root->right,amap);
    }
}
void printNodesSumToS(BinaryTreeNode<int>* root,int s){
    map<int,int>amap
    helper(root,amap);
    vector<int>v;
    for(auto i:amap){
        v.push_back(i.first);
    }
    for(int i=0;i<v.size();i++){
        int curr=v[i];
        if(s-curr>curr and amap.count(s-curr)!=0){
            cout<<curr<<" "<<s-curr<<endl;
        }
    }
}
// int buyTicket(int *arr, int n, int k){
//     priority_queue<int> pq;
//     int val=arr[k];
//     for(int i=0;i<n;i++){
//         pq.push(arr[i]);
//     }
//     int count=0;
//     // int min1=INT_MAX;
//     // for(int i=0;i<n;i++){
//     //     if(arr[i]>val){
//     //         min1=min(min1,arr[i]);
//     //     }
//     // }
//     while(!pq.empty()){
//         if(pq.top()==val){
//             count+=1;
//             break;
//         }
//         pq.pop();
//         count+=1;
//     }
//     return count;
// }
int highestFrequency(int arr[], int n){
    unordered_map<int,int>amap;
    for(int i=0;i<n;i++){
        amap[arr[i]]++;
    }
    int max1=INT_MIN;
    int val=-1;
    for(int i=0;i<n;i++){
        int f=amap[arr[i]];
        if(f>max1){
            max1=f;
            val=arr[i];
        }
    }
    return val;
}
int lengthofLongestSubsetWithZeroSum(int* arr, int n){
    vector<int>prefix;
    int sum=0;
    unordered_map<int,int>amap;
    int max1=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0){
            max1=max(max1,i+1);
        }
        if(amap.count(sum)==0){
            amap[sum]=i;
        }
        else{
            max1=max(max1,i-amap[sum]);
        }
        prefix.push_back(sum);
    }
    return max1;
}
void solve(){
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

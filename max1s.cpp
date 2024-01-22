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
/*------------code-----------------*/
long long OneBlock(int n, vector<int>v){
    int flag=0;
    vector<int>v1;
    for(int i=0;i<n;i++){
        if(flag==1){
            v1.push_back(v[i]);
        }
        else{
            if(v[i]==1){
                v1.push_back(v[i]);
                flag=1;
            }
        }
    }
    if(v1.size()==0){
        return 0;
    }
    while(v1[v1.size()-1]==0){
        v1.pop_back();
    }
    if(flag==0){
        return 0;
    }
    long long res=1;
    n=v1.size();
    long long count=1;
    for(int i=0;i<n;i++){
        if(v1[i]==1){
            res*=count;
            count=1;
        }
        else{
            count+=1;
        }
    }
    return res;
}
int sum(int bit[], int index){
    int sum1=0;
    for(int i=index;i>0;i-=(i&(-i))){
      sum1+=bit[i];
    }
    return sum1;
}
void update(int bit[], int index, int last, int x){
    for(int i=index;i<=last;i+=(i&(-i))){
        bit[i]+=x;
    }
}
void bin(int bit[],int st, int end, int target, int& x, int id){
    while(st<=end){
        int mid=st+(end-st)/2;
        if(target-sum(bit,mid+1)==id-mid){
            x=min(x,mid);
            end=mid-1;
        }
        else{
            st=mid+1;
        }
    }
}
void bin1(int bit[],int st, int end, int target, int& x, int id){
    while(st<=end){
        int mid=st+(end-st)/2;
        if(sum(bit,mid+1)-target==mid-id){
            x=max(x,mid);
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
}
int solve(int n, int m, vector<int> v){
    int bit[n+1];
    for(int i=0;i<n;i++){
        v[i]--;
        bit[i]=0;
    }
    bit[n]=0;
    for(int i=0;i<n;i++){
        update(bit,v[i]+1,n,1);
        int sum1=sum(bit,v[i]+1);
        int x=v[i];
        bin(bit,0,v[i],sum1,x,v[i]);
        int y=v[i];
        bin1(bit,v[i],n,sum1,y,v[i]);
        if(sum(bit,x+1)-sum(bit,x)==0){
            x++;
        }
        if(sum(bit,y+1)-sum(bit,y)==0){
            y--;
        }
        if(y-x+1>=m){
            return i+1;
        }
    }
    return n;
}
void solve1(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }   
    // cout<<OneBlock(n,v)<<endl;
    cout<<solve(n,m,v)<<endl;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    while(t--){
        solve1();
    }
    return 0;
}
/*
1 0 1 0 1
1 010 1
1 01 01
10 10 1
10 1 01
*/

// /*------------Pratham Bansal-----------------*/
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #include <complex>
// #include <queue>
// #include <set>
// #include <unordered_set>
// #include <list>
// #include <chrono>
// #include <random>
// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <string>
// #include <vector>
// #include <map>
// #include <unordered_map>
// #include <stack>
// #include <iomanip>
// #include <fstream>

// using namespace std;

// typedef long long ll;
// typedef long double ld;
// typedef pair<int,int> p32;
// typedef pair<ll,ll> p64;
// typedef pair<double,double> pdd;
// typedef vector<ll> v64;
// typedef vector<int> v32;
// typedef vector<vector<int> > vv32;
// typedef vector<vector<ll> > vv64;
// typedef vector<vector<p64> > vvp64;
// typedef vector<p64> vp64;
// typedef vector<p32> vp32;
// double eps = 1e-12;
// #define endl "\n"
// #define dbg(x) cout<<#x<<" = "<<x<<endl
// #define mp make_pair
// #define pb push_back
// #define fi first
// #define se second
// #define INF 2e18
// #define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define all(x) (x).begin(), (x).end()
// #define sz(x) ((ll)(x).size())

// template <int MOD=1000000007>
// struct Modular {
//   int value;
//   static const int MOD_value = MOD;

//   Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
//   Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

//   Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
//   Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
//   Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

//   friend Modular mexp(Modular a, long long e) {
//     Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
//     return res;
//   }
//   friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

//   Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
//   friend Modular operator+(Modular a, Modular const b) { return a += b; }
//   friend Modular operator-(Modular a, Modular const b) { return a -= b; }
//   friend Modular operator-(Modular const a) { return 0 - a; }
//   friend Modular operator*(Modular a, Modular const b) { return a *= b; }
//   friend Modular operator/(Modular a, Modular const b) { return a /= b; }
//   friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
//   friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
//   friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
// };

// Modular<>z=1;
// Modular<>y=0;

// int Mex(vector<int> a) {
//     sort(a.begin(), a.end());
//     if(a[0] > 0) return 0;
//     for (int i = 1; i < (int) a.size(); i++) {
//         if (a[i] > a[i - 1] + 1) {
//             return a[i - 1] + 1;
//         }
//     }
//     return a.back() + 1;
// }
// void binary(vector<int>&v, int& target, int& val1, int st, int end){
//     if(st<=end){
//         int mid=(st+end)/2;
//         if(v[mid]<=target){
//            val1=max(val1,v[mid]);
//            binary(v,target,val1,mid+1,end);
//         }
//         else{
//            binary(v,target,val1,st,mid-1);
//         }
//     }
//     else{
//         return;
//     }
// }
// void remove(vector<long>&v, int index1){
//     v.erase(v.begin()+index1);
// }
// int binexp(int a, int b, int M){
//   if(b==0){
//      return 1;
//   }
//   long long x=binexp(a,b/2,M)%M;
//   if(b&1){
//       return ((((a%M)*(x%M))%M)*(x%M))%M;
//   }
//   else{
//       return ((x%M)*(x%M))%M;
//   }
// }
// /*     bin=pow(b,m-2)     */
// int sum(int bit[], int index){
//     int sum1=0;
//     for(int i=index;i>0;i-=(i&(-i))){
//       sum1+=bit[i];
//     }
//     return sum1;
// }
// /*To add a val to index i*/
// void update(int bit[], int index, int last, int x){
//     for(int i=index;i<=last;i+=(i&(-i))){
//         bit[i]+=x;
//     }
// }

// long long GCD(long long x, long long y){
//    if(y==0){
//        return x;
//    }
//    return GCD(y, x%y);
// }
// long long LCM(long long x, long long y){
//    return x*y/GCD(x,y);
// }
// bool isPrime(int n){
//     if (n <= 1)
//         return false;
//     for (int i = 2; i * i <= n; i++) {
//         if (n % i == 0)
//             return false;
//     }
//     return true;
// }
// string getbin(int val){
//     string str;
//     for(int i=0;i<32;i++){
//         if((val & (1<<i)) !=0){
//             str='1' + str;
//         }
//         else{
//             str='0' + str;
//         }
//     }
//     return str;
// }
// vector<int> topoSort(int v, vector<int> adj[]) {
//     vector<int>indegree(v,0);
//     for(int i=0;i<v;i++){
//         for(int j=0;j<adj[i].size();j++){
//             indegree[adj[i][j]]++;
//         }
//     }
//     vector<int>visited(v,0);
//     vector<int>res;
//     queue<int>q;
//     for(int i=0;i<v;i++){
//         if(indegree[i]==0){
//             q.push(i);
//         }
//     }
//     while(!q.empty()){
//         int f=q.front();
//         q.pop();
//         visited[f]=1;
//         res.push_back(f);
//         for(int i=0;i<adj[f].size();i++){
//             indegree[adj[f][i]]--;
//             if(indegree[adj[f][i]]==0){
//                 q.push(adj[f][i]);
//             }
//         }
//     }
//     return res;
// }
// /*------------code-----------------*/
// #define int long long
// void primefactors(vector<int>& v, int x){
//     while(x%2==0){
//         v.pb(2);
//         x/=2;
//     }
//     for(int i=3;i<=sqrt(x);i+=2){
//         while(x%i==0){
//             v.pb(i);
//             x/=i;
//         }
//     }
//     if(x>2){
//         v.pb(x);
//     }
// }
// void solve(){
//     int a,b;
//     cin>>a>>b;
//     if(b==0){
//         cout<<0<<endl;
//         return;
//     }
//     int res=0;
//     res=b*(b-1)/2;
//     // cout<<res<<endl;
//     int res1=(res*(a-1))+b;
//     vector<int>v;
//     primefactors(v,a);
//     if(isPrime(a)){
//         v.pop_back();
//     }
//     map<int,int>freqSmall,freqBig;
//     if(v.size()==0){
//         cout<<res1<<endl;
//         return;
//     }
//     for(auto i:v){
//         // cout<<"a"<<" "<<a<<endl;
//         int val=0;
//         int temp=a;
//         while((temp%i)==0){
//             val++;
//             temp/=i;
//         }
//         // cout<<val<<endl;
//         freqSmall[i]=val;
//     }
    
//     for(auto i:freqSmall){
//         cout<<i.first<<" "<<i.second<<endl;
//         int x=i.first;
//         int temp=x;
//         int val=0;
//         while((a-1)/temp>0){
//             val+=(a-1)/temp;
//             temp*=x;
//         }
//         freqBig[x]=val*(b-1);
//     }
//     for(auto i:v){
//         freqBig[i]+=1;
//     }
//     int min1=LLONG_MAX;
//     for(auto i:freqBig){
//         min1=min(min1,(freqBig[i.first]/freqSmall[i.first]));
//     }
//     cout<<res1<<endl;
//     cout<<min1<<endl;
//     cout<<res1+min1<<endl;
// }
// signed main()
// {
//     fast_cin();
//     // ll t;
//     // cin >> t;
//     // while(t--){
//         solve();
//     // }
//     return 0;
// }
// /*
// 4 2
// 1 2 4 8 12 16 
// 0 0 1 1 1  2
// 2 + (3*1);
// 5
// (1*2*3)^(1);
// 2
// 2

// */
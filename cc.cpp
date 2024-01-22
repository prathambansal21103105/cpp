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
/*------------code-----------------*/
void dfs1(vector<vector<int> >&v, int st, vector<int>& odd, int& j ){
    int n=v.size();
    int i=st+1;
    while(j<odd.size() and i<n){
        v[i][st]=odd[j];
        j++;
        v[st][i]=odd[j];
        j++;
        i++;
    }
}
void dfs(vector<vector<int> >&v, int st, vector<int>& odds, int& j ){
    int n=v.size();
    int i=st+1;
    while(j<odds.size() and i<n){
        v[i][st]=odds[j];
        j++;
        v[st][i]=odds[j];
        j++;
        i++;
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int>odds;
    vector<int>evens;
    vector<vector<int> >v(n,vector<int>(n,0));
    for(int i=1;i<=(n*n);i++){
        if(i&1){
            odds.pb(i);
        }
        else{
            evens.pb(i);
        }
    }
    if(n&1){
        int j=1;
        v[0][0]=odds[0];
        for(int i=1;i<n;i++){
            if(j<odds.size()){
                v[i][0]=odds[j];
                j++;
                v[0][i]=odds[j];
                j++;
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int k=0;k<n;k++){
        //         cout<<v[i][k]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"YES"<<endl;
        // cout<<j<<" "<<odds.size()<<endl;
        if(j<odds.size()){
            int st=1;
            int x=1;
            while(j<odds.size()){
                dfs(v,st,odds,j);
                st++;
            }
        }
        j=0;
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                if(v[i][k]==0){
                    v[i][k]=evens[j];
                    j++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int k=0;k<n;k++){
                cout<<v[i][k]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        if(n==2){
            cout<<-1<<endl;
        }
        else{
            v[0][0]=1;
            v[0][1]=2;
            v[0][2]=4;
            v[0][3]=15;
            v[1][0]=6;
            v[1][1]=8;
            v[1][2]=13;
            v[1][3]=10;
            v[2][0]=7;
            v[2][1]=9;
            v[2][2]=11;
            v[2][3]=12;
            v[3][0]=3;
            v[3][1]=14;
            v[3][2]=16;
            v[3][3]=5;
            if(n==4){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        cout<<v[i][j]<<" ";
                    }
                    cout<<endl;
                }
            }
            else{
                vector<int>odd,even;
                for(int i=17;i<=(n*n);i++){
                    if(i&1){
                        odd.pb(i);
                    }
                    else{
                        even.pb(i);
                    }
                }
                int j=0;

                for(int i=4;i<n;i++){
                    if(j<odd.size()){
                        v[i][i]=odd[j];
                        j++;
                        v[i][0]=odd[j];
                        j++;
                        v[0][i]=odd[j];
                        j++;
                    }
                }
                for(int i=0;i<n;i++){
                    for(int k=0;k<n;k++){
                        cout<<v[i][k]<<" ";
                    }
                    cout<<endl;
                }
                cout<<"YES"<<endl;
                int st=4;
                if(j<odd.size()){
                while(j<odd.size()){
                    dfs1(v,st,odd,j);
                    st++;
                }
                }
                j=0;
                for(int i=0;i<n;i++){
                    for(int k=0;k<n;k++){
                        if(v[i][k]==0){
                            v[i][k]=even[j];
                            j++;
                        }
                    }
                }
                for(int i=0;i<n;i++){
                    for(int k=0;k<n;k++){
                        cout<<v[i][k]<<" ";
                    }
                    cout<<endl;
                }
            }
        }
    }
}
// void solve(){
//     int n;
//     cin>>n;
//     vector<int>v(n);
//     int sum=0;
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//         sum+=v[i];
//     }
//     if(sum&1){
//         cout<<"Bob"<<endl;
//     }
//     else{
//         cout<<"Alice"<<endl;
//     }
// }
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

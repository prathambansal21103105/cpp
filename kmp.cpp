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
void computeLPSArray(string pat, int M, vector <int>  &lps){
    int j = 0;
    int i;

    lps[0] = 0;
    i = 1;

    while (i < M){
        if (pat[i] == pat[j]){
            lps[i] = j+1;
            i++;
            j++;
        }

        else{
            if (j != 0){
                j = lps[j - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}
vector <int> search(string& txt, string& pat){
    vector <int> res;
    int N = txt.size();
    int M = pat.size();

    vector < int > lps(M + 1, 0);
    int j  = 0;
    computeLPSArray(pat, M, lps);
    int f = 0;
    int i = 0; 
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            f++;
            res.push_back (i - j + 1);
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    if (f == 0)
        res.push_back (-1);

    return res;
}
bool kmp(string& txt, string& pat){

    int N = txt.size();
    int M = pat.size();

    vector < int > lps(M + 1, 0);
    computeLPSArray(pat, M, lps);
    int i = 0; 
    int j  = 0;
    while (i < N){
        if (pat[j] == txt[i]){
            i++;
            j++;
        }

        if (j == M){
            return true;
        }
        else if (i < N && pat[j] != txt[i]){
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return false;
}
void solve(){
    string text,pattern;
    cin>>text>>pattern;
    // if(kmp_search(text,pattern)){
    //     cout<<"YES"<<endl;
    // }
    // else{
    //     cout<<"NO"<<endl;
    // }
    // vector<int>v=search(text,pattern);
    // for(auto i:v){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    cout<<kmp(text,pattern)<<endl;
}
long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
    int n=bottomLeft.size();
    int max1=0;
    for(int i=0;i<n;i++){
        int l=topRight[i][0]-bottomLeft[i][0];
        int b=topRight[i][1]-bottomLeft[i][1];
        int x=bottomLeft[i][0];
        int y=bottomLeft[i][1];
        for(int j=0;j<n;j++){
            cout<<i<<" "<<j<<endl;
            // if(i==j){
            //     continue;
            // }
            // else{
            //     int l1=topRight[j][0]-bottomLeft[j][0];
            //     int b1=topRight[j][1]-bottomLeft[j][1];
            //     int x1=bottomLeft[j][0];
            //     int y1=bottomLeft[j][1];
            //     if(x1>x){
            //         if(x1<=x+l){
            //             if(y1>y){
            //                 if(y1<=y+b){
            //                     int side=min(y+b-y1,x+l-x1);
            //                     max1=max(max1,side);
            //                 }
            //                 else{
            //                     continue;
            //                 }
            //             }
            //             else{
            //                 if(y<=y1+b1){
            //                     int side=min(y1+b1-y,x+l-x1);
            //                     max1=max(max1,side);
            //                 }
            //                 else{
            //                     continue;
            //                 }
            //             }
            //         }
            //         else{
            //             continue;
            //         }
            //     }
            //     else{
            //         if(x<=x1+l1){
            //             if(y1>y){
            //                 if(y1<=y+b){
            //                     int side=min(y+b-y1,x1+l1-x);
            //                     max1=max(max1,side);
            //                 }
            //                 else{
            //                     continue;
            //                 }
            //             }
            //             else{
            //                 if(y<=y1+b1){
            //                     int side=min(y1+b1-y,x1+l1-x);
            //                     max1=max(max1,side);
            //                 }
            //                 else{
            //                     continue;
            //                 }
            //             }
            //         }
            //         else{
            //             continue;
            //         }
            //     }
            }
        }
    }
    long long ans1=max1;
    ans1*=ans1;
    return ans1;
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

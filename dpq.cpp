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
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define endl "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
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
struct Node{
    public:
    int penalty;
    int deadline;
    int time;
    Node(int p, int d, int t){
        this->penalty=p;
        this->deadline=d;
        this->time=t;
    }
};
bool func(Node* a, Node* b){
    if(a->time < b->time){
        return true;
    }
    else if(a->time > b->time){
        return false;
    }
    else{
        if(a->deadline < b->deadline){
            return true;
        }
        else if(a->deadline > b->deadline){
            return false;
        }
        else{
            if(a->penalty >= b->penalty){
                return true;
            }
            else{
                return false;
            }
        }
    }
    
}
void solve(){
    int n;
    cin>>n;
    vector<Node*>v;
    int total=0;
    int penalty=0;
    for(int i=0;i<n;i++){
        int p,d,t;
        cin>>p>>d>>t;
        Node* x=new Node(p,d,t);
        v.pb(x);
        total+=t;
        penalty+=p;
    }
    sort(v.begin(),v.end(),func);
    int dp[n+1][total+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=total;j++){
            dp[i][j]=0;
        }
    }
    int saved=0;
    unordered_map<int,int> amap;
    for(int i=1;i<=n;i++){
        Node* curr=v[i-1];
        int t=curr->time;
        int p=curr->penalty;
        int d=curr->deadline;
        for(int j=1;j<=d;j++){
            if(t<=j){
                dp[i][j]=max(dp[i-1][j],p+dp[i-1][j-t]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
            saved=max(saved,dp[i][j]);
            if(amap.count(dp[i][j])==0){
                amap[dp[i][j]]=i-1;
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=total;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    penalty-=saved;
    cout<<"SAVED AMOUNT ->"<<endl;
    cout<<saved<<endl;
    cout<<"PENALTY AMAOUNT ->"<<endl;
    cout<<penalty<<endl;
    vector<Node*> order;
    unordered_map<int,int>done;
    while(saved!=0){
        order.pb(v[amap[saved]]);
        done[amap[saved]]=1;
        saved-=v[amap[saved]]->penalty;
        
    }
    reverse(order.begin(),order.end());
    cout<<"DONE ->"<<endl;
    for(int i=0;i<order.size();i++){
        cout<<order[i]->penalty<<" "<<order[i]->deadline<<" "<<order[i]->time<<endl;
    }
    cout<<"PENALTIES ->"<<endl;
    for(int i=0;i<v.size();i++){
        if(done.count(i)==0){
            cout<<v[i]->penalty<<" "<<v[i]->deadline<<" "<<v[i]->time<<endl;
        }
    }
}
int main()
{
    fast_cin();
        solve();
    return 0;
}
/*
INTPUT->
4
5 1 1
10 3 2
6 2 1
3 1 1

OUTPUT->
SAVED AMOUNT ->
16
PENALTY AMAOUNT ->
8
DONE ->
6 2 1
10 3 2
PENALTIES ->
5 1 1
3 1 1

*/
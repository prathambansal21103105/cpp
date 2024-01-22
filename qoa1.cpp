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
ll MOD = 998244353;
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
#define pb push_back
bool func(string& s1, string& s2){
    return s1.length()>s2.length();
}
string longestString(int n, string s){
    if(n==1 or n==2){
        return "not found";
    }
    unordered_map<string,int >amap;
    string str="";
    for(int i=0;i<n-1;i++){
        str+=s[i];
        amap[str]++;
    }
    string str1="";
    for(int i=n-1;i>0;i--){
        str1=s[i]+str1;
        amap[str1]++;
    }
    vector<string>possible;
    for(auto i:amap){
        if(amap[i.first]>1){
            possible.pb(i.first);
        }
    }
    sort(possible.begin(),possible.end(),func);
    string str2="";
    for(int i=1;i<n-1;i++){
        str2+=s[i];
    }
    int flag=0;
    string ans="";
    for(int i=0;i<possible.size();i++){
        ans=possible[i];
        if(ans.length()>str2.length()){
            continue;
        }
        size_t found=str2.find(ans);
        if(found!=string::npos){
            flag=1;
            break;
        }
    }
    if(flag==1){
        return ans;
    }
    else{
        return "not found";
    }
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n==1){
        cout<<"not found"<<endl;
        return;
    }
    vector<string>pre;
    vector<string>suff;
    unordered_map<string,int >amap;
    string str="";
    for(int i=0;i<n-1;i++){
        str+=s[i];
        amap[str]++;
    }
    string str1="";
    for(int i=n-1;i>0;i--){
        str1=s[i]+str1;
        amap[str1]++;
    }
    vector<string>possible;
    for(auto i:amap){
        if(amap[i.first]>1){
            possible.pb(i.first);
        }
    }
    sort(possible.begin(),possible.end(),func);
    string str2="";
    for(int i=1;i<n-1;i++){
        str2+=s[i];
    }
    int flag=0;
    string ans="";
    for(int i=0;i<possible.size();i++){
        ans=possible[i];
        size_t found=str2.find(ans);
        if(found!=string::npos){
            flag=1;
            break;
        }
    }
//     size_t found = s2.find(str2);
//   if (found != string::npos)
//     cout << found << endl;
    
    
    if(flag==1){
        cout<<ans<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }
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

// size_t found = s2.find("geeks.practice",
//                           0, 5);
//   if (found != string::npos)
//     cout << found << endl;
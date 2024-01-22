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

void binarysearch(vector<int>& v, vector<int>&prefix, int st, int end){
    if(st==end){
        cout<<"?"<<" "<<1<<" "<<st+1<<endl;
        int y;
        cin>>y;
        cout<<"!"<<" "<<st+1<<endl;
        cout<<flush;
        // cout<<flush<<endl;
    }
    else if(st<end){
        int mid=(st+end)/2;
        cout<<"?"<<" "<<(mid-st+1)<<" ";
        for(int i=st;i<=mid;i++){
            cout<<i+1<<" ";
        }
        cout<<endl;
        cout<<flush;
        int y;
        cin>>y;

        int target=0;
        if(st==0){
            target=prefix[mid]-0;
        }
        else{
            target=prefix[mid]-prefix[st-1];
        }
        if(y==target){
            binarysearch(v,prefix,mid+1,end);
        }
        else{
            binarysearch(v,prefix,st,mid);
        }
    }
    else{
        return;
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int>v;
    vector<int>prefix;
    int sum1=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.pb(x);
        sum1+=x;
        prefix.pb(sum1);
    }
    binarysearch(v,prefix,0,n-1);
}
int main()
{
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

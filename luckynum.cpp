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

void solve(){
    int l,r;
    cin>>l>>r;
    int diff=r-l+1;
    if(diff>100){
        r=l+99;
        if(l%100<90){
            int x=l%100;
            int y=90-x;
            cout<<l+y<<endl;
        }
        else{
            string str;
            while(r>0){
                int last=r%10;
                char x='0'+last;
                str=x+str;
                r/=10;
            }
            str[str.length()-2]='9';
            str[str.length()-1]='0';    
            cout<<str<<endl;
        }
    }
    else{
        int ans=-1;
        int val=0;
        for(int i=l;i<=r;i++){
            int curr=i;
            int min1=INT_MAX;
            int max1=INT_MIN;
            while(curr>0){
                int last=curr%10;
                min1=min(min1,last);
                max1=max(max1,last);
                curr=curr/10;
            }
            if(abs(max1-min1)>ans){
                ans=abs(max1-min1);
                val=i;
            }
        }
        cout<<val<<endl;
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

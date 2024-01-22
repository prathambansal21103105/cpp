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
    int q;
    cin>>q;
    int h=-1;
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        int max1=INT_MIN;
        if(x&1){
            int a,b,n;
            cin>>a>>b>>n;
            int newh=((a-b)*(n-1))+a;
            int newh1=((a-b)*(n-1));
            if(h==-1){
                h=newh;
                max1=max(max1,newh1);
                cout<<1<<endl;
            }
            else{
                if(newh<=max1){
                    cout<<0<<endl;
                }
                else{
                    h=max(h,newh);
                    max1=max(max1,newh1);
                    cout<<1<<endl;
                }
            }
        }
        else{
            int a,b;
            cin>>a>>b;
            if(h==-1){
                cout<<-1<<endl;
            }
            else{
                int val=0;
                if((h-a)%(a-b)==0){
                    val=(h-a)/(a-b);
                }
                else{
                    val=((h-a)/(a-b))+1;
                }
                val+=1;
                int val1=0;
                
                cout<<val<<endl;
            }
        }
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

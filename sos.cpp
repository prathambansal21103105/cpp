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
    int n,k;
    cin>>n>>k;
    vector<int>v;
    for(int i=0;i<n;i++){
        v.pb(-31);
    }
    if(n==2){
        if(k==0){
            cout<<-1<<" "<<-1<<endl;
        }
        else if(k==1){
            cout<<1<<" "<<-1000<<endl;
        }
        else if(k==2){
            cout<<1000<<" "<<-1<<endl;
        }
        else{
            cout<<1<<" "<<1<<endl;
        }
        return;
    }
    vector<int>v1;
    for(int i=1;i<=30;i++){
        v1.pb(i*(i+1)/2);
    }
    int ans=0;
    int index=-1;
    for(int i=0;i<30;i++){
        if(v1[i]<=k){
            ans=v1[i];
            index=i;
        }
    }
    // cout<<ans<<endl;
    // cout<<index<<endl;
    for(int i=0;i<=index;i++){
        v[i]=2;
    }
    if(index+2<n){
        for(int i=index+2;i<n;i++){
            v[i]=-1000;
        }
    }
    k-=ans;
    if(k==0){
        if(index+1<n){
            v[index+1]=-1000;
        }
    }
    else{
        if(index+1<n){
            int sum=(2*(index+1));
            sum*=-1;
            sum+=1;
            int count=1;
            while(count<k){
                sum+=2;
                count++;
            }
            v[index+1]=sum;
        }
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

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

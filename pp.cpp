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

void solve(){
    int k,n,m;
    cin>>k>>n>>m;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.pb(x);
    }
    vector<int>v1;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        v1.pb(x);
    }
    int count=k;
    int i=0;
    int j=0;
    vector<int>ans;
    while(true){
        if(i==n and j==m){
            break;
        }
        if(i<n and j<m){
            if(v[i]==0){
                ans.pb(v[i]);
                i++;
                k++;
            }
            else{
                if(v[i]<=k){
                    ans.pb(v[i]);
                    i++;
                }
                else{
                    if(v1[j]==0){
                        ans.pb(v1[j]);
                        j++;
                        k++;
                    }
                    else{
                        if(v1[j]<=k){
                            ans.pb(v1[j]);
                            j++;
                        }
                        else{
                            cout<<-1<<endl;
                            return;
                        }
                    }
                }
            }
        }
        else if(i<n){
            if(v[i]==0 or v[i]<=k){
                ans.pb(v[i]);
                if(v[i]==0){
                    k++;
                }
                i++;
            }
            else{
                cout<<-1<<endl;
                return;
            }
        }
        else{
            if(v1[j]==0 or v1[j]<=k){
                ans.pb(v1[j]);
                if(v1[j]==0){
                    k++;
                }
                j++;
            }
            else{
                cout<<-1<<endl;
                return;
            }
        }
    }
    for(int r=0;r<ans.size();r++){
        cout<<ans[r]<<" ";
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

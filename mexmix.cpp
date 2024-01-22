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
    int a,b;
    cin>>a>>b;
    int xor1=0;
    for(int i=0;i<a;i++){
        xor1=xor1 xor i;
    }
    int target=xor1 xor b;
    if(target==0){
        cout<<a<<endl;
    }
    else if(target==a){
        cout<<a+2<<endl;
    }
    else{
        cout<<a+1<<endl;
    }
}

void count() {
    int n,k;
    cin>>n>>k;
    vector<int> price(n);
    forn(i,n) cin>>price[i];

    // int low=0,high=1;
    // int ans=0;
    // for(int i=0;i<n;i++){
    //     while(price[low]<price[high]) {
    //         high++;
    //         low++;
            
    //     }
    //     if(high-low>=k) ans++;
    //     else if(high-low>k) {
    //         int d=high-low-k;
    //         ans+=d;
    //     }

    // }
    // cout<<ans<<endl;
    int i=0;
    int j=1;
    int temp=0;
    int count=0;
    while(j<n){
        
        if(price[j]>price[temp]){
            temp++;
            j++;
            if(j-(i)==k-1){ 
                cout<<j<<" "<<i<<endl;
                count++;
                i++;
                temp=i;
                j++;
            }
        }
        else{
            i=j;
            temp=i;
            j=i+1;
        }
    }
    cout<<j<<" "<<i<<endl;
    cout<<count<<endl;


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

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
#define ln "\n"
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
    int n;
    cin>>n;
    vector<int>v;
    int check=0;
    int fre[200001]={0};
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        fre[x]+=1;
        if(x==0){
            check=1;
        }
        v.push_back(x);
    }
    int sum1=0;
    int count=0;
    for(int i=0;i<200001;i++){
        int flag=0;
        int taken=0;
        int flag1=0;
        if(fre[i]==0){
            flag=1;
            continue;
        }
        fre[i]+=sum1;
        for(int j=i+1;j<=fre[i];j++){
            if(j!=i){
            if(fre[j]>0){
                // cout<<j<<" ";
                flag1=1;
                break;
            }
            }
        }
        // cout<<fre[i]<<endl;
        if(fre[i]>i and flag!=1 and flag1!=1){
            count+=1;
            taken=1;
        }
        sum1=fre[i];
        if(taken==1){
            fre[i]=0;
        }
    }
    int ans=count;
    if(check==1){
        cout<<ans<<endl;
    }
    else{
        cout<<ans+1<<endl;
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

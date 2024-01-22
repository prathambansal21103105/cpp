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
    int arr[200000+1]={0};
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[x]=i;
        v.push_back(x);
    }
    if(n==1 or n==2 or n==3){
        cout<<-1<<endl;
        return;
    }
    int min1=1;
    int max1=n;
    int i=0;
    int j=n-1;
    while(i<=j){
        if((v[i]!=min1 and v[i]!=max1) and (v[j]!=min1 and v[j]!=max1)){
            cout<<i+1<<" "<<j+1<<endl;
            return;
        }
        else{
            if(v[i]==min1){
                i++;
                min1++;
            }
            if(v[i]==max1){
                i++;
                max1--;
            }
            if(v[j]==min1){
                j--;
                min1++;
            }
            if(v[j]==max1){
                j--;
                max1--;
            }
        }
    }
    cout<<-1<<endl;
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
/*
M 1 1 1 1 1 1
1 3 2 4 6 5 7
m 1 3 3 4 6 6

3 6
2 5
1 1

2 2 4 5 5 7 M
1 3 2 4 6 5 7
7 7 7 7 7 7 m

2 5
3 6
2 2


*/
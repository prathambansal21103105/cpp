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
void bubblesort(vector<int>& v1,vector<int>& v2,vector<vector<int> >& output){
    for(int i=0;i<v1.size()-1;i++){
        for(int j=0;j<v1.size()-1-i;j++){
            if(v1[j]>v1[j+1]){
                int temp=v1[j];
                v1[j]=v1[j+1];
                v1[j+1]=temp;
                int temp1=v2[j];
                v2[j]=v2[j+1];
                v2[j+1]=temp1;
                vector<int>v;
                v.pb(j+1);
                v.pb(j+2);
                output.pb(v);
            }
        }
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int>v1;
    vector<int>v11;
    vector<int>v2;
    vector<int>v22;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v1.pb(x);
        v11.pb(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v2.pb(x);
        v22.pb(x);
    }
    sort(v11.begin(),v11.end());
    sort(v22.begin(),v22.end());
    vector<vector<int> > output;
    bubblesort(v1,v2,output);
    bubblesort(v2,v1,output);
    if(v1==v11 and v2==v22){
        cout<<output.size()<<endl;
        for(int i=0;i<output.size();i++){
            cout<<output[i][0]<<" "<<output[i][1]<<endl;
        }
    }
    else{
        cout<<-1<<endl;
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

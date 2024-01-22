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

double dist(double x, double y, double a, double b){
    double dist1=((x-a)*(x-a))+((y-b)*(y-b));
    return sqrt(dist1);
}
bool check(vector<vector<double> >& v, double mid, double x, double y){
    for(int i=0;i<v.size();i++){
        double dist1=dist(x,y,v[i][0],v[i][1]);
        if(dist1>=mid+v[i][2]){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
double binarysearch(vector<vector<double> >& v, double x, double y, double n, double st, double en , double val){
    if(st<=en){
        double mid=(st+en)/2;
        if(check(v,mid,x,y)){
            val=max(val,mid);
            return binarysearch(v,x,y,n,mid+1,en,val);
        }
        else{
            return binarysearch(v,x,y,n,st,mid-1,val);
        }
    }
    else{
        return val;
    }
}

void solve(int count){
    double a,b;
    cin>>a>>b;
    double c,d;
    cin>>c>>d;
    double x,y;
    cin>>x>>y;
    double n;
    cin>>n;
    vector<vector<double>> v;
    for(int i=0;i<n;i++){
        double x1,y1,z1;
        cin>>x1>>y1>>z1;
        vector<double> v1;
        v1.pb(x1);
        v1.pb(y1);
        v1.pb(z1);
        v.pb(v1);
    }
    double x1=(a+c)/2;
    double y1=(b+d)/2;
    double dist1=dist(x,y,x1,b);
    double dist2=dist(x,y,a,y1);
    double dist3=dist(x,y,x1,d);
    double dist4=dist(x,y,c,y1);
    double r1=min(dist1,min(dist2,min(dist3,dist4)));
    // x1,b
    // a,y1
    // x1,d
    // c,y1
    // min distance 
    double val=0;
    double ans=binarysearch(v,x,y,n,0,r1,val);
    int ans1=ans;
    cout<<"Case "<<count<<": "<<ans1<<endl;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
	int count=1;
    while(t--){
        solve(count);
		count++;
    }
    return 0;
}

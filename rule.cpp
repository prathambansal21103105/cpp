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
bool recur(vector<vector<int> >&v, vector<int>v1, int x, int y, int currsum, int target, int st, int en){
    if(st==en){
        if(currsum==target){
            v.push_back(v1);
            return true;
        }
        else{
            return false;
        }
    }
    else{
        vector<int>v2;
        for(int i=0;i<v1.size();i++){
            v2.push_back(v1[i]);
        }
        v1.push_back(x);
        bool a=recur(v,v1,x,y,currsum+x,target,st+1,en);
        v2.push_back(y);
        bool b=recur(v,v2,x,y,currsum+y,target,st+1,en);
        return a or b;
    }
}
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    int u=x;
    int v=y;
    x=min(u,v);
    y=max(u,v);
    if(x==0 and y==0){
        cout<<-1<<endl;
        return;
    }
    if(x==0){
        int target=n-1;
        int b=target/y;
        int rem=target%y;
        if(b>=n){
            cout<<-1<<endl;
        }
        else{
            if(rem==0){
            vector<int>v;
            for(int i=0;i<n;i++){
                if(i<b){
                    v.push_back(y);
                }
                else{
                    v.push_back(0);
                }
            }
            int check=0;
            int k=1;
            for(int i=0;i<v.size();i++){
                for(int j=0;j<v[i];j++){
                    cout<<k<<" ";
                    check=1;
                }
                if(v[i]!=0){
                    if(k==1){
                        k+=v[i];
                        k+=1;
                    }
                    else{
                        k+=v[i];
                    }
                }
            }
            cout<<endl;
            }
            else{
                cout<<-1<<endl;
                return;
            }
        }
        
        return;
    }
    int target=n-1;
    // ax+by=target
    int r=x;
    int y1=0;
    int x1=1;
    int flag=0;
    int w=n;
    while((target-r)>=0 and w>0 ){
        int b=(target-r)/y;
        int rem=(target-r)%y;
        if(rem==0 and b!=0){
            y1=b;
            if(x1+y1==n){
                flag=1;
                break;
            }
        }
        r+=x;
        x1+=1;
        w-=1;
    }
    if(flag==1){
        vector<int>v;
        for(int i=0;i<x1;i++){
            v.push_back(x);
        }
        for(int i=0;i<y1;i++){
            v.push_back(y);
        }
        int check=0;
        int k=1;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i];j++){
                cout<<k<<" ";
                check=1;
            }
            if(v[i]!=0){
                if(k==1){
                    k+=v[i];
                    k+=1;
                }
                else{
                    k+=v[i];
                }
            }
        }
        cout<<endl;

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

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
#define int long long

void remove(vector<long>&v, int index1){
    v.erase(v.begin()+index1);
}

void solve(){
    int n;
    cin>>n;
    if(n%2==0){
        int x=n/2;
        int y=n-x;
        cout<<x<<" "<<y<<endl; 
    }
    else{
        if(n%10==9){
            int temp=n;
            vector<int>v;
            while(temp>0){
                v.push_back(temp%10);
                temp/=10;
            }
            reverse(v.begin(),v.end());
            
            int x=0;
            int y=0;
            vector<int>v1;
            vector<int>v2;
            for(int i=0;i<v.size();i++){
                if(v[i]%2==0){
                    v1.push_back(v[i]/2);
                    v2.push_back(v[i]/2);
                }
                else{
                    if(x==y or x>y){
                        v1.push_back(v[i]/2);
                        v2.push_back(v[i]-(v[i]/2));
                        y++;
                    }
                    else{
                        v2.push_back(v[i]/2);
                        v1.push_back(v[i]-(v[i]/2));
                        x++;
                    }
                }
            }
            // for(int i=0;i<v1.size();i++){
            //             cout<<v1[i];
            //         }
            //         cout<<" ";
            //         for(int i=0;i<v2.size();i++){
            //             cout<<v2[i];
            //         }
            //         cout<<endl;
            int x1=0;
            int y1=0;
            for(int i=0;i<v1.size();i++){
                x1=(x1*10)+v1[i];
                y1=(y1*10)+v2[i];
            }
            cout<<x1<<" "<<y1<<endl;
        }
        else{
            int x=n/2;
            int y=n-x;
            cout<<x<<" "<<y<<endl;
        }
    }
}
signed main()
{
    fast_cin();
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

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
int sum(int bit[], int index){
    int sum1=0;
    for(int i=index;i>0;i-=(i&(-i))){
        sum1+=bit[i];
    }
    return sum1;
}
void update(int bit[], int index, int last, int x){
    for(int i=index;i<=last;i+=(i&(-i))){
        bit[i]+=x;
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>v;
    v.pb(0);
    int bit[n+1];
    for(int i=0;i<=n;i++){
        bit[i]=0;
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v.push_back(x);
        update(bit,i,n,x);
    }
    int min1=INT_MAX;
    for(int i=1;i<=n;i++){
        min1=min(min1,sum(bit,i));
    }
    if(min1==sum(bit,m)){
        cout<<0<<endl;
    }
    else{
        int count=0;
        priority_queue < int, vector<int>, greater<int> > pq1;
        if(m+1<=n){
            if(sum(bit,m+1)<sum(bit,m)){
                update(bit,m+1,n,(-2*(v[m+1])));
                v[m+1]*=-1;
                count++;
            }
            else{
                if(v[m+1]<0){
                    pq1.push(v[m+1]);
                }
            }
        }
        for(int i=m+2;i<=n;i++){
            if(v[i]<0){
                pq1.push(v[i]);
            }
            if(sum(bit,i)<sum(bit,m)){
                int val=sum(bit,m);
                while(sum(bit,i)<val){
                    int x=pq1.top();
                    update(bit,i,n,(-2*x));
                    pq1.pop();
                    count++;
                }
            }
        }
        // cout<<count<<endl;
        // cout<<count<<endl;
        // for(int i=1;i<=n;i++){
        //     cout<<sum(bit,i)<<" ";
        // }
        // cout<<endl;
        if(m>1){
            priority_queue<int>pq;
            if(sum(bit,m-1)<sum(bit,m)){
                update(bit,m,n,(-2*v[m]));
                v[m]*=-1;
                count++;
                if(v[m-1]>0){
                    pq.push(v[m-1]);
                }
            }
            else{
                if(v[m]>0){
                    pq.push(v[m]);
                }
                if(v[m-1]>0){
                    pq.push(v[m-1]);
                }
            }
            // cout<<count<<endl;
            // for(int i=1;i<=n;i++){
            //     cout<<sum(bit,i)<<" ";
            // }
            // cout<<endl;

            for(int i=m-2;i>=1;i--){
                int val=sum(bit,i);
                while(val<sum(bit,m)){
                    if(pq.size()!=0){
                        int x=pq.top();
                        update(bit,m,n,-2*(x));
                        pq.pop();
                        count++;
                    }
                    else{
                        break;
                    }
                }
                if(v[i]>0){
                    pq.push(v[i]);
                }
            }
        }
        cout<<count<<endl;
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
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
int binary(int k, int diff, int st, int en, int target, int val){
    if(st<=en){
        int mid=(st+en)/2;
        long long sum=mid*((2*k)+((mid-1)*diff))/2;
        if(sum>=target){
            val=min(val,mid);
            // if(val==2){
                // cout<<mid<<"  "<<(mid*((2*k)+((mid-1)*diff))/2)<<endl;
            // }
            return binary(k,diff,st,mid-1,target,val);
        }
        else{
            return binary(k,diff,mid+1,en,target,val);
        }
    }
    else{
        return val;
    }
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>h;
    vector<int>p;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        h.pb(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        p.pb(x);
    }
    map<int,int>amap;
    for(int i=0;i<n;i++){
        if(amap.count(p[i])==0){
            amap[p[i]]=h[i];
        }
        else{
            amap[p[i]]=max(amap[p[i]],h[i]);
        }
    }
    vector<vector<int> > v;
    unordered_map<int,int>amap1;
    priority_queue<int,vector<int>,greater<int> > pq;
    int max1=INT_MIN;
    for(auto i:amap){
        vector<int>v1;
        if(i.second-k<=0){
            continue;
        }
        v1.pb(i.first);
        v1.pb(i.second-k);
        v.pb(v1);
        amap1[i.first]=i.second-k;
        pq.push(i.first);
        max1=max(max1,i.second-k);
        // cout<<i.first<<" "<<i.second<<endl;
    }
    // for(int i=0;i<v.size();i++){
        // cout<<v[i][0]<<" "<<v[i][1]<<endl;
    // }
    if(v.size()==0){
        cout<<"YES"<<endl;
    }
    else{
        long long sum=0;
        while(!pq.empty()){
            int x=pq.top();
            int diff=(-1)*x;
            int tar=amap1[x];
            amap1[x]-=sum;
            if(amap1[x]<=0){
                amap1[x]=0;
            }
            else{
                k-=x;
                if(k<=0){
                    cout<<"NO"<<endl;
                    return;
                }
                // cout<<x<<" "<<amap1[x]<<" "<<k<<endl;
                if(k>=amap1[x]){
                    sum+=k;
                }
                else{
                    int rem=k%x;
                    int y=0;
                    if(rem==0){
                        y=k/x;
                    }
                    else{
                        y=(k/x)+1;
                    }
                    if(y>100000){
                        y=100000;
                    }
                    int end=y;
                    int start=1;
                    // cout<<"y: "<<y<<endl;
                    // cout<<k<<" "<<amap1[x]<<endl;
                    int ans=binary(k,diff,1,y,amap1[x],INT_MAX);
                    // cout<<ans<<endl;
                    if(ans==INT_MAX){
                        cout<<"NO"<<endl;
                        return;
                    }
                    else{
                        int add=ans*((2*k)+((ans-1)*diff))/2;
                        sum+=add;
                        k-=((ans-1)*x);
                    }
                }
            }
            pq.pop();
        }
        // cout<<sum<<" "<<max1<<endl;
        if(sum>=max1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
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

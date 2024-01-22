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

void solve(){
    int n;
    cin>>n;
    vector<int>v;
    int max1=INT_MIN;
    int min1=INT_MAX;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.pb(x);
        max1=max(max1,x);
        min1=min(min1,x);
    }
    int val=max1-min1;
    sort(v.begin(),v.end());
    vector<int>v1;
    int i=0;
    int j=n-1;
    int sum=0;
    int count=0;
    if(n==1){
        cout<<"NO"<<endl;
        return;
    }
    for(int k=0;k<n;k++){
        int flag=0;
        if(sum>0){
            while(sum>0){
                v1.push_back(v[i]);
                count++;
                sum+=v[i];
                i++;
                if(count==n){
                    flag=1;
                    break;
                }
            }
        }
        else if(sum<0){
            while(sum<0){
                v1.push_back(v[j]);
                count++;
                sum+=v[j];
                j--;
                if(count==n){
                    flag=1;
                    break;
                }
            }
        }
        else{
            v1.push_back(v[i]);
            i++;
            sum+=v[i];
        }
        if(flag==1){
            break;
        }
    }
    int sum1=0;
    int prev=0;
    int curr=0;
    for(int i=0;i<n;i++){
        if(v1[i]>=0){
            curr=1;
        }
        else{
            curr=0;
        }
        if(prev==curr){
            sum1+=v1[i];
            if(abs(sum1)>=val){
                cout<<"NO"<<endl;
            }
        }
        else{
            prev=curr;
            sum1=0;
            sum1+=v1[i];
            if(abs(sum1)>=val){
                cout<<"NO"<<endl;
            }
        }
        
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        cout<<v1[i]<<" ";
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

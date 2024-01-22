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

int binarysearch(int arr[], int curr, int st, int en, int val){
    if(st<=en){
        int mid=(st+en)/2;
        if(arr[mid]==curr){
            val=max(val,mid+1);
            return binarysearch(arr,curr,mid+1,en,val);
        }
        else if(arr[mid]<curr){
            val=max(val,mid+1);
            return binarysearch(arr,curr,mid+1,en,val);
        }
        else{
            return binarysearch(arr,curr,st,mid-1,val);
        }
    }
    else{
        return val;
    }
}

void solve(){
    string s;
    cin>>s;
    int x=s.length();
    int minel=s[0]-'0';
    int maxel=s[0]-'0';
    int v[x];
    // int minarr[x];
    int maxarr[x];
    for(int i=0;i<x;i++){
        v[i]=INT_MAX;
        // minarr[i]=INT_MAX;
        maxarr[i]=INT_MAX;
    }
    int j=0;
    int count=0;
    for(int i=0;i<s.length();i++){
        int curr=s[i]-'0';
        // cout<<"j:"<<j<<endl;
        // cout<<"curr:"<<curr<<endl;
        if(curr>=minel and curr>=maxel){
            // cout<<"NO"<<endl;
            maxel=max(maxel,curr);
            v[j]=i;
            // minarr[j]=minel;
            maxarr[j]=maxel;
            j++;
            count++;
        }
        else if(curr>=minel and curr<maxel){
            maxel=curr;
            // cout<<"YES "<<curr<<endl;
            // for(int k=0;k<count;k++){
                // cout<<maxarr[k];
            // }
            // cout<<endl;
            j=binarysearch(maxarr,curr,0,count-1,0);
            // cout<<j<<endl;
            count=j;
            v[j]=i;
            // minarr[j]=minel;
            maxarr[j]=maxel;
            j++;
            // for(int k=0;k<count;k++){
            //     cout<<v[k]<<" ";
            // }
            // cout<<endl;
            count++;
            // cout<<count<<endl;
        }
        else if(curr<minel){
            minel=curr;
            maxel=curr;
            j=0;
            count=0;
            v[j]=i;
            // minarr[j]=minel;
            maxarr[j]=maxel;
            j++;
            count++;
        }
    }
    // for(int i=0;i<count;i++){
        // cout<<s[v[i]];
    // }
    // cout<<endl;
    unordered_map<int,int>amap;
    for(int i=0;i<count;i++){
        amap[v[i]]=1;
    }
    vector<int>v1;
    for(int i=0;i<x;i++){
        if(amap.count(i)==0){
            int curr=s[i]-'0';
            v1.pb(min(curr+1,9));
        }
        else{
            int curr=s[i]-'0';
            v1.pb(curr);
        }
    }
    string ans="";
    sort(v1.begin(),v1.end());
    for(int i=0;i<v1.size();i++){
        char y=v1[i]+'0';
        ans+=y;
    }
    // cout<<count<<endl;
    cout<<ans<<endl;
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
1
04829

02599
9
01
112334567888999
02599
9
01
111334567888999

*/
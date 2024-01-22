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
    int n,k;
    cin>>n>>k;
 
    string s1;
    cin>>s1;
 
    string ans="";
 
    vector<int>v;
    unordered_map<int,int>amap;
 
    int fre[127]={0};
    int count1=0;
    for(int i=0;i<n;i++){
        int x=s1[i];
        if(fre[x]==0){
            v.push_back(x);
            amap[x]=count1;
            count1+=1;
        }
        fre[x]+=1;
    }
    char r='a';
    char u='y';
    int beg=r;
    int end=u;
    int min1=k;
    int sum=0;
    int extra=0;
    // for(int i=beg;i<=end;i++){
    //     cout<<fre[i]<<" ";
    // }
    // cout<<endl;
    int flag=0;
    int check=0;
    int flag1=0;
    for(int i=beg;i<=end;i++){
        cout<<fre[i]<<" ";
        if(flag==1){
            break;
        }
        // cout<<min1<<" ";
        char y=i;
        // cout<<y<<" ";
        if(fre[i]>min1){
            if(fre[i]<k){
                int diff=k-fre[i];
                char w=i;
                for(int j=0;j<diff;j++){
                    ans=w+ans;
                    count1+=1;
                    if(ans.length()==k){
                        flag=1;
                        break;
                        
                    }
                }
            }
        }
        else if(fre[i]<min1){
            int diff=min1-fre[i];
            sum+=diff;
            for(int l=end;l>=i+1;l--){
                if(fre[l]>sum){
                    fre[l]-=sum;
                    sum=0;
                }
                else{
                    sum-=fre[l];
                    fre[l]=0;
                }
                if(sum==0){
                    break;
                }
            }
            
            // cout<<diff<<" ";
            min1=fre[i];
            char w=i;
            for(int j=0;j<diff;j++){
                ans=w+ans;
                if(ans.length()==k){
                    flag=1;
                    break;
                }
                count1+=1;
            }
        }
        else{
            check+=1;
            if(check==(n/k) and check==(i-beg+1)){
                check=i;
                flag1=1;
                break;
            }
            continue;
        }
    }
    cout<<endl;
    if(flag1==1){
        for(int i=0;i<k;i++){
            char w=check+1;
            ans+=w;
        }
    }
    
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
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
void subseq(vector<int>& nums, vector<int> v, int x, int y, vector<vector<int> >& res){
    if(x>=y){
        if(v.size()==0){
            return;
        }
        res.push_back(v);
        return;
    }
    else if(x==0){
        subseq(nums,v,x+1,y,res);
        v.push_back(nums[x]);
        subseq(nums,v,x+1,y,res);
    } 
    else{
        subseq(nums,v,x+1,y,res);
        if(v.size()!=0){
            if(nums[x]>=v[v.size()-1]){
                v.push_back(nums[x]);
                subseq(nums,v,x+1,y,res);
            }
        }
        else{
            v.push_back(nums[x]);
            subseq(nums,v,x+1,y,res);
        }
    }
    return;
}
vector<vector<int> > findSubsequences(vector<int>& nums) {
    vector<int>v;
    int y=nums.size();
    int x=0;
    vector<vector<int> > res;
    subseq(nums,v,0,y,res);
    return res;       
}

int main()
{
    fast_cin();
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<vector<int> > res=findSubsequences(v);
    for(int i=res.size()-1;i>=0;i--){
        if(i==0){
            if(res[i].size()==1){
                res.erase(res.begin()+i);
            }
            break;
        }
        else if(res[i].size()==1){
            res.erase(res.begin()+i);
        }
        else if(res[i].size()==res[i-1].size()){
            int flag=0;
            for(int j=0;j<res[i].size();j++){
                if(res[i][j]!=res[i-1][j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                res.erase(res.begin()+i);
            }
        }
        else{
            continue;
        }
    }
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

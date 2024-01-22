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
	string w;
	cin>>w;
	int p;
	cin>>p;
	unordered_map<char,int>amap;
	char a='a';
	int val=1;
	for(int i=0;i<26;i++){
		int x='a';
		x+=i;
		char y=x;
		amap[y]=i+1;
	}
	vector<int>v;
	for(int i=0;i<w.length();i++){
		v.push_back(amap[w[i]]);
	}
	int target=p;
	int curr=0;
	string ans="";
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		if(curr+v[i]<=p){
			curr+=v[i];
			int r='a'-1+v[i];
			char r1=r;
			ans+=r1;
		}
	}
	int fre[126]={0};
	for(int i=0;i<ans.length();i++){
		int pos=ans[i];
		fre[pos]+=1;
	}
	ans="";
	for(int i=0;i<w.length();i++){
		int let=w[i];
		if(fre[let]>0){
			char lett=let;
			ans+=lett;
			fre[let]-=1;
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
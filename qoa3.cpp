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
int sum(int bit[], int index){
    int sum1=0;
    for(int i=index;i>0;i-=(i&(-i))){
      sum1+=bit[i];
    }
    return sum1;
}
/*To add a val to index i*/
void update(int bit[], int index, int last, int x){
    for(int i=index;i<=last;i+=(i&(-i))){
        bit[i]+=x;
    }
}

void solve(){
    
}
void removeAnagrams(string arr[], int N)
{
    // vector to store the final result
    vector<string> ans;
 
    // data structure to keep a mark
    // of the previously occurred string
    unordered_set<string> found;
 
    for (int i = 0; i < N; i++) {
 
        string word = arr[i];
 
        // Sort the characters
        // of the current string
        sort(begin(word), end(word));
 
        // Check if current string is not
        // present inside the hashmap
        // Then push it in the resultant vector
        // and insert it in the hashmap
        if (found.find(word) == found.end()) {
 
            ans.push_back(arr[i]);
            found.insert(word);
        }
    }
 
    // Sort the resultant vector of strings
    sort(begin(ans), end(ans));
 
    // Print the required array
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
}
 
// Driver code
int main()
{
    string arr[]
        = { "geeks", "keegs",
            "code", "doce" };
    int N = 4;
 
    removeAnagrams(arr, N);
 
    return 0;
}
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
vector<int> balancedOrNot (vector<string> exp,vector<int>maxval){
    vector<int>v;
    for(int i=0;i<exp.size();i++){
        string word=exp[i];
        stack<char>s;
        int count=0;
        for(int j=0;j<word.size();j++){
            if(s.size()==0){
                if(word[j]=='>'){
                    count++;
                }
                else{
                    s.push(word[j]);
                }
            }
            else{
                if(word[j]=='>'){
                    if(s.size()>0 and s.top()=='<'){
                        s.pop();
                    }
                    else{
                        count++;
                    }
                }
                else{
                    s.push(word[j]);
                }
            }
        }
        if(s.size()!=0){
            v.push_back(0);
        }
        else{
            if(count<=maxval[i]){
                v.push_back(1);
            }
            else{
                v.push_back(0);
            }
        }
    }
    return v;
}
// void solve(){
    
// }
// // int main()
// // {
// //     vector<string>exp;
// //     vector<int>maxval;
// //     for(int i=0;i<6;i++){
// //         string s;
// //         cin>>s;
// //         exp.pb(s);
// //     }
// //     for(int i=0;i<6;i++){
// //         int x;
// //         cin>>x;
// //         maxval.pb(x);
// //     }
// //     vector<int>v=balancedOrNot(exp,maxval);
// //     for(int i=0;i<v.size();i++){
// //         cout<<v[i]<<" ";
// //     }
// //     cout<<endl;
// //     return 0;
// // }

int findTwoThreePrime(int l, int r)
{
 
    int count = 0;
    if(l==1){
        count++;
        l++;
    }
    for (int i = l; i <= r; i++) {
        int num = i;
        if(num%3!=0 and num%5!=0){
            continue;
        }
        // While num is divisible by 2, divide it by 2
        while (num % 3 == 0)
            num /= 3;
 
        // While num is divisible by 3, divide it by 3
        while (num % 5 == 0)
            num /= 5;
 
        // If num got reduced to 1 then it has
        // only 2 and 3 as prime factors
        if (num == 1)
            count++;
    }
 
    return count;
}
// int main()
// {
//     int l = 1, r = 10;
//     cout << findTwoThreePrime(200, 405);
//     return 0;
// }

// string ltrim(const string &str) {
// 	string s(str);

// 	s.erase(
// 		s.begin(),
// 		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
// 	);

// 	return s;
// }

// string rtrim(const string &str) {
// 	string s(str);

// 	s.erase(
// 		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
// 		s.end()
// 	);

// 	return s;
// }

// vector<string> areAlmostEquivalent(vector<string> s, vector<string> t) {

// 	vector<string> result;

// 	for (int strIdx = 0; strIdx < s.size(); strIdx++) {
// 		int countAlpa_s[27] = { 0, };
// 		int countAlpa_t[27] = { 0, };

// 		for (int charIdx = 0; charIdx < s[strIdx].size(); charIdx++)
// 			countAlpa_s[s[strIdx][charIdx] - 'a']++;

// 		for (int charIdx = 0; charIdx < t[strIdx].size(); charIdx++)
// 			countAlpa_t[t[strIdx][charIdx] - 'a']++;

// 		int alpaIdx = 0;
// 		for (; alpaIdx< 26; alpaIdx++)
// 			if (abs(countAlpa_s[alpaIdx] - countAlpa_t[alpaIdx]) > 3) break;

// 		alpaIdx == 26 ? result.push_back("YES") : result.push_back("NO");
// 	}
// 	return result;

// }   

int func(int l, int r){
    long long num=1;
    unordered_map<int,int>amap;
    vector<long long>v3;
    while(num<INT_MAX){
        if(num>=l and num<=r){
            amap[num]++;
        }
        v3.push_back(num);
        num*=3;
    }
    num=1;
    vector<long long>v5;
    while(num<INT_MAX){
        if(num>=l and num<=r){
            amap[num]++;
        }
        v5.push_back(num);
        num*=5;
    }   
    for(int i=0;i<v3.size();i++){
        for(int j=0;j<v5.size();j++){
            long long val=v3[i]*v5[j];
            if(val>=l and val<=r){
                amap[num]++;
            }
        }
    }
    // for(auto i:amap){
    //     cout<<i.first<<endl;
    // }
    return amap.size();
}
int main(){
    int l,r;
    cin>>l>>r;
    cout<<func(l,r)<<endl;
}
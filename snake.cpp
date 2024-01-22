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
void helper(vector<vector<int> >& board, vector<int>& total, int moves, int curr, int n){
    if(curr==(n*n)){
        total.push_back(moves);
        return;
    }
    else{
        int pos=(curr-1)/n;
        int rem=(curr-1)%n;
        // cout<<curr<<" "<<moves<<" "<<board[pos][rem]<<endl;
        if(board[pos][rem]!=-1){
            curr=board[pos][rem];
        }
        if(curr==(n*n)){
            total.push_back(moves);
            return;
        }
        
        int max1=INT_MIN;
        int flag=0;
        for(int i=1;i<=6;i++){
            if(curr+i<=(n*n)){
                int pos=(curr+i-1)/n;
                int rem=(curr+i-1)%n;
                if(board[pos][rem]!=-1){
                    helper(board,total,moves+1,curr+i,n);    
                }
                else if(board[pos][rem]==-1){
                    max1=max(max1,i);
                    flag=1;
                }
            }
            else{
                break;
            }
        }
        if(flag==1){
            helper(board,total,moves+1,curr+max1,n);
        }
    }
    return;
}
int snakesAndLadders(vector<vector<int> >& board) {
    vector<int>total;
    vector<vector<int> >newboard;
    if(board.size()%2==0){
        for(int i=board.size()-1;i>=0;i--){
            if(i%2!=0){
                //push
                newboard.push_back(board[i]);
            }
            else{
                //reverse
                reverse(board[i].begin(),board[i].end());
                newboard.push_back(board[i]);
            }
        }
    }
    else{
        for(int i=board.size()-1;i>=0;i--){
            if(i%2==0){
                //push
                newboard.push_back(board[i]);
            }
            else{
                //reverse
                reverse(board[i].begin(),board[i].end());
                newboard.push_back(board[i]);
            }
        }
    }
    // for(int i=0;i<board.size();i++){
    //     for(int j=0;j<board.size();j++){
    //         cout<<newboard[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int n=board.size();
    int curr=1;
    helper(newboard,total,0,curr,n);
    int min1=INT_MAX;
    for(int i=0;i<total.size();i++){
        min1=min(total[i],min1);
    }
    if(min1==INT_MAX){
        return -1;
    }
    else{
        return min1;
    }
}
int main()
{
    fast_cin();
    int n;
    cin>>n;
    vector<vector<int> > board;
    for(int i=0;i<n;i++){
        vector<int>v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        board.push_back(v);
    }
    cout<<snakesAndLadders(board)<<endl;
    return 0;
}

/*
-1 -1 -1 -1 48 5 -1
12 29 13 9 -1 2 32
-1 -1 21 7 -1 12 49
42 37 21 40 -1 22 12
42 -1 2 -1 -1 -1 6
39 -1 35 -1 -1 39 -1
-1 36 -1 -1 -1 -1 5
*/
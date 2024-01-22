/*------------Pratham Bansal-----------------*/
/*---------------21103105--------------------*/
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
double eps = 1e-12;
#define endl "\n"
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

template <int MOD=1000000007>
struct Modular {
  int value;
  static const int MOD_value = MOD;

  Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
  Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

  Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
  Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
  Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

  friend Modular mexp(Modular a, long long e) {
    Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
  friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
  friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};

Modular<>z=1;
Modular<>y=0;

int Mex(vector<int> a) {
    sort(a.begin(), a.end());
    if(a[0] > 0) return 0;
    for (int i = 1; i < (int) a.size(); i++) {
        if (a[i] > a[i - 1] + 1) {
            return a[i - 1] + 1;
        }
    }
    return a.back() + 1;
}
void binary(vector<int>&v, int& target, int& val1, int st, int end){
    if(st<=end){
        int mid=(st+end)/2;
        if(v[mid]<=target){
           val1=max(val1,v[mid]);
           binary(v,target,val1,mid+1,end);
        }
        else{
           binary(v,target,val1,st,mid-1);
        }
    }
    else{
        return;
    }
}
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

/*---------------------------code------------------------------*/
/*-------------------------question 1--------------------------*/
string get(int x){
    if(x==2){
        return "abc";
    }
    else if(x==3){
        return "def";
    }
    else if(x==4){
        return "ghi";
    }
    else if(x==5){
        return "jkl";
    }
    else if(x==6){
        return "mno";
    }
    else if(x==7){
        return "pqrs";
    }
    else if(x==8){
        return "tuv";
    }
    else if(x==9){
        return "wxyz";
    }
    else{
        return "";
    }
}
void func(int n){
    string s=to_string(n);
    queue<string>q;
    q.push("");
    for(int i=0;i<s.length();i++){
        string poss=get(s[i]-'0');
        int sz=q.size();
        for(int j=0;j<sz;j++){
            string curr=q.front();
            q.pop();
            for(int k=0;k<poss.size();k++){
                q.push(curr+poss[k]);
            }
        }
    }
    vector<string>v;
    while(!q.empty()){
        v.push_back(q.front());
        q.pop();
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

}
void solve1(){
    int n;
    cin>>n;
    func(n);
}
/*-------------------------question 2--------------------------*/
vector<int>h;
vector<int>m;
vector<int> hrs[5];
vector<int> mns[7];
vector<string> geth(int x){
    vector<string>ret;
    for(int i=0;i<hrs[x].size();i++){
        string hr=to_string(hrs[x][i]);
        ret.push_back(hr);
    }
    return ret;
}
vector<string> getm(int y){
    vector<string>ret;
    for(int i=0;i<mns[y].size();i++){
        string ms;
        string x=to_string(mns[y][i]);
        if(x.size()==1){
            ms+='0';
            ms+=x;
        }
        else{
            ms+=x;
        }
        ret.push_back(ms);
    }
    return ret;
}
void subsequences(vector<int>&v, int i, int sum, int k, vector<int> out[]){
    if(i==v.size()){
        out[k].push_back(sum);
    }
    else{
        subsequences(v,i+1,sum,k,out);
        subsequences(v,i+1,sum+v[i],k+1,out);
    }
}
vector<string> helper(int n){
    vector<string>res;
    for(int i=0;i<=n;i++){
        int x=i;
        int y=n-i;
        if(x>4 or y>6){
            continue;
        }
        else{
            vector<string>hs=geth(x);
            vector<string>ms=getm(y);
            for(int j=0;j<hs.size();j++){
                for(int k=0;k<ms.size();k++){
                    string s1=hs[j];
                    string s2=ms[k];
                    s1.push_back(':');
                    s1+=s2;
                    res.push_back(s1);
                }
            }
        }
    }
    return res;
}
void solve2(){
    h.push_back(1);
    h.push_back(2);
    h.push_back(4);
    h.push_back(8);
    m.push_back(1);
    m.push_back(2);
    m.push_back(4);
    m.push_back(8);
    m.push_back(16);
    m.push_back(32);
    subsequences(h,0,0,0,hrs);
    subsequences(m,0,0,0,mns);
    int n;
    cin>>n;
    if(n>10 or n<0){
        cout<<"NOT POSSIBLE"<<endl;
        return;
    }
    vector<string>v=helper(n);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
/*-------------------------question 3--------------------------*/
void helper(int n, vector<string>& res){
    vector<string>v;
    if(n==1){
        string s="()";
        v.push_back(s);
        res=v;
        return;
    }
    else{
        string s="()";
        v.push_back(s);
        res=v;
        vector<vector<string> > out;
        out.push_back(v);
        for(int i=1;i<n;i++){
            unordered_set<string>aset;
            int j=0;
            int k=i-1;
            while(j<=k){
                for(int u=0;u<out[j].size();u++){
                    string str1=out[j][u];
                    for(int v=0;v<out[k].size();v++){
                        string str2=out[k][v];
                        string str3=str1;
                        str3+=str2;
                        string str4=str2;
                        str4+=str1;
                        aset.insert(str3);
                        aset.insert(str4);
                    }
                }
                j++;
                k--;
            }
            for(int l=0;l<out[i-1].size();l++){
                string str;
                str+='(';
                str+=out[i-1][l];
                str+=')';
                aset.insert(str);
            }
            vector<string>v1;
            for(auto i:aset){
                v1.push_back(i);
            }
            out.push_back(v1);
        }
        res=out[out.size()-1];
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    helper(n,res);
    return res;
}
void solve3(){
    int n;
    cin>>n;
    vector<string>v=generateParenthesis(n);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
/*-------------------------question 4--------------------------*/
bool possible(vector<string>& board, int row, int col, int n){
    for(int i=row;i>=0;i--){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    for(int i=col;i>=0;i--){
        if(board[row][i]=='Q'){
            return false;
        }
    }
    int row1=row;
    int col1=col;
    while(col1>=0 and row1>=0){
        if(board[row1][col1]=='Q'){
            return false;
        }
        row1--;
        col1--;
    }
    row1=row;
    col1=col;
    while(col1<n and row1>=0){
        if(board[row1][col1]=='Q'){
            return false;
        }
        row1--;
        col1++;
    }
    return true;
}

void helper(vector<string>& board, int row, int n, vector<vector<string> >& res){
    if(row==n){
        res.push_back(board);
    }
    else{
        for(int i=0;i<n;i++){
            if(possible(board,row,i,n)){
                board[row][i]='Q';
                helper(board,row+1,n,res);
                board[row][i]='.';
            }
        }
    }
}
vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > res;
    vector<string>board;
    string s;
    for(int i=0;i<n;i++){
        s+='.';
    }
    for(int i=0;i<n;i++){
        board.push_back(s);
    }
    helper(board,0,n,res);
    return res;
}
void solve4(){
    int n;
    cin>>n;
    vector<vector<string> > ans=solveNQueens(n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            for(int k=0;k<ans[i][j].size();k++){
                cout<<ans[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
int main()
{
    cout<<"Pratham Bansal"<<endl;
    cout<<"SID: 21103105"<<endl;
    // solve1();
    // solve2();
    // solve3();
    solve4();
    return 0;
}

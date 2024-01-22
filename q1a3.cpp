// #include<bits/stdc++.h>
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

// int helper(int numD,vector<int> deno,int value){
// if(value<=0){return 0;}
// int* ans=new int[value+1];
// for(int i=0;i<=value;i++){
// ans[i]=INT_MAX;
// }
// ans[0]=0;
// for(int i=1;i<=value;i++){
// int a=INT_MAX,b=INT_MAX,c=INT_MAX;
// a=ans[i-deno[0]]+1;
// if(i-deno[1]>=0){
// b=ans[i-deno[1]]+1;
// }
// if(i-deno[2]>=0){
// c=ans[i-deno[2]]+1;
// }
// ans[i]=min(a,min(b,c));
// }
// return ans[value];
// }

// int min_coin(int n){
// vector<int> coins;
// coins.push_back(1);
// coins.push_back(5);
// coins.push_back(10);
// return helper(3,coins,n);
// }

// int main(){
// cout<<"Name: Pratham Bansal SID: 21103105\n";
// cout<<"Enter the value\n";
// int n;
// cin>>n;
// cout<<"The minimun number of coins are: ";
// cout<<min_coin(n)<<endl;;
// }

// int solve(int total,int miles,vector<int> &input){
// int temp=miles;
// int ans=0;
// for(int i=0;i<input.size()-1;i++){
// if(input[i+1]>=temp && input[i]<=temp){
// temp=input[i]+miles;
// ans++;
// if((total-input[i])==0){
// --ans;
// return ans;
// }

// }
// }
// return -1;
// }

// int main(){
// cout<<"Name:Pratham Bansal SID: 21103105\n";
// int total;
// cout<<"Enter total miles: ";
// cin>>total;
// cout<<endl;

// int miles;
// cout<<"Enter miles car can cover 1 time: ";
// cin>>miles;
// cout<<endl;

// vector<int> input;
// int k;

// int j;
// cout<<"Enter the value of j: ";
// cin>>j;


//  cout<< "Enter here"<<endl;

// for(int i=0;i<j;i++){
// cin>>k;
// input.push_back(k);
// }
// input.push_back(total);
// input.push_back(5000000);

// int ans=solve(total,miles,input);

// cout<<ans<<endl;
// }

// bool endpoint(const pair<int, int> p1,const pair<int, int> p2)
// {
// return p1.second < p2.second;
// }

// int main(){
// cout<<"Name: Pratham Bansal SID:21103105\n";
// cout<<"Enter number of lines\n";
// int num_of_lines;
// cin>>num_of_lines;
// vector<pair<int,int> > v(num_of_lines);
// cout<<"Enter starting and endiing points of line segments\n";
// for(int i=0;i<num_of_lines;i++){
//  cin>>v[i].first;
// cin>>v[i].second;
// }
// vector<int> points;
// sort(v.begin(),v.end(),endpoint);
// int i=0;
// while(i<num_of_lines){
// int marked=v[i].second;
// int start=v[i].first;
// points.push_back(marked);
// if(i>=num_of_lines-1){
// break;
// }

// while(v[i].first<=marked){
// i++;
// if(i>=num_of_lines){
// break;
// }
// }

// }
// cout<<"The points are as follows\n";
// cout<<points.size()<<endl;
// for(int i=0;i<points.size();i++){
// cout<<points[i]<<" ";
// }cout<<endl;
// return 0;
// }

class edge{
public:
int v1;
int v2;
int weight;
};

bool comp(edge a,edge b){
return a.weight<b.weight;
}
int w=0;
void kruskals(int v,int e,edge*edges){

int *parents = new int[v];
for(int i=0;i<v;i++){
parents[i]=i;
}
edge * ans =new edge[v-1];
int count =0;
int i=0;
while(count<v-1){
edge temp = edges[i];
int s = temp.v1;
int e = temp.v2;
int parentss = s;
int parente =e;
while(parentss!=parents[parentss]){
parentss= parents[parentss];
}
while(parente!=parents[parente]){
parente= parents[parente];
}
if(parentss!=parente){
ans[count]=temp;
count++;
parents[parentss]= parente;
}
i++;

}
cout<<"The MST is as follows:\n";
for(int i=0;i<v-1;i++){
if(ans[i].v1<ans[i].v2){
cout<<char(65+ans[i].v1)<<" "<<char(65+ans[i].v2)<<" "<<ans[i].weight<<endl;
w+=ans[i].weight;
}
else{
cout<<char(65+ans[i].v2)<<" "<<char(65+ans[i].v1)<<" "<<ans[i].weight<<endl;

w+=ans[i].weight;
}
}

}

int main() {

cout<<"Name:Pratham Bansal SID:21103105\n";
cout<<"Enter the number of vertices\n";
int v,e;
edge temp;
cin>>v;
cout<<"Enter the number of edges\n";

cin>>e;
cout<<"Enter the edges starting point ending point and weight\n";
edge *edges = new edge[e];
for(int i=0;i<e;i++){
char x,y;
int z;
cin>>x>>y>>z;
temp.v1=x-'A';
temp.v2=y-'A';
temp.weight=z;
edges[i] =temp;
}
sort(edges,edges+e,comp);

kruskals(v,e,edges);

cout<<"weight of the MST:"<<" "<<w<<endl;
}

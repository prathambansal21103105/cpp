/*------------Pratham Bansal-----------------*/
#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
 
using namespace __gnu_pbds;
template<typename T, class C = std::less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> os;

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
int binexp(int a, int b, int M){
  if(b==0){
     return 1;
  }
  long long x=binexp(a,b/2,M)%M;
  if(b&1){
      return ((((a%M)*(x%M))%M)*(x%M))%M;
  }
  else{
      return ((x%M)*(x%M))%M;
  }
}
// /*     bin=pow(b,m-2)     */
// int sum(int bit[], int index){
//     int sum1=0;
//     for(int i=index;i>0;i-=(i&(-i))){
//       sum1+=bit[i];
//     }
//     return sum1;
// }
// /*To add a val to index i*/
// void update(int bit[], int index, int last, int x){
//     for(int i=index;i<=last;i+=(i&(-i))){
//         bit[i]+=x;
//     }
// }
 
long long GCD(long long x, long long y){
   if(y==0){
       return x;
   }
   return GCD(y, x%y);
}
long long LCM(long long x, long long y){
   return x*y/GCD(x,y);
}
bool isPrime(int n){
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
string getbin(int val){
    string str;
    for(int i=0;i<32;i++){
        if((val & (1<<i)) !=0){
            str='1' + str;
        }
        else{
            str='0' + str;
        }
    }
    return str;
}
vector<int> topoSort(int v, vector<int> adj[]) {
    vector<int>indegree(v,0);
    for(int i=0;i<v;i++){
        for(int j=0;j<adj[i].size();j++){
            indegree[adj[i][j]]++;
        }
    }
    vector<int>visited(v,0);
    vector<int>res;
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int f=q.front();
        q.pop();
        visited[f]=1;
        res.push_back(f);
        for(int i=0;i<adj[f].size();i++){
            indegree[adj[f][i]]--;
            if(indegree[adj[f][i]]==0){
                q.push(adj[f][i]);
            }
        }
    }
    return res;
}
vector<int> getPrimes(int n){
    vector<int>counts(n+1,0);
    vector<int>res;
    for(int i=2;i<=n;i++){
        if(counts[i]==0){
            res.pb(i);
            for(int j=i*i;j<=n;j+=i){
                counts[j]++;
            }
        }
        else{
            continue;
        }
    }
    return res;
}
/*------------code-----------------*/
#define int long long
int getSmaller(vector<int>& v, int day){
    int val=lower_bound(v.begin(),v.end(),day)-v.begin();
    return val;
}
int findParent(int node1, vector<int>& parent){
    if (node1 != parent[node1]) {
        parent[node1] = findParent(parent[node1], parent); // path compression
    }
    return parent[node1];
}
void unionByRank(int node1, int node2, vector<int>& parent, vector<int>& rank){
    int p1=findParent(node1,parent);
    int p2=findParent(node2,parent);
    if(p1!=p2){
        if(rank[p1]==rank[p2]){
            parent[p1]=p2;
            rank[p2]++;
        }
        else if(rank[p1]>rank[p2]){
            parent[p2]=p1;
        }
        else{
            parent[p1]=p2;
        }
    }
}
void build(vector<int>& seg, vector<int>& v, int l, int r, int i){
    if(l==r){
        seg[i]=v[l];
        return;
    }
    int mid=l+(r-l)/2;
    build(seg,v,l,mid,(2*i)+1);
    build(seg,v,mid+1,r,(2*i)+2);
    seg[i]=max(seg[(2*i)+1],seg[(2*i)+2]);
}
int query(vector<int>& seg, int l, int r, int i, int l1, int r1){
    if(l>=l1 && r<=r1){
        return seg[i];
    }
    else if(r<l1 || r1<l){
        return 0;
    }
    int mid=l+(r-l)/2;
    auto ans1=query(seg,l,mid,(2*i)+1,l1,r1);
    auto ans2=query(seg,mid+1,r,(2*i)+2,l1,r1);
    auto val=max(ans1,ans2);
    return val;
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

long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    
    return result;
}
 
long long modDiv(long long a, long long b, long long mod) {
    long long b_inv = modExp(b, mod - 2, mod);
    return (a * b_inv) % mod;
}

int makeSieve(int n){

	bool isPrime[n+1];
	for(int i=0;i<=n;i++){
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;

	for(int i=2;i*i<=n;i++){
		if(isPrime[i] == true){
			for(int j=i*i;j<=n;j+=i){
				isPrime[j] = false;
			}
		}
	}

	int count = 0;
	for(int i=0;i<=n;i++){
		if(isPrime[i] == true){
			count++;
		}
	}
	return count;

}

class Triplet{
    public:
    int x;
    int y;
    int gcd;
};
Triplet extendedEuclid(int a, int b){
    // a should be greater than or equal to b
    if(b==0){
        Triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }
    Triplet smallAns=extendedEuclid(b,a%b);
    Triplet ans;
    ans.gcd=smallAns.gcd;
    ans.x=smallAns.y;
    ans.y=smallAns.x - (a/b)*smallAns.y;
    return ans;
}
int mmInverse(int a, int m){
    Triplet ans = extendedEuclid(a,m);
    return ans.x;
}

struct Point{
    int x;
    int y;
};

bool toChange(Point p, Point q, Point r){
    int x1=q.x-p.x;
    int y1=q.y-p.y;
    int x2=r.x-q.x;
    int y2=r.y-q.y;
    int value=x1*y2-x2*y1;
    return value>0;
}

void convexHull(Point points[], int n){
    vector<Point> hull;
    int left=0;
    for(int i=1;i<n;i++){
        if(points[i].x<points[left].x){
            left=i;
        }
    }
    int p=left;
    do{
        hull.push_back(points[p]);
        int q=(p+1)%n;
        for(int i=0;i<n;i++){
            if(toChange(points[p],points[q],points[i])){
                q=i;
            }
        }
        p=q;

    } while(p!=left);

    for(int i=0;i<hull.size();i++){
        cout<<hull[i].x<<" "<<hull[i].y<<endl;
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int>x(n);
    vector<int>y(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int j=0;j<n;j++){
        cin>>y[j];
    }
    double ans=0;
    for(int i=1;i<n-1;i++){
        double x1=(x[i]-x[0])*1.0;
        double y1=(y[i]-y[0])*1.0;
        double x2=(x[i+1]-x[0])*1.0;
        double y2=(y[i+1]-y[0])*1.0;
        ans+=(x1*y2 - x2*y1);
    }
    ans/=2;
    ans=abs(ans);
    cout<<ans<<endl;
}
signed main()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll t;
    cin >> t;
    // vector<vector<int>>v(101,vector<int>(101,0));
    // for(int i=1;i<=100;i++){
    //     primefactors(i,v);
        // for(int j=1;j<101;j++){
        //     cout<<v[i][j]<<" ";
        // }
        // cout<<endl;
    // }
    // int count=1;
    while(t--){
        // cout<<"Case "<<count<<":"<<endl;
        // solve(v);
        solve();
        // count++;
    }
    // ordered_set<pair<int,int>>st;
    // st.insert({1,1});
    // st.insert({1,3});
    // st.insert({2,2});
    // int id = st.order_of_key({1,1});
    // auto val = *st.find_by_order(2);
    // // auto it=st.lower_bound(2);
    // // auto p=*it;
    // // cout<<p.first<<" "<<p.second<<endl;
    // cout<<val.first<<val.second<<endl;
    // cout<<id<<endl;
    // // st.erase({2,2});
    // cout<<st.size()<<endl;
    return 0;
}
/*
0 2
1 1
2 0
1 2 3 4
1 1 3 3
*/ 
/*
.ss.p..
*/
/*
1 2 3 4
1 4 2 3
1 4 3 2
*/
/*
2 1 3
3 2 1
2 1 3

1 3 2
3 2 1
2 1 3

1 2 4 5 3
5 2 1 3 4
4 5 3 1 2
2 3 5 4 1
3 1 4 2 5
*/
/*
1 2 3 4 5 6 7 8 9 10 11
6
3 4
2
*/
/*
6 0 0 3 0 -4 0 1 0 0 0 -10 0 4
6
12
18
27
36
41
46
52
28
64
70
78

*/
/*
1 -1 1 1 -1 1 1
/*
3,2,5,4,1
3 4 5 1 2
3 4 2 1
2 3 1
1 2 3 4
3
6
10
3
7
10

27 28 27
13 14 13
6 7 6

count=1 ans=7
ans=14

/*
5 4 1 2 3 
5 4 1 3 2
4 5 1 2 3
1 2 3 4
3
6
10
19
3
7
10

3 2 3 2 3 1
1 2 3
3
6
A=[4,5,3,7,1,9]
B=[4,3,5,2,6,1]
remove 1
4 3 5 2 1
remove 3
4 3 2 5 1
remove 4
3 4 2 5 1
remove 5
3 4 2 5 1
remove 7
3 2 4 5 1
remove 9
3 2 4 1 5
*/
/*
1 2 3 4 5 6 7
10
1
2
4
8
16
32
64
*/
/*
x y 
sum
sum-y
*/
/*
1 2 3 4 5
0 2 2 -1 2
0 2 2 0 2
0 1 2 0 1

4 2 4
-1 -1 -1 -1
0 2 -1 2
0 2 0 2
0 1 0 2



*/

/*
.sp
3 2 1
ss.pp

...pp
*/

/*
3 4 5 7
2 4 6 7
*/

/*
0 0 1 0 0 0 0 2
*/

/*
1 2 3 6 2 3 1
1 1 1 2 2 2 2
400 500 600 1000 1500 4000 3

a=5
b=0
c=0
k=1
9

a=1
b=1
c=1
k=2
3

a=600
b=1000
c=3400
k=3
*/

/*
1 2 3 4
1 3 4 2
1+1+1+1
3+3+2
4+2
2

*/


/*
1 2 3 4 5
1 2 3 5 4
1 2 4 5 3
1 2 5 4 3

1 3 4 5 2
1 3 5 4 2
1 4 5 3 2
1 5 4 3 2

1 2 3 4
1 2 4 3

1 3 4 2
1 4 3 2


*/












// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int d,x,y;
//     vector<int>parent(n,-1);
//     vector<int>rank(n,0);
//     vector<int>order(n,-1);
//     for(int i=0;i<n;i++){
//         parent[i]=i;
//     }
//     int count=0;
//     vector<pair<int,int> >queries;
//     for(int i=0;i<k;i++){
//         cin>>d>>x>>y;
//         if(x>n || y>n){
//             count++;
//             continue;
//         }
//         else{
//             int pt1=findParent(x-1,parent);
//             int pt2=findParent(y-1,parent);
//             if(d==1){
//                 if(pt1==pt2){
//                     int d1=getDistance(x-1);
//                     int d2=getDistance(y-1);
//                     int d3=(d1-d2)%3;
//                     if(d3!=0){
//                         count++;
//                     }
//                 }
//                 else{
//                     unionByRank(pt1,pt2,parent,rank);
//                 }
//             }
//             else{
//                 if(pt1==pt2){
//                     int d1=getDistance(x-1);
//                     int d2=getDistance(y-1);
//                     int d3=(d1-d2)%3;
//                     if(d3==-1 || d3==2){
//                         continue;
//                     }
//                     else{
//                         count++;
//                     }
//                 }
//                 else{
 
//                 }
//             }
//         }
//     }
//     cout<<count<<endl;
// }
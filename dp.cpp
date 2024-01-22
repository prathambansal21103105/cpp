#include<iostream>
using namespace std;

int fibo(int n){
    if(n<=1){
        return n;
    }
    int a=fibo(n-1);
    int b=fibo(n-2);
    return a+b;
}

int fibo_3(int n){
    int* ans=new int[n+1];
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<=n;i++){
        ans[i]=ans[i-1]+ans[i-2];
    }
    return ans[n];
}

int fibo_helper(int n,int*ans){
    if(n<=1){
        return n;
    }
    //Check if output already exists
    if(ans[n]!=-1){
        return ans[n];
    }
    int a=fibo_helper(n-1,ans);
    int b=fibo_helper(n-2,ans);

    //Save the output for future use
    ans[n]=a+b;
    return ans[n];
}
int fibo_2(int n){
    int*ans=new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
}
int main(){
    int n;
    cin>>n;
    cout<<fibo(n)<<endl;
    return 0;
}
/*


#include<bits/stdc++.h>
#include<vector>
using namespace std;
int flag=0;
void subsetsumk(int input[],int n,int k,vector<int>v,vector<vector<int>>&out){
    if(k==0){
        out.push_back(v);
        return;
    }
    if(n==0){
        return;
    }
    subsetsumk(input+1,n-1,k,v,out);
    if(input[0]<=k){
        v.push_back(input[0]);
        subsetsumk(input+1,n-1,k-input[0],v,out);
    }
    return;
}
int main(){
    // write your code here
    int t;
    cin>>t;
    while(t>0){
        int n,k;
        cin>>n>>k;
        int input[n];
        for(int i=0;i<n;i++){
            cin>>input[i];
        }
        vector<int> v;
        vector<vector<int>> out;
        subsetsumk(input, n, k, v, out);
        cout << out.size() << endl;
        t-=1;
    }
    return 0;
}
*/
/*
#include <climits>
int helper(int *ans, int n) {
  if (n == 1) {
    ans[1] = 0;
    return 0;
  }
  if (n == 2) {
    ans[2] = 1;
    return 1;
  }
  if (ans[n] != -1) {
    return ans[n];
  }
  int a = INT_MAX;
  int b = INT_MAX;
  int c = INT_MAX;
  a = helper(ans, n - 1);
  if (n % 2 == 0) {
    b = helper(ans, n / 2);
  }
  if (n % 3 == 0) {
    c = helper(ans, n / 3);
  }
  int min1 = INT_MAX;
  if (min1 > a) {
    min1 = a;
  }
  if (min1 > b) {
    min1 = b;
  }
  if (min1 > c) {
    min1 = c;
  }
  int retval = 1 + min1;
  ans[n] = retval;
  return retval;
}
int countStepsToOne(int n)
{
	//Write your code here
	int *ans = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		ans[i] = -1;
	}
	int retval = helper(ans, n);
	return retval;
}
*/
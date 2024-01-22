#include <iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

//Memoization solution
int longestIncreasingSubsequence(vector<int>arr1, int n,int curr, int max1,int** output) {
  if (n == 0) {
    return 0;
  } 
  if(output[n][max1]!=0 ){
	  return output[n][max1];
  }
  else {
    int ans = 0;
    if (arr1[curr]>arr1[max1]) {
        int a = 1 + longestIncreasingSubsequence(arr1 , n - 1, curr+1,curr,output);
        int b = longestIncreasingSubsequence(arr1 , n - 1, curr+1,max1,output);
        ans = max(a, b);
    } 
    else {
        ans = longestIncreasingSubsequence(arr1 , n - 1,curr+1, max1,output);
    }
    output[n][max1]=ans;
    return ans;
  }
}
int longestIncreasingSubsequence(int *arr, int n) {
  // Write your code here
  int**output=new int*[n+1];
  for(int i=0;i<=n;i++){
	  output[i]=new int[n+1];
  }
  for(int i=0;i<=n;i++){
	  for(int j=0;j<=n;j++){
		  output[i][j]=0;
	  }
  }
  vector<int>arr1;
  arr1.push_back(0);
  for(int i=0;i<n;i++){
    arr1.push_back(arr[i]);
  }
  return longestIncreasingSubsequence(arr1, n,1,0,output);
}

//recursive solution
int longestIncreasingSubsequence(int* arr, int n, int max1){
    if(n==0){
        return 0;
    }
    else{
        int ans=0;
        if(arr[0]>max1){
            int a=1+longestIncreasingSubsequence(arr+1,n-1,arr[0]);
            int b=longestIncreasingSubsequence(arr+1,n-1,max1);
            ans=max(a,b);
        }
        else{
            ans=longestIncreasingSubsequence(arr+1,n-1,max1);
        }
        return ans;
    }
}
int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
    int max1=INT_MIN;
    return longestIncreasingSubsequence(arr,n,max1);
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}
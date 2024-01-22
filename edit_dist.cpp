#include<iostream>
#include<cstring>
#include<climits>
#include<cmath>
using namespace std;

//DP solution
int editDistance_DP(string s1, string s2){
    int m=s1.length();
    int n=s2.length();
    int output[m+1][n+1];
    output[0][0]=0;
    for(int i=1;i<=m;i++){
        output[i][0]=i;
    }
    for(int i=1;i<=n;i++){
        output[0][i]=i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int ans=0;
            if(s1[m-i]==s2[n-j]){
                ans=output[i-1][j-1];
            }
            else{
                int a=output[i-1][j];
                int b=output[i][j-1];
                int c=output[i-1][j-1];
                ans=1+min(a,min(b,c));
            }
            output[i][j]=ans;
        }
    }
    return output[m][n];
}

//Memoization solution
int editDistance(string s1,string s2,int**output){
    int m=s1.length();
    int n=s2.length();
	int ans=INT_MAX;
	if(output[m][n]!=-1){
		return output[m][n];
	}
	else{
		if(m==0 or n==0){
			return max(m,n);
		}
		if(s1[0]!=s2[0]){
			int a=1+editDistance(s1.substr(1),s2,output);
			int b=1+editDistance(s1,s2.substr(1),output);
			int c=1+editDistance(s1.substr(1),s2.substr(1),output);

			ans= min(a,min(b,c));
		}
		else{
			int a=1+editDistance(s1.substr(1),s2,output);
			int b=1+editDistance(s1,s2.substr(1),output);
			int c=editDistance(s1.substr(1),s2.substr(1),output);

			ans= min(a,min(b,c));
		}
		output[m][n]=ans;
		return ans;
	}
}
int editDistance_MEM(string s1, string s2) {
	// Write your code here
	int m=s1.length();
    int n=s2.length();
	int **output=new int*[m+1];
	for(int i=0;i<=m;i++){
		output[i]=new int[n+1];
		for(int j=0;j<=n;j++){
			output[i][j]=-1;
		}
	}
	return editDistance(s1,s2,output);
}

//Recursive solution
int editDistance(string s1, string s2) {
  // Write your code here
  int m = s1.length();
  int n = s2.length();
  if (m == 0 or n == 0) {
    return max(m, n);
  }
  if (s1[0] != s2[0]) {
    int a = 1 + editDistance(s1.substr(1), s2);
    int b = 1 + editDistance(s1, s2.substr(1));
    int c = 1 + editDistance(s1.substr(1), s2.substr(1));

    return min(a, min(b, c));
  } 
  else {
    return editDistance(s1.substr(1), s2.substr(1));
  }
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance_DP(s1, s2);
}
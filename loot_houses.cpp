#include <iostream>
#include<climits>
#include<cmath>
using namespace std;

//DP solution
int maxMoneyLooted(int *arr, int n){
	//Write your code here
    int** output=new int*[n+1];
	for(int i=0;i<=n;i++){
		output[i]=new int[2];
	}
    for(int i=0;i<2;i++){
        output[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            if(j==0){
                int ans=0;
                int a=arr[n-i]+output[i-1][1];
                int b=output[i-1][0];
                ans=max(a,b);
                output[i][0]=ans;
            }
            else{
                int a=output[i-1][0];
                output[i][1]=a;
            }
        }
    }
    return output[n][0];
}

//Memoization solution
int maxMoneyLooted(int* arr ,int n, int k,int**output){
	if(n==0){
		return 0;
	}

	int ans=0;
	if(output[n][k]!=0){
		return output[n][k];
	}
	else{
		if(k==0){
			int a=arr[0]+maxMoneyLooted(arr+1,n-1,1,output);
			int b=maxMoneyLooted(arr+1,n-1,0,output);
			ans=max(a,b);
			output[n][k]=ans;
		}
		else{
			int a=maxMoneyLooted(arr+1,n-1,0,output);
			ans=a;
			output[n][k]=ans;
		}
	}
	return ans;
}
int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
	int** output=new int*[n+1];
	for(int i=0;i<=n;i++){
		output[i]=new int[2];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=2;j++){
			output[i][j]=0;
		}
	}
	return maxMoneyLooted(arr,n,0,output);
}

//recursive solution
int maxMoneyLooted(int* arr ,int n, int k){
	if(n==0){
		return 0;
	}
	int ans=0;
	if(k==0){
		int a=arr[0]+maxMoneyLooted(arr+1,n-1,1);
		int b=maxMoneyLooted(arr+1,n-1,0);
		ans=max(a,b);
	}
	else{
		int a=maxMoneyLooted(arr+1,n-1,0);
		ans=a;
	}
	return ans;
}
int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
	return maxMoneyLooted(arr,n,0);
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}
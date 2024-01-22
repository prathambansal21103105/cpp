#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

//DP solution
int minCostPath_DP(int **input, int m, int n){
    int**output=new int*[m];
    for(int i=0;i<m;i++){
        output[i]=new int[n];
    }
    output[m-1][n-1]=input[m-1][n-1];

    for(int j=n-2;j>=0;j--){
        output[m-1][j]=output[m-1][j+1]+input[m-1][j];
    }
    for(int i=m-2;i>=0;i--){
        output[i][n-1]=output[i+1][n-1]+input[i][n-1];
    }
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            output[i][j]=min(output[i+1][j+1],output[i+1][j]);
            output[i][j]=min(output[i][j+1],output[i][j])+input[i][j];
        }
    }
    return output[0][0];
}

//Memoization solution
int minCostPath_Mem(int** input,int visited[100][100],int m,int n, int row, int col){
  if (row == m - 1 and col == n - 1) {
    return input[m - 1][n - 1];
  }
  if (row < 0 or row >= m or col < 0 or col >= n) {
    return INT_MAX;
  }
  if(visited[row][col]!=0){
    return visited[row][col];
  }
  int a = minCostPath_Mem(input,visited, m, n, row + 1, col);
  int b = minCostPath_Mem(input,visited, m, n, row, col + 1);
  int c = minCostPath_Mem(input,visited, m, n, row + 1, col + 1);

  int ans = min(a, min(b, c))+input[row][col];

  visited[row][col]=ans;

  return ans;
}

//recursive solution
int helper(int**input,int visited[100][100],int m,int n,int row,int col){
	if(row<0 or row>=m or col<0 or col>=n){
		return INT_MAX;
	}
	if(row==m-1 and col==n-1){
		return input[m-1][n-1];
	}
	visited[row][col]=1;
	int a=INT_MAX;
	int b=INT_MAX;
	int c=INT_MAX;
	int min1=INT_MAX;

	if(row+1<=m-1 and visited[row+1][col]==0){
		a=input[row][col]+helper(input,visited,m,n,row+1,col);
	}
	if(col+1<=n-1 and visited[row][col+1] == 0) {
		b = input[row][col]+helper(input, visited, m, n, row, col+1);
	}
	if(row+1<=m-1 and col+1<=n-1 and visited[row+1][col+1]==0){
		c=input[row][col]+helper(input,visited,m,n,row+1,col+1);
	}

	min1=min(a,b);
	min1=min(c,min1);
	visited[row][col]=0;

	return min1;
}

int minCostPath(int **input, int m, int n){
	//Write your code here
	int row=0;
	int col=0;
	int visited[100][100]={0};
	// int ans=helper(input,visited,m,n,row,col);
    int ans=minCostPath_DP(input,m,n);
	return ans;
}

int main(){
    
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}
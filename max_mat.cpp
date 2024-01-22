#include <iostream>
#include<cmath>
using namespace std;

int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	//Write your code here
    int mat[n][m];
    for(int i=0;i<n;i++){
        if(arr[i][0]==1){
            mat[i][0]=0;
        }
        else{
            mat[i][0]=1;
        }
    }
    for(int i=0;i<m;i++){
        if(arr[0][i]==1){
            mat[0][i]=0;
        }
        else{
            mat[0][i]=1;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][j]==0){
                int a,b,c;
                a=mat[i-1][j-1];
                b=mat[i-1][j];
                c=mat[i][j-1];
                mat[i][j]=1+min(a,min(b,c));
            } 
            else{
                mat[i][j]=0;
            }
        }
    }
    int max1=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]>max1){
                max1=mat[i][j];
            }
        }
    }
    return max1;
}

int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}
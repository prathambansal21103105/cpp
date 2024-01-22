#include <iostream>
#include<climits>
#include<cmath>
using namespace std;

//DP solution
int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    int **output = new int *[n + 1];
    for (int i = 0; i <= n; i++) {
        output[i] = new int[maxWeight + 1];
    }
    for(int i=0;i<=maxWeight;i++){
        output[0][i]=0;
    }
    for(int j=0;j<=n;j++){
        output[j][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxWeight;j++){
            int ans=0;
            if(weight[n-i]<=j){
                int a=value[n-i]+output[i-1][j-weight[n-i]];
				int b=output[i-1][j];
				ans=max(a,b);
            }
            else{
                ans=output[i-1][j];
            }
            output[i][j]=ans;
        }
    }
    return output[n][maxWeight];
}

//Memoization solution
int knapsack_MEM(int *weight, int *value, int n, int maxWeight, int **output) {
  // Write your code here

  if (n == 0) {
    if (maxWeight >= 0) {
      return 0;
    } 
    else {
      return INT_MIN;
    }
  }
  else{
    if (output[n][maxWeight] != 0) {
      // cout<<"YES"<<endl;
      return output[n][maxWeight];
    } 
    else {
      int a=INT_MIN;
      if(weight[0]<=maxWeight){
        a = value[0] + knapsack_MEM(weight + 1, value + 1, n - 1,maxWeight - weight[0], output);
      }
      int b = knapsack_MEM(weight + 1, value + 1, n - 1, maxWeight, output);
      output[n][maxWeight] = max(a, b);
      // cout<<"HERE: "<<n<<" "<<maxWeight<<endl;
      return output[n][maxWeight];
    }
  }
}
int knapsack(int *weight, int *value, int n, int maxWeight) {
  // Write your code here
  int **output = new int *[n + 1];
  for (int i = 0; i <= n; i++) {
    output[i] = new int[maxWeight + 1];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= maxWeight; j++) {
      output[i][j] = 0;
    }
  }
  return knapsack_MEM(weight, value, n, maxWeight, output);
}


//recursive solution
int knapsack(int *weights, int *values, int n, int maxWeight){
	//write your code here
    if(n==0){
        if(maxWeight>=0){
            return 0;
        }
        else{
            return INT_MIN;
        }
    }
    else{
        int a=values[0]+ knapsack(weights+1,values+1,n-1,maxWeight-weights[0]);
        int b=knapsack(weights+1,values+1,n-1,maxWeight);
        return max(a,b);
    }
}

int main()
{
	int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}
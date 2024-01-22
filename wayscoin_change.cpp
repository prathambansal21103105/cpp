#include <iostream>
using namespace std;

//DP
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
 	//Write your code here
  if(value<denominations[0]){
	  return 0;
  }
  int matrix[value+1][numDenominations+1];
  for(int i=0;i<=numDenominations;i++){
    matrix[0][i]=0;
  }
  for(int i=0;i<=value;i++){
    matrix[i][0]=0;
  }
  for(int i=1;i<=value;i++){
    for(int j=1;j<=numDenominations;j++){
      if(i>=denominations[j-1]){
        matrix[i][j]=matrix[i][j-1];
        int ans=1;
        int rest=i-denominations[j-1];
        if(matrix[rest][j]>0){
          matrix[i][j]+=matrix[rest][j];
        }
        else if(rest==0){
          matrix[i][j]+=1;
        }

      }
      else{
        matrix[i][j]=matrix[i][j-1];
      }
    }
  }
  // for(int i=0;i<=value;i++){
  //   for(int j=0;j<=numDenominations;j++){
  //     cout<<matrix[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  return matrix[value][numDenominations];
}

//Memoization solution
// int helper(int denominations[],int numDenominations, int value, int** matrix, int index){
//   if(matrix[value][numDenominations]!=-1){
//     return matrix[value][numDenominations];
//   }
//   if (numDenominations == index) {
//     return 0;
//   }
//   int ans = 0;
//   if(denominations[index]<=value){
//     if(matrix[value-denominations[index]][index]!=-1){
//       ans+=matrix[value-denominations[index]][index];
//     }
//     else{
//       ans+=countWaysToMakeChange(denominations,numDenominations,value-denominations[index],index);
//     }
//   }
//   if(matrix[value][index+1]!=-1){
//     ans+=matrix[value][index+1];
//   }
//   else{
//     ans+=countWaysToMakeChange(denominations,numDenominations,value,index+1);
//   }
//   matrix[value][numDenominations]=ans;
//   return ans;
// }
// int countWaysToMakeChange(int denominations[], int numDenominations, int value){
// 	//Write your code here
//   if(denominations[0]>value){
//     return 0;
//   }
//   int** matrix=new int*[value+1];
//   for(int i=0;i<=value;i++){
//     matrix[i]=new int[numDenominations+1];
//     for(int j=0;j<=value;j++){
//       matrix[i][j]=-1;
//       if(i==0 or j==0){
//         matrix[i][j]=0;
//       }
//     }
//   }
//   int ans=helper(denominations,numDenominations,value,matrix,0);
//   return ans;
// }

// recursive solution
int countWaysToMakeChange(int denominations[], int numDenominations,int value, int index) {
  // Write your code here
  if (value == 0) {
    return 1;
  }
  if (value <= 0 or numDenominations == index) {
    return 0;
  }
  int ans = 0;
  if(denominations[index]<=value){
	  ans+=countWaysToMakeChange(denominations,numDenominations,value-denominations[index],index);
    ans+=countWaysToMakeChange(denominations,numDenominations,value,index+1);
  }
  else{
    return 0;
  }
  return ans;
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value) {
  // Write your code here
  return countWaysToMakeChange(denominations, numDenominations, value, 0);
}

int main()
{

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;
}

/*
#include<bits/stdc++.h>
int countWaysToMakeChange(int denominations[], int numDenominations,int value, int index, int* output) {
  // Write your code here
  if (value == 0) {
    return 1;
  }
  if (value <= 0 or numDenominations == index) {
    return 0;
  }
  if(output[value]!=0){
	  return output[value];
  }
  int ans = 0;
  if(denominations[index]<=value){
	  ans+=countWaysToMakeChange(denominations,numDenominations,value-denominations[index],index,output);
  }
  ans+=countWaysToMakeChange(denominations,numDenominations,value,index+1,output);
  output[value]=ans;
  return ans;
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value) {
  // Write your code here
  int*output=new int[value+1];
  for(int i=0;i<value+1;i++){
	  output[i]=0;
  }
  return countWaysToMakeChange(denominations, numDenominations, value, 0,output);
}
*/
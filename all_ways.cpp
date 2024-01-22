#include <iostream>
#include<cmath>
using namespace std;

//Memoization solution
int getAllWays1(int a, int b, vector<int>v, int index, int size, int*output) {
  // Write your code here
  if (a == 0 ) {
    return 1;
  }
  if (a < 0 or index==size) {
    return 0;
  }
  if(output[a]!=0){
    return output[a];
  }
  int ans = 0;
  int newa=a-v[index];
  int a1=0;
  int b1=0;
  if(a>=v[index]){
    a1=getAllWays1(newa,b,v,index+1,size,output);
  }
  b1=getAllWays1(a,b,v,index+1,size,output);
  ans+=a1;
  ans+=b1;
  output[a]=ans;
  return ans;
}
int getAllWays(int a, int b) {
	// Write your code here
    vector<int>v;
    for (int i = 1; i < pow(a, 1.0 / b); i++) {
        v.push_back(pow(i,b));
    }
    int n=v.size();
    int *output=new int[a+1];
    for(int i=0;i<=a;i++){
        output[i]=0;
    }
    return getAllWays1(a,b,v,0,n,output);
}

//recursive solution
int getAllWays1(int a, int b, vector<int>v, int index, int size) {
  // Write your code here
  if (a == 0 ) {
    return 1;
  }
  if (a < 0 or index==size) {
    return 0;
  }
  int ans = 0;
  int newa=a-v[index];
  int a1=0;
  int b1=0;
  if(a>=v[index]){
    a1=getAllWays1(newa,b,v,index+1,size);
  }
  b1=getAllWays1(a,b,v,index+1,size);
  ans+=a1;
  ans+=b1;
  return ans;
}
int getAllWays(int a, int b) {
	// Write your code here
    vector<int>v;
    for (int i = 1; i <=pow(a, 1.0 / b); i++) {
        v.push_back(pow(i,b));
    }
    int n=v.size();
    return getAllWays1(a,b,v,0,n);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}
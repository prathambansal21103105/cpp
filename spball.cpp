#include <iostream>
using namespace std;
#define int long long

const int m  =1e9+7;

signed main() {
	// your code goes here
    int x = 1e6+1;
	int input1[x];
	input1[0]=1;
	for(int i=1;i<1e6+1;i++){
	    input1[i]=(input1[i-1]*1LL*i)%m;
	}
	int t;
	cin>>t;
	while(t>0){
	    int n;
	    cin>>n;
	    int input[n];
	    for(int i=0;i<n;i++){
	        cin>>input[i];
	    }
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum=(sum+input1[input[i]])%(m);
	        sum=sum%(m);
	    }
	    cout<<sum<<endl;
	    t-=1;
	}
	return 0;
}
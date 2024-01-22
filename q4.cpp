#include <iostream>
using namespace std;
#define MAX 100

int main(){
	
	int arr[MAX];
	int n,i,j;
	int temp;
	cin>>n;
    
	for(i=0;i<n;i++){
		cin>>arr[i];
	}

	for(i=0;i<n;i++){		
		for(j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
    int flag=1;
    int ans;
    int maxn=arr[n-1];
	for(int k=n-1;k>=1;k--){
        if (arr[k]<maxn){
            ans=arr[k];
            flag=0;
            break;
        }
    }
    if (flag==1){
        cout<<-2147483648<<endl;
    }
    else{
        cout<<ans<<endl;
    }
	return 0;
}
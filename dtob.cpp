#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ar[18];
    if(n==0){
        cout<<0<<endl;
    }
    else if(n==1){
        cout<<1<<endl;
    }
    else{
        int i=0;
    while(true){
        int rem=n%2; 
        ar[i]=rem;
        i+=1; 
        n=n/2;     
        if(n==1){
            ar[i]=1;
            break;
        }
    }
    
    int ans;
    for(int j=i;j>=0;j--){
        cout<<ar[j];
    }
    }
    return 0;
}
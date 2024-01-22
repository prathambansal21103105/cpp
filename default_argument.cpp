#include<iostream>
using namespace std;

int sum(int a[],int size,int si=0){ // if we do not give value of si it would simply find the sum of the whole array
    int ans=0;
    for(int i=si;i<size;i++){
        ans+=a[i];
    }
    return ans;
}

int sum2(int a,int b,int c=0,int d=0){
    return a+b+c+d;
}

int main(){
    
    int a[20];
    for(int i=0;i<20;i++){
        cin>>a[i];
    }

    cout<<sum(a,20)<<endl;

    cout<<sum2(1,2)<<endl;

    return 0;
}
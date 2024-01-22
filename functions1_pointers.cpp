#include<iostream>
using namespace std;
int sum(int a[],int size){
    int ans=0;
    for(int i=0;i<size;i++){
        ans+=a[i];
    }
    cout<<sizeof(a)<<endl;
    return ans;
}
int main(){
    int a[10];
    cout<<sizeof(a)<<endl;
    cout<<sum(a+3,7)<<endl;
    return 0;
}
// when an array is passed in a function ,we actually are passing a pointer so if the function checks the value of the pointer the size would be 8
// we can even pass part of an array in a function
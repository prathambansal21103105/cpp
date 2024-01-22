#include<iostream>
using namespace std;
void sort012(int arr[],int n){
    int count0,count1,count2;
    count0=0;
    count1=0;
    count2=0;
    for(int i=0;i<n;i++){
        if (arr[i]==0){
            count0+=1;
        }
        else if (arr[i]==1){
            count1+=1;
        }
        else{
            count2+=1;
        }
    }
 
    for(int i=0;i<n;i++){
        if(i<count0){
            arr[i]=0;
     
        }
        else if(i>=count0 and i<count0+count1){
            arr[i]=1;
        }
        else{
            arr[i]=2;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int input[n];
        for(int i=0;i<n;i++){
            cin>>input[i];
        }
        sort012(input,n);
        for(int i=0;i<n;i++){
            cout<<input[i]<<" ";
        }
        cout<<endl;
        t-=1;
    }
    return 0;
}
#include<iostream>
#include<queue>
using namespace std;
void intersection(int arr1[], int arr2[], int n, int m){
    priority_queue<int>pq,pq1;
    if(n<m){
        for(int i=0;i<n;i++){
        pq.push(-arr1[i]);
    }
    for(int i=0;i<n;i++){
        arr1[i]=-pq.top();
        pq.pop();
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=count;j<m;j++){
            if(arr1[i]==arr2[j]){
                cout<<arr1[i]<<" ";
                int temp=arr2[j];
                arr2[j]=arr2[count];
                arr2[count]=temp;
                count+=1;
                break;
            }
        }        
    }
    }
    else{
        for(int i=0;i<m;i++){
        pq1.push(-arr2[i]);
    }
    for(int i=0;i<m;i++){
        arr2[i]=-pq1.top();
        pq1.pop();
    }
    int count=0;
        for(int i=0;i<m;i++){
        for(int j=count;j<n;j++){
            if(arr2[i]==arr1[j]){
                cout<<arr2[i]<<" ";
                int temp=arr1[j];
                arr1[j]=arr1[count];
                arr1[count]=temp;
                count+=1;
                break;
            }
        }        
    }
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int input1[n];
        for(int i=0;i<n;i++){
            cin>>input1[i];
        }
        int m;
        cin>>m;
        int input2[m];
        for(int i=0;i<m;i++){
            cin>>input2[i];
        }
        intersection(input1,input2,n,m);
        t-=1;
    }
    return 0;
}
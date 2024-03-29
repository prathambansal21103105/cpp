#include<iostream>
#include<queue>
using namespace std;
void k_sortedarray(int input[],int n,int k){
    priority_queue<int>pq;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }
    int j=0;
    for(int i=k;i<n;i++){
        input[j]=pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }
    while(!pq.empty()){
        input[j]=pq.top();
        pq.pop();
        j++;
    }
}
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    int k;
    cin>>k;
    k_sortedarray(input,n,k);
    for(int i=0;i<n;i++){
        cout<<input[i]<<" "; 
    }
    cout<<endl;
    return 0;
}

// nlogk = n
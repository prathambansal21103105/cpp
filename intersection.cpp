#include<iostream>
using namespace std;
void intersection(int input1[],int input2[],int size1,int size2){
    int max=input1[0];
    for(int i=0;i<size1;i++){
        if (input1[i]>max){
            max=input1[i];
        }
    }
    for(int i=0;i<size1;i++){
        for(int j=0;j<size2;j++){
            if (input1[i]==input2[j]){
                cout<<input1[i]<<" ";
                input2[j]=max+1;
                break;
            }
        }
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while (t>0){
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
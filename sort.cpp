#include<iostream>
using namespace std;
int main(){
    int size1;
    cin>>size1;
    int input1[size1];
    for(int i=0;i<size1;i++){
        cin>>input1[i];
    }
    for(int i=0;i<size1;i++){
        int max1=input1[i];
        for(int j=i+1;j<size1;j++){
            if (input1[j]>max1){
                max1=input1[j];
                int temp=input1[i];
                input1[i]=input1[j];
                input1[j]=temp;
            }
        }
    }
    for(int i=0;i<size1;i++){
        cout<<input1[i]<<endl;
    }
    
    return 0;
}
#include<iostream> //min
using namespace std;
void selection(int input[],int n){
    for(int i=0;i<n;i++){
        int min=input[i];
        for(int j=i;j<n;j++){
            if(input[j]<min){
                min=input[j];
                int temp=input[j];
                input[j]=input[i];
                input[i]=temp;
            } 
        }
    }
}
int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    selection(input,n);
    for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
}
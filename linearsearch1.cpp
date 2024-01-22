#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int input1[n];
    for(int i=0;i<n;i++){
        cin>>input1[i];
    }
    int x;
    cin>>x;
    for(int i=0;i<n;i++){
        if (input1[i]==x){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
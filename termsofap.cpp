#include<iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    int count=0;
    int i=1;
    while(count<x){
        if (((3*(i))+2)%4==0){
            i+=1;
        }
        else{
            cout<<(3*(i))+2<<" ";
            i+=1;
            count+=1;
        }
    }
    return 0;
}
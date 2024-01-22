#include<iostream>      //prime function
using namespace std;
bool isPrime(int num1){
    int j=0;
    for(int i=2;i<num1;i++){
        int calc=num1%i;
        if(calc==0){
            j=j+1;
            break;
        }
    }
    if(j==1 and num1>2){
        // cout<<"Non Prime"<<endl;
        return false;
    }
    else{
        // cout<<"Prime"<<endl;
        return true;
    }
}
int main(){
    int a;
    cout<<"Give a number except 1 --"<<endl;
    cin>>a;
    if(isPrime(a)==1 and a!=1){
        cout<<"Prime"<<endl;
    }
    else if(a==1){
        cout<<"Give another number :)"<<endl;
    }
    else{
        cout<<"Non-Prime"<<endl;
    }
    return 0;
}


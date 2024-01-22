#include<iostream>     //fibonacci function
using namespace std;
int fibonacci(int a){
    
    if(a==1){
        cout<<1<<endl;
        return 1;
    }
    else if (a==2){
        cout<<1<<endl;
        return 1;
    }
    else{
        cout<<fibonacci(a-2)+fibonacci(a-1);
        return 0;
    }
    

}

int main(){
    int a;
    cout<<"Give a number-"<<endl;
    cin>>a;
    cout<<fibonacci(a)<<endl;
    return 0;
}
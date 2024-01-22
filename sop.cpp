#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int c;
    cin>>c;
    int sum=0;
    int product=1;
    sum=(n*(n+1))/2;
    int i=1;
    while(i<=n){
        product*=i;
        i+=1;
    }
    if(c==1){
        cout<<sum<<endl;
    }
    else if(c==2){
        cout<<product<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}
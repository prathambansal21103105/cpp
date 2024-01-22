#include<iostream>
#include<math.h>
using namespace std;
int main(){

    int n;
    cin>>n;

    int sum=0;
    int originaln =n;
    
    while(n>0){
      int lastdigit=n%10;
      sum= sum + pow(lastdigit,3);
      n=n/10;
    }

    cout<<sum<<endl;
    if(sum==originaln){
        cout<<"Yes n is an Armstrong number"<<endl;
    }
    else{
        cout<<"No n is not an Armstrong number"<<endl;
    }




    return 0;
}
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=1;
    int sum=0;
    while (i<=n){
        if (i%2==0){
            sum+=i;
            i+=1;
        }
        else{
            i+=1;
            continue;
        }
    }
    cout<<sum<<endl;
    return 0;
}
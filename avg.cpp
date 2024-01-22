#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t>0){
        int n,k,v;
        cin>>n>>k>>v;
        int sum=0;
        int an[n];
        for(int i=0;i<n;i++){
            cin>>an[i];
            sum+=an[i];
        }
        int expression;
        expression=((v*(n+k))-sum);
        if (expression<=0 or expression%k!=0){
            cout<<-1<<endl;
        }
        else{
            cout<<expression/k<<endl;
        }
        t-=1;
    }
    return 0;
}
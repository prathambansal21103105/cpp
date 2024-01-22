#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int input[n];
        for(int i=0;i<n-1;i++){
            cin>>input[i];
        }
        int sum=0;
        int b=0;
        for(int i=0;i<n-1;i++){
            sum+=input[i];
            if(i==0){
                b=b+input[i]+input[i];
            }
            else{
                int prev=sum-input[i];
                int curr=sum;
                int next=sum+input[i+1];
                if(curr>b){
                    b=b+curr-b+input[i];
                }
                else{
                    b=b+input[i];
                }
            }
        }
        cout<<b<<endl;
        t-=1;
    }
    return 0;
} 
/*

t=0       t=3       t=6     t=8    t=13
a=1       a=2       a=g     a=3    a=3
b=1       b=1       b=2     b=2    b=3

2    3    4
3    8
6    13

2    3    4
5    7    13
10   12   19

t=0  t=5  t=7  t=10  t=12   t=13
1     2    3    g     g       4
1     1    1    2     3       

*/
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        long long int n,k;
        cin>>n>>k;
        char a[n];
        cin>>a;
        long long int si=0;
        long long int j=n-k;
        while(si<=j){
            if(a[si]=='1'){
                for(long long int i=si;i<si+k;i++){
                    if(a[i]=='0'){
                        a[i]='1';
                    }
                    else{
                        a[i]='0';
                    }
                }
                si+=1;
            }
            else{
                si+=1;
            }
        }
        cout<<a<<endl;
        t-=1;
    }
    return 0;
}
/*
1011
j=2
0111
0001
*/
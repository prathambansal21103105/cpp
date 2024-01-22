#include<iostream>
#include<cstring>
using namespace std;
void change(char a[],long long int k){
    if(strlen(a)==k){
        if(a[0]=='1'){
            for(long long int i=0;i<k;i++){
                    if(a[i]=='1'){
                        a[i]='0';
                    }
                    else{
                        a[i]='1';
                    }
                }
        }
        else{
            return;
        }
    }
    else{
        if(a[0]=='1'){
            for(long long int i=0;i<k;i++){
                if(a[i]=='0'){
                    a[i]='1';
                }
                else{
                    a[i]='0';
                }
            }
            change(a+1,k);
        }
        else{
            change(a+1,k);
        }
    }
}
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
        change(a,k);
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
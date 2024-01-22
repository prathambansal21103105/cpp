#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n,m;
        cin>>n>>m;
        char input[n*m];
        cin>>input;
        while(m-1>0){
            int i;
            int si=strlen(input);
            int ei=si+n;
            for(i=si;i<ei;i++){
                input[i]=input[i-n];
            }
            input[i]='\0';
            m-=1;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            if(input[i]=='1'){
                sum+=1;
            }
            else{
                sum+=0;
            }
        }
        sum=sum*m;
        int ans=0;
        int prefix=0;
        int suffix=sum;
        for(int i=0;i<strlen(input);i++){
            if(input[i]=='1'){
                prefix+=1;
            }
            else{
                prefix+=0;
            }
            suffix=sum-prefix;
            if(prefix==suffix){
                ans+=1;
            }
        }
        cout<<ans<<endl;
        t-=1;
    }
    return 0;
}